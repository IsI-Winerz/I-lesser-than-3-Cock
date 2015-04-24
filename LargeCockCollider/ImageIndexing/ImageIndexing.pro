#-------------------------------------------------
#
# Project created by QtCreator 2015-02-20T11:18:28
#
#-------------------------------------------------

QT       -= gui

TARGET = ImageIndexing
TEMPLATE = lib

CONFIG += staticlib

DEFINES += IMAGEINDEXING_LIBRARY

SOURCES += imageindexing.cpp \
    chickenrecognizer.cpp \
    orientationhist.cpp

HEADERS += imageindexing.h\
        ImageIndexing_global.h \
    CImg.h \
    chickenrecognizer.h \
    orientationhist.h
