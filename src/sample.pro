#-------------------------------------------------
#
# Project created by QtCreator 2015-04-16T11:56:17
#
#-------------------------------------------------

QT += core
QT += network
QT += serialport
CONFIG += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rs232sample
TEMPLATE = app


SOURCES += main.cpp\
    rs232commmodule.cpp \
    test_rs232.cpp

HEADERS  += rs232commmodule.h \
    test_rs232.h

