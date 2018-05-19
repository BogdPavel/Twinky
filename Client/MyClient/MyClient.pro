#-------------------------------------------------
#
# Project created by QtCreator 2018-05-18T21:16:50
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyClient
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
    myclient.cpp \
    signupwindow.cpp \
    startwindow.cpp

HEADERS += \
    myclient.h \
    signupwindow.h \
    startwindow.h

RESOURCES += \
    images.qrc

FORMS += \
    myclient.ui \
    signupwindow.ui \
    startwindow.ui
