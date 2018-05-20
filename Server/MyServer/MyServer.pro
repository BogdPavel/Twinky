#-------------------------------------------------
#
# Project created by QtCreator 2018-05-18T21:29:16
#
#-------------------------------------------------

QT += core
QT += gui
QT += network
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyServer
TEMPLATE = app

LIBS += "C:\Program Files\MySQL\MySQL Server 5.5\bin"
        "C:\Program Files\MySQL\MySQL Server 5.5\lib"

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    myserver.cpp \
    mythreadsocket.cpp

HEADERS += \
    myserver.h \
    mythreadsocket.h
