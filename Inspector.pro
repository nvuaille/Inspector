#-------------------------------------------------
#
# Project created by QtCreator 2014-11-17T11:31:48
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Inspector
TEMPLATE = app


SOURCES += main.cpp\
        inspectorpanel.cpp \
    basicelement.cpp \
    commoninterface.cpp \
    intervalinspectorview.cpp

HEADERS  += inspectorpanel.h \
    basicelement.h \
    commoninterface.h \
    intervalinspectorview.h

FORMS    += inspectorpanel.ui
