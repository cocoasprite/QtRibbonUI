#include "QtRibbonWindow.h"
#include "QtRibbonWindowButtonGroup.h"
#include <QFile>

QtRibbonWindow::QtRibbonWindow(QWidget *parent)
    : QMainWindow(parent), m_bg(new QtRibbonWindowButtonGroup(this))
{
    this->resize(800, 600);//设置窗口默认大小
    this->setWindowFlags(Qt::FramelessWindowHint); //隐藏标题栏

    QFile file(":/default.qss");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return;
    }
    setStyleSheet(file.readAll());
}
