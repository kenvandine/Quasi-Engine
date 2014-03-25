TEMPLATE = subdirs

SUBDIRS += libtiled src

contains(BUILD_EXAMPLES, 1) {
    SUBDIRS += examples demos
}
