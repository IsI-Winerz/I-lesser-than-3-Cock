#-------------------------------------------------
#
# Project created by QtCreator 2015-02-20T11:17:25
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = Interface
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

LIBS += -L ../lib \
        -lpthread \
        -lX11 \
        -lImageIndexing

PRE_TARGETDEPS += ../lib/*.a

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui \
    admin.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ImageIndexing/release/ -lImageIndexing
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ImageIndexing/debug/ -lImageIndexing
else:unix: LIBS += -L$$OUT_PWD/../ImageIndexing/ -lImageIndexing

INCLUDEPATH += $$PWD/../ImageIndexing
DEPENDPATH += $$PWD/../ImageIndexing

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ImageIndexing/release/libImageIndexing.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ImageIndexing/debug/libImageIndexing.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ImageIndexing/release/ImageIndexing.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ImageIndexing/debug/ImageIndexing.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../ImageIndexing/libImageIndexing.a
