#-------------------------------------------------
#
# Project created by QtCreator 2018-03-16T15:35:43
#
#-------------------------------------------------

QT              += core gui widgets
CONFIG          += c++11

CONFIG(debug, debug|release){
    TARGET      = Exampled
}else{
    TARGET      = Example
}

TEMPLATE        = app

DESTDIR         = $$PWD/../bin/

SOURCES         += \
                main.cpp

include($$PWD/../LibRibbonUI.pri)

RESOURCES += \
    icon.qrc
