#include "QtRibbonWindow.h"
#include "QtRibbonWindowBar.h"
#include "QtRibbonQuickAccessBar.h"
#include <QApplication>
#include <QElapsedTimer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QElapsedTimer cost;
    cost.start();
    QtRibbonWindow w;

    w.setWindowTitle(QString("Ribbon TEST"));
    w.setWindowIcon(QIcon(":/edit-image.png"));

    w.ribbonWindowBar()->quickAccessBar()->addButton(new QAction(QIcon(":/save.png"), "保存", &w));
    w.ribbonWindowBar()->quickAccessBar()->addButton(new QAction(QIcon(":/undo.png"), "撤销", &w));
    w.ribbonWindowBar()->quickAccessBar()->addButton(new QAction(QIcon(":/redo.png"), "重做", &w));
    w.ribbonWindowBar()->quickAccessBar()->addSeparator();

    qDebug() << "window build cost:" << cost.elapsed() << " ms";

    w.show();

    return a.exec();
}
