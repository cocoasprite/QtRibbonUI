#ifndef QTRIBBONQUICKACCESSBAR_H
#define QTRIBBONQUICKACCESSBAR_H

#include "LibRibbonUIGlobal.h"
#include <QFrame>

class QAction;
class QtRibbonToolButton;
class QLabel;
class QHBoxLayout;

class LIBRIBBONUISHARED_EXPORT QtRibbonQuickAccessBar : public QFrame
{
    Q_OBJECT
public:
    QtRibbonQuickAccessBar(QWidget* parent = nullptr);
    ~QtRibbonQuickAccessBar();

public:
    void setLogo(const QIcon &icon);
    void setTitle(const QString &title);
    QtRibbonToolButton *addButton(QAction *action);
    void addSeparator();

private:
    QLabel *m_logo;
    QLabel *m_title;
    QHBoxLayout *m_layoutLogo;
    QHBoxLayout *m_layoutBar;
    QHBoxLayout *m_layoutTitle;
};

#endif // QTRIBBONQUICKACCESSBAR_H
