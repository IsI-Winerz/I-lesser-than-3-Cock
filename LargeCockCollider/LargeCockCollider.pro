TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS += \
    ImageIndexing \
    Interface


LIBS += -lpthread \
        -lX11

