#-------------------------------------------------
#
# Project created by QtCreator 2015-11-30T16:31:52
#
#-------------------------------------------------

QT       += core gui
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TiledJsonParser
TEMPLATE = app
CONFIG+=C++11



SOURCES += main.cpp\
        widget.cpp \
    tiledjsonmapparsor.cpp \
    tiledtileset.cpp \
    tiledlayergroupitem.cpp \
    mycharacter.cpp \
    gamescene.cpp \
    gamehud.cpp \
    sonarpowar.cpp

HEADERS  += widget.h \
    tiledjsonmapparsor.h \
    tiledtileset.h \
    tiledlayergroupitem.h \
    mycharacter.h \
    gamescene.h \
    gamehud.h \
    sonarpowar.h

RESOURCES += \
    assets.qrc
