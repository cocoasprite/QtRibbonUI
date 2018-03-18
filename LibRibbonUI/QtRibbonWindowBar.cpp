#include "QtRibbonWindowBar.h"

QtRibbonWindowBar::QtRibbonWindowBar(QWidget *parent)
    : QMenuBar(parent)
{
    this->addMenu(new QMenu("文件"));
    this->addAction(new QAction("打开"));

    QObject::connect(parent, &QWidget::windowTitleChanged, this, &QtRibbonWindowBar::onWindowTitleChanged);
    QObject::connect(parent, &QWidget::windowIconChanged, this, &QtRibbonWindowBar::onWindowIconChanged);
}

void QtRibbonWindowBar::onWindowTitleChanged(const QString &title)
{
    Q_UNUSED(title);
    update();
}

void QtRibbonWindowBar::onWindowIconChanged(const QIcon &icon)
{
    if(!icon.isNull())
    {
        //int iconMinSize = m_d->titleBarHight - 6;
        //QSize s = icon.actualSize(QSize(iconMinSize,iconMinSize));
        //m_d->iconRightBorderPosition = m_d->widgetBord.left()+s.width();
    }
    update();
}
