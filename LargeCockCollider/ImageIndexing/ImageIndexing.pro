#-------------------------------------------------
#
# Project created by QtCreator 2015-02-20T11:18:28
#
#-------------------------------------------------

QT       -= gui

TARGET = ImageIndexing
TEMPLATE = lib

DEFINES += IMAGEINDEXING_LIBRARY

SOURCES += imageindexing.cpp

HEADERS += imageindexing.h\
        ImageIndexing_global.h \
        CImg.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xEE776410
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = ImageIndexing.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
