#ifndef QTRIBBONTOOLBUTTON_H
#define QTRIBBONTOOLBUTTON_H

#include "LibRibbonUIGlobal.h"
#include <QToolButton>

class LIBRIBBONUISHARED_EXPORT QtRibbonToolButton : public QToolButton
{
    Q_OBJECT
public:
    QtRibbonToolButton(QAction *action, QWidget *parent = nullptr);
};

#endif // QTRIBBONTOOLBUTTON_H
