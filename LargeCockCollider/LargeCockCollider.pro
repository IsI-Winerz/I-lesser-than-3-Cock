TEMPLATE = subdirs

SUBDIRS += \
    Interface \
    ImageIndexing

LIBS += -lpthread \
        -lX11

