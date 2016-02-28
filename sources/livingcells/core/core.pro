#-------------------------------------------------
#
# Project created by QtCreator 2016-02-29T00:40:39
#
#-------------------------------------------------

QT       -= core gui

TARGET = core
TEMPLATE = lib
CONFIG += staticlib

SOURCES += core.cpp

HEADERS += core.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
