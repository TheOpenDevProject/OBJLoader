QT += core
QT -= gui

CONFIG += c++11

TARGET = ModelLoader
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    regexmodelloader.cpp

HEADERS += \
    regexmodelloader.h \
    modelvertex.h
