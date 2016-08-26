#-------------------------------------------------
#
# Project created by QtCreator 2016-08-09T22:14:18
#
#-------------------------------------------------

QT       += core gui uitools

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RubiksCube
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    rubixAlgorithms.cpp \
    rubixMoves.cpp \
    rubiks.cpp \
    dialog.cpp \
    cubeinput.cpp

HEADERS  += mainwindow.h \
    rubixAlgorithms.hpp \
    rubixMoves.hpp \
    rubiks.h \
    dialog.h \
    cubeinput.h

FORMS    += mainwindow.ui \
    dialog.ui \
    cubeinput.ui
