#-------------------------------------------------
#
# Project created by QtCreator 2015-03-27T16:13:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += network
QT +=opengl

TARGET = mainwindow
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    waitingroom.cpp \
    network.cpp \
    boardwindow.cpp\
    chess.cpp\
    game.cpp\
    party.cpp\
    widget.cpp

HEADERS  += mainwindow.h \
    waitingroom.h \
    network.h \
    boardwindow.h\
    chess.h\
    game.h\
    global.h\
    party.h\
    widget.h

FORMS    += mainwindow.ui\
    waitingroom.ui
RESOURCES += \
    image.qrc

DISTFILES += \
    image/11159.jpg
