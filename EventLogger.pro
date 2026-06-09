QT = core serialport network sql

CONFIG += c++17 cmdline
CONFIG -= app_bundle
TEMPLATE = app
VPATH += src include  ../include/
INCLUDEPATH += $${VPATH}

# Define bin directory (Cross-Platform)
win32:BIN_DIR = $${PWD}\\bin
unix:BIN_DIR = $${PWD}/bin

# Ensure bin directory exists before building
win32:QMAKE_MKDIR = mkdir
unix:QMAKE_MKDIR = mkdir -p
system($$QMAKE_MKDIR $${BIN_DIR})

DESTDIR = $${BIN_DIR}

# Define install path
target.path = $${BIN_DIR}

SOURCES += main.cpp \
           EventLoggerKMS.cpp \
           nmsDBQuerys.cpp \
           EventLoggerGPS.cpp \
           nmsUDPServer.cpp \
           kavachpkthandler.cpp \
           KAVACH_PARSEPACKET.cpp \
           nmsDB.cpp \
           nmsMainWindow.cpp \
           crc32.c

HEADERS += nmsDBQuerys.h                    nmsUDPServer.h           \
           EventLoggerGPS.h                                      \
           EventLoggerKMS.h \
           kavachpkthandler.h               KAVACH_PARSEPACKET.h   \
           nmsDefines.h                     nmsEnum.h              \
           nmsQtInc.h                       nmsStructs.h           \
           nmsDB.h                                                \
           nmsMainWindow.h                  crc32.h