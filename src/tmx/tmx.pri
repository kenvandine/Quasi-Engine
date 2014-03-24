TEMPLATE = subdirs

INCLUDEPATH += $$PWD

include($$PWD/libtiled/libtiled.pri)

SUBDIRS += tmx/libtiled

LIBS += -L$$PWD -ltiled

HEADERS += \
    $$PWD/tmximagelayer.h \
    $$PWD/tmxlayer.h \
    $$PWD/tmxmap.h \
    $$PWD/tmxmapobject.h \
    $$PWD/tmxobject.h \
    $$PWD/tmxobjectlayer.h \
    $$PWD/tmxtilelayer.h
