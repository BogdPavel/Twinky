#-------------------------------------------------
#
# Project created by QtCreator 2018-05-18T21:29:16
#
#-------------------------------------------------

QT += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyServer
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    myserver.cpp \
    mythreadsocket.cpp

HEADERS += \
    myserver.h \
    mythreadsocket.h
