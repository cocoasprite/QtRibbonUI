#include "QtRibbonQuickAccessBar.h"
#include "QtRibbonToolButton.h"
#include "QtRibbonSeparatorWidget.h"
#include <QAction>
#include <QHBoxLayout>
#include <QLabel>

QtRibbonQuickAccessBar::QtRibbonQuickAccessBar(QWidget *parent)
    : QFrame(parent)
{
    m_layoutLogo = new QHBoxLayout();
    m_layoutBar = new QHBoxLayout();
    m_layoutTitle = new QHBoxLayout();

    m_logo = new QLabel(this);
    m_title = new QLabel(this);

    m_layoutLogo->setContentsMargins(0, 0, 0, 0);
    m_layoutLogo->setSpacing(10);
    m_layoutLogo->addWidget(m_logo);
    m_layoutLogo->addWidget(new QtRibbonSeparatorWidget(this));

    m_layoutTitle->setContentsMargins(0, 0, 0, 0);
    m_layoutTitle->setSpacing(10);
    m_layoutTitle->addWidget(new QtRibbonSeparatorWidget(this));
    m_layoutTitle->addWidget(m_title);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->setContentsMargins(10, 0, 10, 0);
    layout->setSpacing(0);
    layout->addLayout(m_layoutLogo);
    layout->addLayout(m_layoutBar);
    layout->addLayout(m_layoutTitle);
    this->setLayout(layout);
    this->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
}

QtRibbonQuickAccessBar::~QtRibbonQuickAccessBar()
{
    delete m_logo;
    delete m_title;
    delete m_layoutLogo;
    delete m_layoutBar;
    delete m_layoutTitle;
}

void QtRibbonQuickAccessBar::setLogo(const QIcon &icon)
{
    m_logo->setPixmap(icon.pixmap(16, 16));
}

void QtRibbonQuickAccessBar::setTitle(const QString &title)
{
    m_title->setText(title);
}

void QtRibbonQuickAccessBar::addButton(QAction *action)
{
    QtRibbonToolButton *btn = new QtRibbonToolButton(action, this);
    btn->setToolButtonStyle(Qt::ToolButtonIconOnly);
    btn->setFixedSize(26, 26);
    m_layoutBar->addWidget(btn);
    m_layoutBar->setAlignment(btn, Qt::AlignCenter);
}

void QtRibbonQuickAccessBar::addSeparator()
{
    QtRibbonSeparatorWidget *separatorWidget = new QtRibbonSeparatorWidget(this);
    m_layoutBar->addWidget(separatorWidget);
    m_layoutBar->setAlignment(separatorWidget, Qt::AlignCenter);
}
