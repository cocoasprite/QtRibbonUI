#include "QtRibbonQuickAccessBar.h"
#include "QtRibbonToolButton.h"
#include "QtRibbonSeparatorWidget.h"
#include <QAction>
#include <QHBoxLayout>
#include <QLabel>
#include <qDebug>

class QtRibbonQuickAccessBarPrivate
{
public:
    QtRibbonQuickAccessBarPrivate(QtRibbonQuickAccessBar *parent = nullptr)
    {
        m_parent = parent;

        QHBoxLayout *layout = new QHBoxLayout;
        layout->setContentsMargins(10, 0, 0, 0);
        layout->setSpacing(0);
        m_parent->setLayout(layout);
        m_parent->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    }

public:
    QtRibbonQuickAccessBar *m_parent;
};

QtRibbonQuickAccessBar::QtRibbonQuickAccessBar(QWidget *parent)
    : QFrame(parent),
      m_qabp(new QtRibbonQuickAccessBarPrivate(this)),
      m_logo(new QLabel(this))
{
    m_logo->setFixedSize(26, 26);
    this->layout()->addWidget(m_logo);
    this->layout()->setAlignment(m_logo, Qt::AlignCenter);
    this->addSeparator();
}

QtRibbonQuickAccessBar::~QtRibbonQuickAccessBar()
{
    delete m_qabp;
}

void QtRibbonQuickAccessBar::setLogo(const QIcon &icon)
{
    m_logo->setPixmap(icon.pixmap(16, 16));
}

QtRibbonToolButton *QtRibbonQuickAccessBar::addButton(QAction *action)
{
    QtRibbonToolButton *btn = new QtRibbonToolButton(action, this);
    btn->setToolButtonStyle(Qt::ToolButtonIconOnly);
    btn->setFixedSize(26, 26);
    this->layout()->addWidget(btn);
    this->layout()->setAlignment(btn, Qt::AlignCenter);
    return btn;
}

void QtRibbonQuickAccessBar::addSeparator()
{
    QtRibbonSeparatorWidget *separatorWidget = new QtRibbonSeparatorWidget(this);
    this->layout()->addWidget(separatorWidget);
    this->layout()->setAlignment(separatorWidget, Qt::AlignCenter);
}
