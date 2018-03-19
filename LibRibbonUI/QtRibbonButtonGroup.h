#ifndef QTRIBBONBUTTONGROUP_H
#define QTRIBBONBUTTONGROUP_H

#include "LibRibbonUIGlobal.h"
#include <QWidget>

class QtRibbonButtonGroupPrivate;

class LIBRIBBONUISHARED_EXPORT QtRibbonButtonGroup
        : public QWidget
{
    Q_OBJECT
public:
    QtRibbonButtonGroup(QWidget* parent = nullptr);
    ~QtRibbonButtonGroup();

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
    QtRibbonButtonGroupPrivate *m_wbgp;
};

#endif // QTRIBBONBUTTONGROUP_H
