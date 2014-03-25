#CONFIG += static
#OBJECTS_DIR = .obj

INCLUDEPATH += $$PWD
LIBS += -ltiled

HEADERS += $$PWD/compression.h \
    $$PWD/gidmapper.h \
    $$PWD/imagelayer.h \
    $$PWD/isometricrenderer.h \
    $$PWD/layer.h \
    $$PWD/map.h \
    $$PWD/mapobject.h \
    $$PWD/mapreader.h \
    $$PWD/mapreaderinterface.h \
    $$PWD/maprenderer.h \
    $$PWD/mapwriter.h \
    $$PWD/mapwriterinterface.h \
    $$PWD/object.h \
    $$PWD/objectgroup.h \
    $$PWD/orthogonalrenderer.h \
    $$PWD/properties.h \
    $$PWD/staggeredrenderer.h \
    $$PWD/terrain.h \
    $$PWD/tile.h \
    $$PWD/tiled.h \
    $$PWD/tiled_global.h \
    $$PWD/tilelayer.h \
    $$PWD/tileset.h \
    $$PWD/logginginterface.h
