#-------------------------------------------------
#
# Project created by QtCreator 2015-02-20T11:17:25
#
#-------------------------------------------------

QT       += core gui widgets

QMAKE_CXXFLAGS += -fopenmp
QMAKE_LFLAGS   +=  -fopenmp

TARGET = Interface
TEMPLATE = app

INCLUDEPATH += ../ImageIndexing \
               ../
LIBS +=  \
    -lpthread \
    -lX11 \
    ../ImageIndexing/libImageIndexing.a

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui \
    admin.ui
