#-------------------------------------------------
#
# Project created by QtCreator 2015-01-20T10:28:17
#
#-------------------------------------------------

QT       += core
QT       += network
QT       -= gui

TARGET = FMServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    cserver.cpp \
    cclient.cpp \
    ctask.cpp

HEADERS += \
    cserver.h \
    cclient.h \
    ctask.h
