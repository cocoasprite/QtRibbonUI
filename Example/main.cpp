#include "QtRibbonWindow.h"
#include "QtRibbonWindowBar.h"
#include "QtRibbonQuickAccessBar.h"
#include "QtRibbonToolButton.h"
#include "QtRibbonMenuButton.h"
#include <QApplication>
#include <QElapsedTimer>
#include <QFontDatabase>
#include <QFileInfo>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QElapsedTimer cost;
    cost.start();

    QString strPath = QByteArray(argv[0]);
    QFileInfo fileinfo(strPath);
    QString filePath = fileinfo.absolutePath();

    //a.setFont(QFont("微软雅黑"));
    int nIndex = QFontDatabase::addApplicationFont(("./wqy-zenhei.ttc"));
    if (nIndex != -1)
    {
        QStringList strList(QFontDatabase::applicationFontFamilies(nIndex));
        if (strList.count() > 0)
        {
            QFont fontThis(strList.at(0));
            fontThis.setPixelSize(11);
            a.setFont(fontThis);
        }
        qDebug() << nIndex << strList;
    }

    QtRibbonWindow w;

    w.setWindowTitle(QString("Ribbon 测试程序"));
    w.setWindowIcon(QIcon(":/edit-image.png"));

    QtRibbonToolButton *btn1 = w.ribbonWindowBar()->quickAccessBar()->addButton(new QAction(QIcon(":/save.png"), "保存", &w));
    QtRibbonToolButton *btn2 = w.ribbonWindowBar()->quickAccessBar()->addButton(new QAction(QIcon(":/undo.png"), "撤销", &w));
    QtRibbonToolButton *btn3 = w.ribbonWindowBar()->quickAccessBar()->addButton(new QAction(QIcon(":/redo.png"), "保存", &w));

    QObject::connect(btn1, &QtRibbonToolButton::clicked, [=]{
        qDebug() << "clicked btn1.";
    });
    QObject::connect(btn2, &QtRibbonToolButton::clicked, [=]{
        qDebug() << "clicked btn2.";
    });
    QObject::connect(btn3, &QtRibbonToolButton::clicked, [=]{
        qDebug() << "clicked btn3.";
    });

    w.ribbonWindowBar()->menuButton()->setAction(new QAction(QIcon(":/more.png"), "更多", &w));

    qDebug() << "window build cost:" << cost.elapsed() << " ms";
    w.show();

    return a.exec();
}
