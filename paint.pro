#-------------------------------------------------
#
# Project created by QtCreator 2015-09-24T19:55:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = paint
TEMPLATE = app


SOURCES += main.cpp\
        paint.cpp \
    paintscene.cpp \
    createnewstiker.cpp

HEADERS  += paint.h \
    paintscene.h \
    createnewstiker.h

FORMS    += paint.ui \
    createnewstiker.ui
