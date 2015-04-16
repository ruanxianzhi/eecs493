#-------------------------------------------------
#
# Project created by QtCreator 2015-03-27T16:13:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += network
QT += opengl
QT += multimedia

TARGET = mainwindow
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    waitingroom.cpp \
    boardwindow.cpp\
    chess.cpp\
    network.cpp \
    game.cpp\
    party.cpp\
    widget.cpp \
    set.cpp \
    rules.cpp \
    quit.cpp \
    endwindow.cpp

HEADERS  += mainwindow.h \
    waitingroom.h \
    network.h \
    boardwindow.h\
    chess.h\
    game.h\
    global.h\
    party.h\
    widget.h \
    set.h \
    rules.h \
    quit.h \
    endwindow.h

FORMS    += mainwindow.ui\
    waitingroom.ui \
    set.ui \
    rules.ui \
    quit.ui \
    endwindow.ui

RESOURCES += \
    image.qrc
