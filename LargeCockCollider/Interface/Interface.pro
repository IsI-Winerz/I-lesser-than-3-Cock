#-------------------------------------------------
#
# Project created by QtCreator 2015-02-20T11:17:25
#
#-------------------------------------------------

QT       += core gui

TARGET = Interface
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\

LIBS += -lpthread \
        -lX11

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ImageIndexing/release/ -lImageIndexing
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ImageIndexing/debug/ -lImageIndexing
else:symbian: LIBS += -lImageIndexing
else:unix: LIBS += -L$$OUT_PWD/../ImageIndexing/ -lImageIndexing

INCLUDEPATH += $$PWD/../ImageIndexing
DEPENDPATH += $$PWD/../ImageIndexing
