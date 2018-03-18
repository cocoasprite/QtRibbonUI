#ifndef QTRIBBONWINDOWBAR_H
#define QTRIBBONWINDOWBAR_H

#include "LibRibbonUIGlobal.h"
#include <QMenuBar>

class LIBRIBBONUISHARED_EXPORT QtRibbonWindowBar : public QMenuBar
{
    Q_OBJECT
public:
    QtRibbonWindowBar(QWidget* parent = nullptr);

protected slots:
    void onWindowTitleChanged(const QString &title);
    void onWindowIconChanged(const QIcon &icon);
};

#endif // QTRIBBONWINDOWBAR_H
