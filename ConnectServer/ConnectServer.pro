#-------------------------------------------------
#
# Project created by MOSE Team
#
#-------------------------------------------------

QT          += core
QT          += network
QT          -= gui

TARGET      = ConnectServer
CONFIG      += console
CONFIG      -= app_bundle

TEMPLATE    = app

SOURCES += \
    connectserver.cpp \
    ../include/logger.cpp \
    ../include/tcpserver.cpp \
    mainserver.cpp \
    ../include/configuration.cpp \
    protocol.cpp \
    protocol/welcomemessage.cpp \
    protocol/serverlist.cpp

HEADERS += \
    connectserver.h \
    ../include/logger.h \
    ../include/tcpserver.h \
    mainserver.h \
    ../include/configuration.h \
    protocol.h \
    protocol/structs.h \
    protocol/welcomemessage.h \
    protocol/serverlist.h
