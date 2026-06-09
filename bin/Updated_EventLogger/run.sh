#!/bin/sh
echo "======================================"
echo " Starting EventLogger Environment"
echo "======================================"

# -------------------------------
# 1. Start / Create Postgres
# -------------------------------
echo "Checking Postgres container..."
if [ "$(docker ps -aq -f name=postgres-db)" ]; then
    echo "Container exists. Starting..."
    docker start postgres-db >/dev/null
else
    echo "Container not found. Creating..."
    docker run -d \
        --name postgres-db \
        -e POSTGRES_DB=NMSDB \
        -e POSTGRES_USER=admin \
        -e POSTGRES_PASSWORD=admin123 \
        -p 5432:5432 \
        -v postgres_data:/var/lib/postgresql/data \
        postgres:17
fi

# -------------------------------
# 2. Wait for DB Ready
# -------------------------------
echo "Waiting for DB to be ready..."
until docker exec postgres-db pg_isready -U admin >/dev/null 2>&1; do
    sleep 1
done
echo "DB Ready!"

# -------------------------------
# 3. Pre-configure GSM UART (CRITICAL for Toradex)
#    stty must run on HOST before passing to Docker.
#    Sets: 115200 baud, 8N1, no flow control, DTR on.
# -------------------------------
GSM_FLAG=""
if [ -e /dev/ttyS2 ]; then
    echo "GSM detected on /dev/ttyS2"

    # Kill any process already using it
    fuser -k /dev/ttyS2 2>/dev/null || true
    sleep 1

    # Configure UART on host — this persists into Docker
    stty -F /dev/ttyS2 115200 cs8 -cstopb -parenb \
         -crtscts -ixon -ixoff \
         clocal cread \
         -echo -echoe -echok \
         raw

    # Assert DTR on host level
    # (some Toradex BSPs need this before Docker starts)
    python3 -c "
import serial, time
try:
    s = serial.Serial('/dev/ttyS2', 115200, timeout=1)
    s.dtr = True
    s.rts = True
    time.sleep(0.3)
    s.close()
    print('  DTR/RTS asserted on /dev/ttyS2')
except Exception as e:
    print('  DTR pre-assert skipped:', e)
" 2>/dev/null || true

    chmod 666 /dev/ttyS2

    GSM_FLAG="--device /dev/ttyS2:/dev/ttyS2"
    echo "GSM UART configured ✅"
else
    echo "⚠️  GSM device /dev/ttyS2 not found"
fi

# -------------------------------
# 4. Detect GPS Device
# -------------------------------
GPS_FLAG=""
if [ -e /dev/ttyS3 ]; then
    echo "GPS detected on /dev/ttyS0"
    fuser -k /dev/ttyS0 2>/dev/null || true
    sleep 1
    GPS_FLAG="--device /dev/ttyS0:/dev/ttyS0 --privileged"
elif [ -e /dev/ttyACM0 ]; then
    echo "GPS detected on USB (/dev/ttyACM0)"
    fuser -k /dev/ttyACM0 2>/dev/null || true
    sleep 1
    GPS_FLAG="--device /dev/ttyACM0:/dev/ttyACM0"
else
    echo "⚠️  No GPS device found - running without GPS"
fi

# -------------------------------
# 5. Clean old datalogger containers
# -------------------------------
echo "Cleaning old datalogger containers..."
docker stop $(docker ps -q --filter ancestor=datalogger-img) 2>/dev/null || true
docker rm $(docker ps -aq --filter ancestor=datalogger-img) 2>/dev/null || true

# -------------------------------
# 6. Run EventLogger
# -------------------------------
echo "Starting EventLogger..."
docker run --rm \
  -v /home/torizon:/home/torizon \
  --network host \
  -e TZ=Asia/Kolkata \
  $GPS_FLAG \
  $GSM_FLAG \
  --privileged \
  datalogger-img \
  sh -c 'LD_LIBRARY_PATH=/home/torizon/04052026 /home/torizon/04052026/EventLogger'

echo "======================================"
echo " EventLogger stopped"
echo "======================================"
