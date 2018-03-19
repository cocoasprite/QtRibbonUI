#include "QtRibbonToolButton.h"

QtRibbonToolButton::QtRibbonToolButton(QAction *action, QWidget *parent)
    : QToolButton(parent)
{
    this->setDefaultAction(action);
}
