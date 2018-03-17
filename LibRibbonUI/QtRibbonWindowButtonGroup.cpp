#include "QtRibbonWindowButtonGroup.h"
#include <QPushButton>
#include <QStyle>
#include <QEvent>

class QtRibbonWindowButtonGroupPrivate
{
public:
    QtRibbonWindowButtonGroupPrivate() :
        m_buttonClose(nullptr),
        m_buttonMin(nullptr),
        m_buttonMax(nullptr)
    {}

public:
    void setupCloseButton(QtRibbonWindowButtonGroup* parent, bool on)
    {
        if(on)
        {
            if(!m_buttonClose)
            {
                m_buttonClose = new QPushButton(parent);
                m_buttonClose->setObjectName(QStringLiteral("QtRibbonCloseWindowButton"));
                m_buttonClose->setFixedSize(40,30);
                parent->connect(m_buttonClose, &QAbstractButton::clicked, parent,
                                &QtRibbonWindowButtonGroup::closeWindow);
                QIcon icon = parent->style()->standardIcon(QStyle::SP_TitleBarCloseButton);
                m_buttonClose->setIcon(icon);
            }
        }
        else
        {
            if(m_buttonClose)
            {
                delete m_buttonClose;
            }
        }
        updateSize(parent);
    }
    void setupMaxButton(QtRibbonWindowButtonGroup* parent, bool on)
    {
        if(on)
        {
            if(!m_buttonMax)
            {
                m_buttonMax = new QPushButton(parent);
                m_buttonMax->setObjectName(QStringLiteral("QtRibbonMaxWindowButton"));
                m_buttonMax->setFixedSize(30,30);
                parent->connect(m_buttonMax, &QAbstractButton::clicked, parent,
                                &QtRibbonWindowButtonGroup::maxWindow);
                QIcon icon = parent->style()->standardIcon(QStyle::SP_TitleBarMaxButton);
                m_buttonMax->setIcon(icon);
            }
        }
        else
        {
            if(m_buttonMax)
            {
                delete m_buttonMax;
            }
        }
        updateSize(parent);
    }
    void setupMinButton(QtRibbonWindowButtonGroup* parent, bool on)
    {
        if(on)
        {
            if(!m_buttonMin)
            {
                m_buttonMin = new QPushButton(parent);
                m_buttonMin->setObjectName(QStringLiteral("QtRibbonMinWindowButton"));
                m_buttonMin->setFixedSize(30,30);
                parent->connect(m_buttonMin, &QAbstractButton::clicked, parent,
                                &QtRibbonWindowButtonGroup::minWindow);
                QIcon icon = parent->style()->standardIcon(QStyle::SP_TitleBarMinButton);
                m_buttonMin->setIcon(icon);
            }
        }
        else
        {
            if(m_buttonMin)
            {
                delete m_buttonMin;
            }
        }
        updateSize(parent);
    }

    void updateSize(QtRibbonWindowButtonGroup* parent)
    {
        int span = 0;
        if(m_buttonClose)
        {
            m_buttonClose->move(parent->width() - m_buttonClose->width(), parent->y());
            span = m_buttonClose->width();
        }
        if(m_buttonMax)
        {
            m_buttonMax->move(parent->width() - m_buttonMax->width() - span, parent->y());
            span += m_buttonMax->width();
        }
        if(m_buttonMin)
        {
            m_buttonMin->move(parent->width() - m_buttonMin->width() - span, parent->y());
        }
    }

    QSize sizeHint()
    {
        int width = 0;
        int height = 0;
        if(m_buttonClose)
        {
            width += m_buttonClose->width();
            height = qMax(height, m_buttonClose->height());
        }
        if(m_buttonMax)
        {
            width += m_buttonMax->width();
            height = qMax(height, m_buttonMax->height());
        }
        if(m_buttonMin)
        {
            width += m_buttonMin->width();
            height = qMax(height, m_buttonMin->height());
        }
        return QSize(width,height);
    }

public:
    QPushButton *m_buttonClose;
    QPushButton *m_buttonMin;
    QPushButton *m_buttonMax;
};

QtRibbonWindowButtonGroup::QtRibbonWindowButtonGroup(QWidget *parent)
    : QWidget(parent), m_bgp(new QtRibbonWindowButtonGroupPrivate)
{
    if(parent)
        parent->installEventFilter(this);

    Qt::WindowFlags flags = parentWidget()->windowFlags();
    m_bgp->setupMinButton(this, (flags & Qt::WindowMinimizeButtonHint));
    m_bgp->setupMaxButton(this, (flags & Qt::WindowMaximizeButtonHint));
    m_bgp->setupCloseButton(this, (flags & Qt::WindowCloseButtonHint));
}

QtRibbonWindowButtonGroup::~QtRibbonWindowButtonGroup()
{
    delete m_bgp;
}

bool QtRibbonWindowButtonGroup::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == parentWidget())
    {
        switch(event->type())
        {
        case QEvent::Resize:
            parentResize();
            break;
        default:
            break;
        }
    }
    return false;//不截断任何事件
}

void QtRibbonWindowButtonGroup::parentResize()
{
    QWidget* parent = parentWidget();
    if(parent)
    {
        QSize parentSize = parent->size();
        move(parentSize.width() - width()-1, 1);
    }
}

QSize QtRibbonWindowButtonGroup::sizeHint()
{
    return m_bgp->sizeHint();
}

void QtRibbonWindowButtonGroup::closeWindow()
{
    if(parentWidget())
        parentWidget()->close();
}

void QtRibbonWindowButtonGroup::minWindow()
{
    if(parentWidget())
        parentWidget()->showMinimized();
}

void QtRibbonWindowButtonGroup::maxWindow()
{
    QWidget *parent = parentWidget();

    if(parent)
    {
        if(parent->isMaximized())
        {
            parent->showNormal();
        }
        else
        {
            parent->showMaximized();
        }

        if(parent->isMaximized())
        {
            if(m_bgp->m_buttonMax)
            {
                m_bgp->m_buttonMax->setIcon(style()->standardIcon(QStyle::SP_TitleBarNormalButton));
            }
        }
        else
        {
            if(m_bgp->m_buttonMax)
            {
                m_bgp->m_buttonMax->setIcon(style()->standardIcon(QStyle::SP_TitleBarMaxButton));
            }
        }
    }
}
