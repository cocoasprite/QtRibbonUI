INCLUDEPATH     += $$PWD/LibRibbonUI
DEPENDPATH      += $$PWD/LibRibbonUI

CONFIG(debug, debug|release){
    LIBS        += -L$$PWD/bin/ -lLibRibbonUId
}else{
    LIBS        += -L$$PWD/bin/ -lLibRibbonUI
}
