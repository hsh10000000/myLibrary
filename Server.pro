#-------------------------------------------------
#
# Project created by QtCreator 2016-11-12T20:12:45
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Server
TEMPLATE = app


SOURCES += main.cpp\
        server.cpp

HEADERS  += server.h

FORMS    += server.ui

RESOURCES += \
    pics.qrc

DISTFILES += \
    config.ini
