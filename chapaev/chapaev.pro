#-------------------------------------------------
#
# Project created by QtCreator 2021-03-12T17:08:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chapaev
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        checker.cpp \
    checkerviewstyle.cpp \
        gameposition.cpp \
    gameview.cpp \
        main.cpp \
        mainwindow.cpp \
    movingchecker.cpp \
    physx.cpp \
    qchecker.cpp \
    qcheckerholder.cpp \
        startgamedata.cpp \
    game.cpp

HEADERS += \
    BattleSide.h \
        checker.h \
    checkerviewstyle.h \
        gameposition.h \
    gameview.h \
        mainwindow.h \
    movingchecker.h \
    physx.h \
    qchecker.h \
    qcheckerholder.h \
        startgamedata.h \
    game.h

FORMS += \
        mainwindow.ui
