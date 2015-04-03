#-------------------------------------------------
#
# Project created by QtCreator 2015-03-31T21:58:22
#
#-------------------------------------------------

QT       += core gui
QT       += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = flightChess
TEMPLATE = app


SOURCES += main.cpp\
        boardwindow.cpp\
        widget.cpp \
        chess.cpp \
        party.cpp \
        game.cpp

HEADERS  += boardwindow.h\
        widget.h \
        chess.h \
        global.h \
        party.h \
        game.h
