#-------------------------------------------------
#
# Project created by QtCreator 2016-02-21T10:43:07
#
#-------------------------------------------------

QT       += core gui\
        network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OSBLCartes
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    config.cpp \
    csmap.cpp \
    csmapgetter.cpp \
    config.cpp

HEADERS  += config.hpp \
    csmap.hpp \
    csmapgetter.hpp \
    uploader.hpp \
    mainwindow.hpp

FORMS    += mainwindow.ui

DISTFILES +=
