#ifndef QTRIBBONWINDOW_H
#define QTRIBBONWINDOW_H

#include "LibRibbonUIGlobal.h"
#include <QMainWindow>

class QtRibbonWindowButtonGroup;

class LIBRIBBONUISHARED_EXPORT QtRibbonWindow : public QMainWindow
{
    Q_OBJECT
public:
    QtRibbonWindow(QWidget* parent = nullptr);

 private:
    QtRibbonWindowButtonGroup *m_bg;
};

#endif // QTRIBBONWINDOW_H
