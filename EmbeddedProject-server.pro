#-------------------------------------------------
#
# Project created by QtCreator 2015-06-16T14:36:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EmbeddedProject-server
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcp_server.cpp \
    filemanager.cpp \
    accesscodeslist.cpp \
    clientthread.cpp

HEADERS  += mainwindow.h \
    tcp_server.h \
    filemanager.h \
    accesscodeslist.h \
    clientthread.h

FORMS    += mainwindow.ui
