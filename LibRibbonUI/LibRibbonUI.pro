#-------------------------------------------------
#
# Project created by QtCreator 2018-03-16T15:35:43
#
#-------------------------------------------------

QT              += core gui widgets
CONFIG          += c++11

DEFINES         += LIBRIBBONUI_LIBRARY #定义此宏将构建library

CONFIG(debug, debug|release){
    TARGET      = LibRibbonUId
}else{
    TARGET      = LibRibbonUI
}

TEMPLATE        = lib

DESTDIR         = $$PWD/../bin

SOURCES         += \
                QtRibbonWindow.cpp \
    QtRibbonWindowBar.cpp \
    QtRibbonButtonGroup.cpp \
    QtRibbonQuickAccessBar.cpp \
    QtRibbonToolButton.cpp \
    QtRibbonSeparatorWidget.cpp \
    QtRibbonMenuButton.cpp

HEADERS         += \
                QtRibbonWindow.h \
                LibRibbonUIGlobal.h \
    QtRibbonWindowBar.h \
    QtRibbonButtonGroup.h \
    QtRibbonQuickAccessBar.h \
    QtRibbonToolButton.h \
    QtRibbonSeparatorWidget.h \
    QtRibbonMenuButton.h

RESOURCES += \
    qss.qrc \
