#include "QtRibbonWindowBar.h"
#include "QtRibbonQuickAccessBar.h"
#include "QtRibbonMenuButton.h"

class QtRibbonWindowBarPrivate
{
public:
    QtRibbonWindowBarPrivate(QtRibbonWindowBar *parent = nullptr)
    {
        m_quickAccessBar = new QtRibbonQuickAccessBar(parent);
        m_menuButton = new QtRibbonMenuButton(parent);
        m_menuButton->setGeometry(0, 30, 56, 24);

        m_windowBar = parent;
    }

public:
    QtRibbonWindowBar *m_windowBar;
    QtRibbonQuickAccessBar *m_quickAccessBar; //快速响应栏
    QtRibbonMenuButton *m_menuButton;//菜单按钮
};

QtRibbonWindowBar::QtRibbonWindowBar(QWidget *parent)
    : QMenuBar(parent),
      m_wbp(new QtRibbonWindowBarPrivate(this))
{
    this->setFixedHeight(54);
}

QtRibbonWindowBar::~QtRibbonWindowBar()
{
    delete m_wbp;
}

QtRibbonQuickAccessBar *QtRibbonWindowBar::quickAccessBar()
{
    return m_wbp->m_quickAccessBar;
}

QtRibbonMenuButton *QtRibbonWindowBar::menuButton()
{
    return m_wbp->m_menuButton;
}
