#!/bin/bash
set -e

# ============================================================
# ARM64 Cross Compilation Configuration
# ============================================================

CXX=aarch64-linux-gnu-g++
CC=aarch64-linux-gnu-gcc

# MOC runs on the x86_64 host machine
MOC=/usr/lib/qt6/libexec/moc

# Qt headers on host
QT_INC=/usr/include/x86_64-linux-gnu/qt6

# ARM64 Qt libraries
QT_LIB=/usr/lib/aarch64-linux-gnu

SRC=../src
INC=../include
DESTDIR=../bin

mkdir -p "$DESTDIR"

# ============================================================
# Compiler Flags
# ============================================================

CXXFLAGS="-std=c++17 -O2 -fPIC \
  -I$QT_INC \
  -I$QT_INC/QtCore \
  -I$QT_INC/QtNetwork \
  -I$QT_INC/QtSql \
  -I$QT_INC/QtSerialPort \
  -I$SRC \
  -I$INC \
  -I.."

CFLAGS="-std=c11 -O2 -fPIC \
  -I$INC \
  -I$SRC"

# ============================================================
# Run Qt MOC
# ============================================================

echo ""
echo "=========================================="
echo "              Running MOC"
echo "=========================================="

# ------------------------------------------------------------
# Function to generate MOC from a header
# ------------------------------------------------------------

generate_moc()
{
    HEADER_NAME="$1"

    echo "Generating MOC: $HEADER_NAME.h"

    if [ -f "$INC/$HEADER_NAME.h" ]; then

        "$MOC" "$INC/$HEADER_NAME.h" -o "moc_$HEADER_NAME.cpp"

    elif [ -f "$SRC/$HEADER_NAME.h" ]; then

        "$MOC" "$SRC/$HEADER_NAME.h" -o "moc_$HEADER_NAME.cpp"

    else

        echo "ERROR: Header not found: $HEADER_NAME.h"
        exit 1

    fi

    if [ ! -s "moc_$HEADER_NAME.cpp" ]; then
        echo "ERROR: MOC generation failed: moc_$HEADER_NAME.cpp"
        exit 1
    fi

    echo "OK: moc_$HEADER_NAME.cpp"
}

# ============================================================
# MOC Headers
# ============================================================

generate_moc "EventLoggerGPS"
generate_moc "EventLoggerKMS"
generate_moc "EventLoggerGPIO"

generate_moc "nmsDBQuerys"
generate_moc "nmsUDPServer"
generate_moc "kavachpkthandler"
generate_moc "KAVACH_PARSEPACKET"
generate_moc "nmsDB"
generate_moc "nmsMainWindow"

echo ""
echo "MOC generation completed successfully."

# ============================================================
# Compile C Sources
# ============================================================

echo ""
echo "=========================================="
echo "          Compiling C Sources"
echo "=========================================="

echo "Compiling crc32.c"

"$CC" $CFLAGS \
    -c "$SRC/crc32.c" \
    -o crc32.o

# ============================================================
# Compile C++ Sources
# ============================================================

echo ""
echo "=========================================="
echo "          Compiling C++ Sources"
echo "=========================================="

SOURCES="\
main \
nmsDBQuerys \
nmsUDPServer \
kavachpkthandler \
KAVACH_PARSEPACKET \
nmsCRC32 \
nmsDB \
nmsMainWindow \
EventLoggerGPS \
EventLoggerKMS \
EventLoggerGPIO"

MOC_SOURCES="\
nmsDBQuerys \
nmsUDPServer \
kavachpkthandler \
KAVACH_PARSEPACKET \
nmsDB \
nmsMainWindow \
EventLoggerGPS \
EventLoggerKMS \
EventLoggerGPIO"

# ------------------------------------------------------------
# Compile application source files
# ------------------------------------------------------------

for src in $SOURCES; do

    echo "Compiling $src.cpp"

    if [ ! -f "$SRC/$src.cpp" ]; then
        echo "ERROR: Source file not found: $SRC/$src.cpp"
        exit 1
    fi

    "$CXX" $CXXFLAGS \
        -c "$SRC/$src.cpp" \
        -o "$src.o"

done

# ============================================================
# Compile MOC Sources
# ============================================================

echo ""
echo "=========================================="
echo "          Compiling MOC Sources"
echo "=========================================="

for src in $MOC_SOURCES; do

    echo "Compiling moc_$src.cpp"

    if [ ! -f "moc_$src.cpp" ]; then
        echo "ERROR: Missing MOC source: moc_$src.cpp"
        exit 1
    fi

    "$CXX" $CXXFLAGS \
        -c "moc_$src.cpp" \
        -o "moc_$src.o"

    if [ ! -f "moc_$src.o" ]; then
        echo "ERROR: Failed to create moc_$src.o"
        exit 1
    fi

done

# ============================================================
# Linking
# ============================================================

echo ""
echo "=========================================="
echo "                Linking"
echo "=========================================="

OBJS="crc32.o"

# ------------------------------------------------------------
# Add application object files
# ------------------------------------------------------------

for src in $SOURCES; do

    if [ ! -f "$src.o" ]; then
        echo "ERROR: Missing object file: $src.o"
        exit 1
    fi

    OBJS="$OBJS $src.o"

done

# ------------------------------------------------------------
# Add MOC object files
# ------------------------------------------------------------

for src in $MOC_SOURCES; do

    if [ ! -f "moc_$src.o" ]; then
        echo "ERROR: Missing MOC object: moc_$src.o"
        exit 1
    fi

    OBJS="$OBJS moc_$src.o"

done

# ============================================================
# Qt SerialPort Library
# ============================================================

SERIALPORT_LIB=""

if [ -f "$QT_LIB/libQt6SerialPort.so" ]; then

    SERIALPORT_LIB="$QT_LIB/libQt6SerialPort.so"

    echo "Found SerialPort library"

else

    echo "WARNING: Qt6SerialPort library not found"

fi

# ============================================================
# Display Objects Being Linked
# ============================================================

echo ""
echo "========== OBJECTS BEING LINKED =========="

for obj in $OBJS; do
    echo "$obj"
done

echo "=========================================="

# ============================================================
# Final ARM64 Link
# ============================================================

"$CXX" \
    $OBJS \
    "$QT_LIB/libQt6Core.so" \
    "$QT_LIB/libQt6Network.so" \
    "$QT_LIB/libQt6Sql.so" \
    $SERIALPORT_LIB \
    -lgpiod \
    -lpthread \
    -Wl,-rpath-link,"$QT_LIB" \
    -o "$DESTDIR/EventLogger"

# ============================================================
# Build Result
# ============================================================

echo ""
echo "=========================================="
echo "              Build Result"
echo "=========================================="

file "$DESTDIR/EventLogger"

echo ""
echo "ARM64 EventLogger build completed successfully."
echo "Output: $DESTDIR/EventLogger"
echo ""
