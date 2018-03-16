#ifndef QTRIBBONWINDOW_H
#define QTRIBBONWINDOW_H

#include "LibRibbonUIGlobal.h"

#include <QMainWindow>

class LIBRIBBONUISHARED_EXPORT QtRibbonWindow : public QMainWindow
{
    Q_OBJECT
public:
    QtRibbonWindow(QWidget* parent = nullptr);
};

#endif // QTRIBBONWINDOW_H
