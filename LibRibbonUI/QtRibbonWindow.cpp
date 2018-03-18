#include "QtRibbonWindow.h"
#include "QtRibbonWindowButtonGroup.h"
#include "QtRibbonWindowBar.h"
#include <QFile>

QtRibbonWindow::QtRibbonWindow(QWidget *parent)
    : QMainWindow(parent),
      m_wbg(new QtRibbonWindowButtonGroup(this)),
      m_wb(new QtRibbonWindowBar(this))
{
    this->resize(800, 600);//设置窗口默认大小
    this->setWindowFlags(Qt::FramelessWindowHint); //隐藏标题栏
    this->setMenuWidget(m_wb);//添加自定义菜单栏
    m_wbg->raise();

    QFile file(":/default.qss");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return;
    }
    setStyleSheet(file.readAll());
}
