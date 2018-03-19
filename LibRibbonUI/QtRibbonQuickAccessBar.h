#ifndef QTRIBBONQUICKACCESSBAR_H
#define QTRIBBONQUICKACCESSBAR_H

#include "LibRibbonUIGlobal.h"
#include <QFrame>
#include <QAction>

class QtRibbonQuickAccessBarPrivate;
class QtRibbonToolButton;
class QLabel;

class LIBRIBBONUISHARED_EXPORT QtRibbonQuickAccessBar : public QFrame
{
    Q_OBJECT
public:
    QtRibbonQuickAccessBar(QWidget* parent = nullptr);
    ~QtRibbonQuickAccessBar();

public:
    void setLogo(const QIcon &icon);
    QtRibbonToolButton *addButton(QAction *action);
    void addSeparator();

private:
    QtRibbonQuickAccessBarPrivate *m_qabp;
    QLabel *m_logo;
};

#endif // QTRIBBONQUICKACCESSBAR_H
