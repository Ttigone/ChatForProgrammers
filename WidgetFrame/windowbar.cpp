#include "windowbar.h"
#include "windowbar_p.h"

#include <QtCore/QLocale>

#include <QEvent>

namespace Ttigone {

    WindowBarPrivate::WindowBarPrivate() {
        w = nullptr;
        autoTitle = true;
        autoIcon = false;
    }

    WindowBarPrivate::~WindowBarPrivate() = default;

    void WindowBarPrivate::init() {
        // Gets a pointer to the original class
        Q_Q(WindowBar);
        m_layout = new QHBoxLayout();

        if (QLocale::system().textDirection() == Qt::RightToLeft) {
            m_layout->setDirection(QBoxLayout::RightToLeft);
        }

        m_layout->setContentsMargins(QMargins());
        m_layout->setSpacing(0);
        for (int i = IconButton; i <= CloseButton; ++i) {
            insertDefaultSpace(i);
        }
        q->setLayout(m_layout);
    }

    void WindowBarPrivate::setWidgetAt(int index, QWidget *widget) {
        auto priWidget = m_layout->takeAt(index)->widget();
        if (priWidget) {
            priWidget->deleteLater();
        }
        if (!widget) {
            insertDefaultSpace(index);
        } else {
            m_layout->insertWidget(index, widget);
        }
    }

    QWidget *WindowBarPrivate::takeWidgetAt(int index) {
        auto item = m_layout->itemAt(index);
        auto priWidget = item->widget();
        if (priWidget) {
            item = m_layout->takeAt(index);
            delete item;
            insertDefaultSpace(index);
        }
        return priWidget;
    }


    // 委托构造
    WindowBar::WindowBar(QWidget *parent) : WindowBar(*new WindowBarPrivate(), parent) {
    }

    QMenuBar *WindowBar::menuBar() const {
        Q_D(const WindowBar);
        return qobject_cast<QMenuBar *>(d->widgetAt(WindowBarPrivate::MenuWidget));
    }

    QLabel *WindowBar::titleLabel() const {
        Q_D(const WindowBar);
        return qobject_cast<QLabel *>(d->widgetAt(WindowBarPrivate::TitleLabel));
    }

    QAbstractButton *WindowBar::iconButton() const {
        Q_D(const WindowBar);
        return qobject_cast<QAbstractButton *>(d->widgetAt(WindowBarPrivate::IconButton));
    }

    QAbstractButton *WindowBar::minButton() const {
        Q_D(const WindowBar);
        return qobject_cast<QAbstractButton *>(d->widgetAt(WindowBarPrivate::MinimumButton));
    }

    QAbstractButton *WindowBar::maxButton() const {
        Q_D(const WindowBar);
        return qobject_cast<QAbstractButton *>(d->widgetAt(WindowBarPrivate::MaxinumButton));
    }

    QAbstractButton *WindowBar::closeButton() const {
        Q_D(const WindowBar);
        return qobject_cast<QAbstractButton *>(d->widgetAt(WindowBarPrivate::CloseButton));
    }

    void WindowBar::setMenuBar(QMenuBar *menuBar) {
        Q_D(WindowBar);
        auto pri = takeMenuBar();
        if (pri) {
            pri->deleteLater();
        }
        if (!menuBar) {
            return;
        }
        d->setWidgetAt(WindowBarPrivate::MenuWidget, menuBar);
        menuBar->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);
    }

    void WindowBar::setTitleLabel(QLabel *label) {
        Q_D(WindowBar);
        auto pri = takeTitleLabel();
        if (pri) {
            pri->deleteLater();
        }
        if (!label) {
            return;
        }
        d->setWidgetAt(WindowBarPrivate::TitleLabel, label);
        if (d->autoTitle && d->w) {
            label->setText(d->w->windowTitle());
        }
        label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    }

    void WindowBar::setIconButton(QAbstractButton *btn) {
        Q_D(WindowBar);
        auto pri = takeIconButton();
        if (pri) {
            pri->deleteLater();
        }
        if (!btn) {
            return;
        }
        d->setWidgetAt(WindowBarPrivate::IconButton, btn);
        if (d->autoIcon && d->w) {
            btn->setIcon(d->w->windowIcon());
        }
        btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    }

    void WindowBar::setMinButton(QAbstractButton *btn) {
        Q_D(WindowBar);
        auto pri = takeMinButton();
        if (pri) {
            pri->deleteLater();
        }
        if (!btn) {
            return;
        }
        d->setWidgetAt(WindowBarPrivate::MinimumButton, btn);
        connect(btn, &QAbstractButton::clicked, this, &WindowBar::minimizeRequested);
    }

    void WindowBar::setMaxButton(QAbstractButton *btn) {
        Q_D(WindowBar);
        auto pri = takeMaxButton();
        if (pri) {
            pri->deleteLater();
        }
        if (!btn) {
            return;
        }
        d->setWidgetAt(WindowBarPrivate::MaxinumButton, btn);
        connect(btn, &QAbstractButton::clicked, this, &WindowBar::maximizeRequested);
    }

    void WindowBar::setCloseButton(QAbstractButton *btn) {
        Q_D(WindowBar);
        auto pri = takeCloseButton();
        if (pri) {
            pri->deleteLater();
        }
        if (!btn) {
            return;
        }
        d->setWidgetAt(WindowBarPrivate::CloseButton, btn);
        connect(btn, &QAbstractButton::clicked, this, &WindowBar::closeRequested);
    }

    QMenuBar *WindowBar::takeMenuBar() {
        Q_D(WindowBar);
        return qobject_cast<QMenuBar *>(d->takeWidgetAt(WindowBarPrivate::MenuWidget));
    }

    QLabel *WindowBar::takeTitleLabel() {
        Q_D(WindowBar);
        return qobject_cast<QLabel *>(d->takeWidgetAt(WindowBarPrivate::TitleLabel));

    }

    QAbstractButton *WindowBar::takeIconButton() {
        Q_D(WindowBar);
        return qobject_cast<QAbstractButton *>(d->takeWidgetAt(WindowBarPrivate::IconButton));
    }

    QAbstractButton *WindowBar::takeMinButton() {
        Q_D(WindowBar);
        return qobject_cast<QAbstractButton *>(d->takeWidgetAt(WindowBarPrivate::MinimumButton));
    }

    QAbstractButton *WindowBar::takeMaxButton() {
        Q_D(WindowBar);
        return qobject_cast<QAbstractButton *>(d->takeWidgetAt(WindowBarPrivate::MaxinumButton));

    }

    QAbstractButton *WindowBar::takeCloseButton() {
        Q_D(WindowBar);
        return qobject_cast<QAbstractButton *>(d->takeWidgetAt(WindowBarPrivate::CloseButton));
    }

    QWidget *WindowBar::hostWidget() const {
        Q_D(const WindowBar);
        return d->w;
    }

    void WindowBar::setHostWidget(QWidget *w) {
        Q_D(WindowBar);
        QWidget *pri = d->w;
        if (pri) {
            pri->removeEventFilter(this);
        }
        d_ptr->w = w;
        if (w) {
            w->installEventFilter(this);
        }
    }

    bool WindowBar::titleFollowWindow() const {
        Q_D(const WindowBar);
        return d->autoTitle;
    }

    void WindowBar::setTitleFollowWindow(bool value) {
        Q_D(WindowBar);
        d->autoTitle = value;
    }

    bool WindowBar::iconFollowWindow() const {
        Q_D(const WindowBar);
        return d->autoIcon;
    }

    void WindowBar::setIconFollowWindow(bool value) {
        Q_D(WindowBar);
        d->autoIcon = value;
    }

    bool WindowBar::eventFilter(QObject *obj, QEvent *event) {
        Q_D(WindowBar);
        auto w = d->w;
        if (obj == w) {
            QAbstractButton *iconBtn = iconButton();
            QLabel *label = titleLabel();
            QAbstractButton *maxBtn = maxButton();
            switch (event->type()) {
                case QEvent::WindowIconChange: {
                    if (d_ptr->autoIcon && iconBtn) {
                        iconBtn->setIcon(w->windowIcon());
                        iconChanged(w->windowIcon());
                    }
                    break;
                }
                case QEvent::WindowTitleChange: {
                    if (d_ptr->autoTitle && label) {
                        label->setText(w->windowTitle());
                        titleChanged(w->windowTitle());
                    }
                    break;
                }
                case QEvent::WindowStateChange: {
                    if (maxBtn) {
                        maxBtn->setChecked(w->isMaximized());
                    }
                    break;
                }
                default:
                    break;
            }
        }
        return QWidget::eventFilter(obj, event);
    }

    void WindowBar::titleChanged(const QString &text) {
        Q_UNUSED(text)
    }

    void WindowBar::iconChanged(const QIcon &icon) {
        Q_UNUSED(icon)
    }


    WindowBar::~WindowBar() = default;

    WindowBar::WindowBar(WindowBarPrivate &d, QWidget *parent) : QFrame(parent), d_ptr(&d) {
        // Public Class Point of Private Class is assigned to the Public Class Point
        d.q_ptr = this;
        // execute private actions
        d.init();
    }


}
