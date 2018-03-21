#ifndef QTRIBBONMENUBUTTON_H
#define QTRIBBONMENUBUTTON_H

#include "LibRibbonUIGlobal.h"
#include <QToolButton>

class LIBRIBBONUISHARED_EXPORT QtRibbonMenuButton : public QToolButton
{
    Q_OBJECT
public:
    QtRibbonMenuButton(QWidget *parent = nullptr);

public:
    void setAction(QAction *action);
};

#endif // QTRIBBONMENUBUTTON_H
