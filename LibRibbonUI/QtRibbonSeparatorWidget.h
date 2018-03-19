#ifndef QTRIBBONSEPARATORWIDGET_H
#define QTRIBBONSEPARATORWIDGET_H

#include "LibRibbonUIGlobal.h"
#include <QWidget>

class LIBRIBBONUISHARED_EXPORT QtRibbonSeparatorWidget : public QWidget
{
    Q_OBJECT
public:
    QtRibbonSeparatorWidget(QWidget* parent = nullptr);

public:
    virtual QSize sizeHint() const Q_DECL_OVERRIDE;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};

#endif // QTRIBBONSEPARATORWIDGET_H
