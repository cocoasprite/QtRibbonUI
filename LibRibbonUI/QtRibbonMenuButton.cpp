#include "QtRibbonMenuButton.h"

QtRibbonMenuButton::QtRibbonMenuButton(QWidget *parent)
    : QToolButton(parent)
{
    this->setPopupMode(QToolButton::MenuButtonPopup);
}

void QtRibbonMenuButton::setAction(QAction *action)
{
    this->setDefaultAction(action);
}
