#ifndef QTRIBBONWINDOWBAR_H
#define QTRIBBONWINDOWBAR_H

#include "LibRibbonUIGlobal.h"
#include <QMenuBar>

class QtRibbonWindowBarPrivate;
class QtRibbonQuickAccessBar;
class QtRibbonMenuButton;

class LIBRIBBONUISHARED_EXPORT QtRibbonWindowBar : public QMenuBar
{
    Q_OBJECT
public:
    QtRibbonWindowBar(QWidget* parent = nullptr);
    ~ QtRibbonWindowBar();

public:
    QtRibbonQuickAccessBar *quickAccessBar();//获取快速响应栏
    QtRibbonMenuButton *menuButton();//获取菜单按钮

protected slots:

private:
    friend class QtRibbonWindowBarPrivate;
    QtRibbonWindowBarPrivate *m_wbp;
};

#endif // QTRIBBONWINDOWBAR_H
