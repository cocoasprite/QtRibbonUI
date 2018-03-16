#include "QtRibbonWindow.h"

QtRibbonWindow::QtRibbonWindow(QWidget *parent) : QMainWindow(parent)
{
    this->resize(800, 600);//设置窗口默认大小
    this->setWindowFlags(Qt::FramelessWindowHint); //隐藏标题栏
}
