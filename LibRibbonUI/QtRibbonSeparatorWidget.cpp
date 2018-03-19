#include "QtRibbonSeparatorWidget.h"
#include <QPainter>

QtRibbonSeparatorWidget::QtRibbonSeparatorWidget(QWidget *parent)
    : QWidget(parent)
{
}

QSize QtRibbonSeparatorWidget::sizeHint() const
{
    return QSize(10, height() - 10);
}

void QtRibbonSeparatorWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.save();
    int margin = 3;
    painter.setPen(palette().background().color().darker(114));
    int x1 = rect().center().x();
    painter.drawLine(QPoint(x1, rect().top() + margin), QPoint(x1, rect().bottom() - margin));
    painter.restore();
}
