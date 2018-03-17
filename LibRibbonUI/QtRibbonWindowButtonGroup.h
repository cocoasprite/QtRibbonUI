#ifndef QTRIBBONWINDOWBUTTONGROUP_H
#define QTRIBBONWINDOWBUTTONGROUP_H

#include "LibRibbonUIGlobal.h"
#include <QWidget>

class QtRibbonWindowButtonGroupPrivate;

class LIBRIBBONUISHARED_EXPORT QtRibbonWindowButtonGroup
        : public QWidget
{
    Q_OBJECT
public:
    QtRibbonWindowButtonGroup(QWidget* parent = nullptr);
    ~QtRibbonWindowButtonGroup();

protected:
    QSize sizeHint();
    virtual bool eventFilter(QObject *watched, QEvent *event);
    virtual void parentResize();

public slots:
    Q_SLOT void closeWindow();
    Q_SLOT void minWindow();
    Q_SLOT void maxWindow();

private:
    friend class SAWindowButtonGroupPrivate;
    QtRibbonWindowButtonGroupPrivate *m_bgp;
};

#endif // QTRIBBONWINDOWBUTTONGROUP_H
