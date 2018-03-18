#ifndef QTRIBBONWINDOW_H
#define QTRIBBONWINDOW_H

#include "LibRibbonUIGlobal.h"
#include <QMainWindow>

class QtRibbonWindowButtonGroup;
class QtRibbonWindowBar;

class LIBRIBBONUISHARED_EXPORT QtRibbonWindow : public QMainWindow
{
    Q_OBJECT
public:
    QtRibbonWindow(QWidget* parent = nullptr);

 private:
    QtRibbonWindowButtonGroup *m_wbg;
    QtRibbonWindowBar *m_wb;
};

#endif // QTRIBBONWINDOW_H
