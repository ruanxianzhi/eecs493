#-------------------------------------------------
#
# Project created by QtCreator 2015-03-27T16:13:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mainwindow
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    waitingroom.cpp

HEADERS  += mainwindow.h \
    waitingroom.h
FORMS    += mainwindow.ui\
    waitingroom.ui
RESOURCES += \
    image.qrc

DISTFILES += \
    image/11159.jpg
