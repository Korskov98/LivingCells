#-------------------------------------------------
#
# Project created by QtCreator 2016-02-29T00:40:39
#
#-------------------------------------------------

QT       -= core gui

TARGET = core
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    cell.cpp \
    field.cpp \
    api.cpp

HEADERS += \
    cell.h \
    field.h \
    api.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
