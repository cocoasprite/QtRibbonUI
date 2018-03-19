#include "QtRibbonWindowBar.h"
#include "QtRibbonQuickAccessBar.h"

class QtRibbonWindowBarPrivate
{
public:
    QtRibbonWindowBarPrivate(QtRibbonWindowBar *parent = nullptr)
    {
        m_quickAccessBar = new QtRibbonQuickAccessBar(parent);
        m_windowBar = parent;
    }

public:
    QtRibbonWindowBar *m_windowBar;
    QtRibbonQuickAccessBar *m_quickAccessBar; //快速响应栏
};

QtRibbonWindowBar::QtRibbonWindowBar(QWidget *parent)
    : QMenuBar(parent),
      m_wbp(new QtRibbonWindowBarPrivate(this))
{
    this->setFixedHeight(60);
}

QtRibbonWindowBar::~QtRibbonWindowBar()
{
    delete m_wbp;
}

QtRibbonQuickAccessBar *QtRibbonWindowBar::quickAccessBar()
{
    return m_wbp->m_quickAccessBar;
}
