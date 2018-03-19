#ifndef QTRIBBONWINDOW_H
#define QTRIBBONWINDOW_H

#include "LibRibbonUIGlobal.h"
#include <QMainWindow>

class QtRibbonButtonGroup;
class QtRibbonWindowBar;

class LIBRIBBONUISHARED_EXPORT QtRibbonWindow : public QMainWindow
{
    Q_OBJECT
public:
    QtRibbonWindow(QWidget* parent = nullptr);
    ~QtRibbonWindow();

public:
    QtRibbonWindowBar* ribbonWindowBar();

protected slots:
    void onWindowTitleChanged(const QString &title);
    void onWindowIconChanged(const QIcon &icon);

private:
    QtRibbonButtonGroup *m_bg;
    QtRibbonWindowBar *m_wb;
};

#endif // QTRIBBONWINDOW_H
