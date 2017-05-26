#-------------------------------------------------
#
# Project created by QtCreator 2017-05-14T17:34:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = symulation
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp \
        dialog.cpp \
        model/Area.cpp \
        model/Matrix.cpp \
        model/Point.cpp \
        model/Hysteresis.cpp \
        model/animals/Animal.cpp \
        model/animals/Lion.cpp \
        model/animals/Elephant.cpp \
    model/animals/Bear.cpp \
    model/animals/Boar.cpp \
    model/animals/Hippo.cpp \
    model/animals/Wolf.cpp \
    controller/AreaController.cpp


HEADERS  += dialog.h \
        model/Area.h \
        model/Point.h \
        model/Matrix.h \
        model/Hysteresis.h \
        model/animals/Animal.h \
        model/animals/Lion.h \
        model/animals/Elephant.h \
    model/animals/Bear.h \
    model/animals/Boar.h \
    model/animals/Hippo.h \
    model/animals/Wolf.h \
    controller/AreaController.h

FORMS    += dialog.ui
