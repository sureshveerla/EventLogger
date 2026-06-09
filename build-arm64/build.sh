#!/bin/bash
set -e

CXX=aarch64-linux-gnu-g++
CC=aarch64-linux-gnu-gcc
MOC=/usr/lib/qt6/libexec/moc
QT_INC=/usr/include/x86_64-linux-gnu/qt6
QT_LIB=/usr/lib/aarch64-linux-gnu
SRC=../src
INC=../include
DESTDIR=../bin

mkdir -p $DESTDIR

CXXFLAGS="-std=c++17 -O2 -fPIC \
  -I$QT_INC \
  -I$QT_INC/QtCore \
  -I$QT_INC/QtNetwork \
  -I$QT_INC/QtSql \
  -I$QT_INC/QtSerialPort \
  -I$SRC -I$INC -I.."

CFLAGS="-std=c11 -O2 -fPIC -I$INC -I$SRC"

echo "=== Running MOC ==="
$MOC $INC/DataloggerGPS.h -o moc_DataloggerGPS.cpp 2>/dev/null || true
$MOC $INC/EventLoggerGPS.h -o moc_EventLoggerGPS.cpp 2>/dev/null || \
$MOC $INC/EventLogger.h -o moc_EventLoggerGPS.cpp 2>/dev/null || true
$MOC $INC/EventLoggerKMS.h -o moc_EventLoggerKMS.cpp 2>/dev/null || true

for h in nmsDBQuerys nmsUDPServer kavachpkthandler KAVACH_PARSEPACKET nmsDB nmsMainWindow; do
  echo "moc $h.h"
  $MOC $INC/$h.h -o moc_$h.cpp 2>/dev/null || \
  $MOC $SRC/$h.h -o moc_$h.cpp 2>/dev/null || true
done

echo "=== Compiling C Sources ==="
echo "Compiling crc32.c"
$CC $CFLAGS -c $SRC/crc32.c -o crc32.o

echo "=== Compiling C++ Sources ==="
SOURCES="main nmsDBQuerys nmsUDPServer kavachpkthandler KAVACH_PARSEPACKET nmsCRC32 nmsDB nmsMainWindow EventLoggerGPS EventLoggerKMS"
MOC_SOURCES="nmsDBQuerys nmsUDPServer kavachpkthandler KAVACH_PARSEPACKET nmsDB nmsMainWindow EventLoggerGPS EventLoggerKMS"

for src in $SOURCES; do
  echo "Compiling $src.cpp"
  $CXX $CXXFLAGS -c $SRC/$src.cpp -o $src.o
done

for src in $MOC_SOURCES; do
  if [ -f moc_$src.cpp ]; then
    echo "Compiling moc_$src.cpp"
    $CXX $CXXFLAGS -c moc_$src.cpp -o moc_$src.o
  fi
done

echo "=== Linking ==="
OBJS="crc32.o"
for src in $SOURCES; do OBJS="$OBJS $src.o"; done
for src in $MOC_SOURCES; do
  [ -f moc_$src.o ] && OBJS="$OBJS moc_$src.o"
done

SERIALPORT_LIB=""
if [ -f "$QT_LIB/libQt6SerialPort.so" ]; then
  SERIALPORT_LIB="$QT_LIB/libQt6SerialPort.so"
  echo "Found SerialPort library"
fi

$CXX \
  $OBJS \
  $QT_LIB/libQt6Core.so \
  $QT_LIB/libQt6Network.so \
  $QT_LIB/libQt6Sql.so \
  $SERIALPORT_LIB \
  -lpthread \
  -Wl,-rpath-link,$QT_LIB \
  -o $DESTDIR/EventLogger

echo ""
echo "=== Build Result ==="
file $DESTDIR/EventLogger
