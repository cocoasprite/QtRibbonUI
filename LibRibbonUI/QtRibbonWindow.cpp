#include "QtRibbonWindow.h"
#include "QtRibbonButtonGroup.h"
#include "QtRibbonWindowBar.h"
#include "QtRibbonQuickAccessBar.h"
#include <QFile>
#include <qDebug>

QtRibbonWindow::QtRibbonWindow(QWidget *parent)
    : QMainWindow(parent),
      m_bg(new QtRibbonButtonGroup(this)),
      m_wb(new QtRibbonWindowBar(this))
{
    this->resize(800, 600);//设置窗口默认大小
    this->setWindowFlags(Qt::FramelessWindowHint); //隐藏标题栏
    this->setMenuWidget(m_wb);//添加自定义菜单栏
    m_bg->raise();//将最小化、最大化、关闭按钮组提升到最顶层

    QObject::connect(this, &QtRibbonWindow::windowIconChanged, this, &QtRibbonWindow::onWindowIconChanged);
    QObject::connect(this, &QtRibbonWindow::windowTitleChanged, this, &QtRibbonWindow::onWindowTitleChanged);

    QFile file(":/default.qss");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return;
    }
    setStyleSheet(file.readAll());
}

QtRibbonWindow::~QtRibbonWindow()
{
    delete m_bg;
    delete m_wb;
}

QtRibbonWindowBar *QtRibbonWindow::ribbonWindowBar()
{
    return m_wb;
}

void QtRibbonWindow::onWindowTitleChanged(const QString &title)
{
    if(!title.isEmpty())
    {
        m_wb->quickAccessBar()->setTitle(title);
    }
}

void QtRibbonWindow::onWindowIconChanged(const QIcon &icon)
{
    if(!icon.isNull())
    {
        m_wb->quickAccessBar()->setLogo(icon);
    }
}
