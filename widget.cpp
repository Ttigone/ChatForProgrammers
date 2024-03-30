#include "widget.h"


#include <QFile>
#include <QLabel>
#include <QMenuBar>
#include <QTimer>
#include <QBoxLayout>
#include <QThread>
#include <QtWidgets/QApplication>


#include "qt-easy-logger-main/logger.h"
#include "windowbar.h"
#include "windowbutton.h"



Widget::Widget(QWidget *parent)
    : QWidget(parent) {

    qInstallMessageHandler(h::Logger::messageHandler);  // 启用功能
    installWindowAgent();
    loadStyleSheet(Theme::Dark);

    m_layout->setContentsMargins(QMargins());
    this->setMinimumSize(800, 600);
    this->setLayout(m_layout);

    windowAgent->centralize();

}

Widget::~Widget() {}

// solve click maxBtn, then the maxBtn will hover a little time, so we shoule cancle that time
static inline void emulateLeaveEvent(QWidget *widget) {
    Q_ASSERT(widget);
    if (!widget) {
        return;
    }
    QTimer::singleShot(0, widget, [widget]() {
#if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
        const  QScreen *screen = widget->screen();
#else
        const QScreen *screen = widget.windowHandle()->screen();
#endif
        const QPoint globalPos = QCursor::pos(screen);
        if (!QRect(widget->mapToGlobal(QPoint(0, 0)), widget->size()).contains(globalPos)) {
            QCoreApplication::postEvent(widget, new QEvent(QEvent::Leave));
            if (widget->testAttribute(Qt::WA_Hover)) {
                const QPoint localPos = widget->mapFromGlobal(globalPos);
                const QPoint scenePos = widget->window()->mapFromGlobal(globalPos);
                static constexpr const auto oldPos = QPoint();
                const Qt::KeyboardModifiers modifiers = QGuiApplication::keyboardModifiers();
#if (QT_VERSION >= QT_VERSION_CHECK(6, 4, 0))
                const auto event = new QHoverEvent(QEvent::HoverLeave, scenePos, globalPos, oldPos, modifiers);
                Q_UNUSED(localPos);
#elif (QT_VERSION >= QT_VERSION_CHECK(6, 3, 0))
                const auto event = new QHoverEvent(QEvent::HoverLeave, localPos, globalPos, oldPos, modifiers);
                Q_UNUSED(scenePos);
#else
                const auto event = new QHoverEvent(QEvent::HoverLeave, localPos, oldPos, modifiers);
                Q_UNUSED(scenePos);
#endif
                QCoreApplication::postEvent(widget, event);
            }
        }
    });
}

void Widget::installWindowAgent() {
    m_layout = new QVBoxLayout();

    windowAgent = new QWK::WidgetWindowAgent(this);
    windowAgent->setup(this);

    auto menuBar = [this](){
        Q_UNUSED(this)
        auto menuBar = new QMenuBar();

        auto file = new QMenu(tr("File(&F)"), menuBar);
        file->addAction(new QAction(tr("New(&N)"), menuBar));
        file->addSeparator();

        auto edit = new QMenu(tr("Edit(&E)"), menuBar);
        edit->addAction(new QAction(tr("Undo(&U)"), menuBar));
        edit->addAction(new QAction(tr("Redo(&R)"), menuBar));


        menuBar->addMenu(file);
        menuBar->addMenu(edit);

        return menuBar;
    }();

    // set Object name
    menuBar->setObjectName(QStringLiteral("win-menu-bar"));

    auto titleLabel = new QLabel();
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setObjectName(QStringLiteral("win-title-label"));

    auto iconBtn = new Ttigone::WindowButton();
    iconBtn->setObjectName(QStringLiteral("icon-button"));
    iconBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    auto minBtn = new Ttigone::WindowButton();
    minBtn->setObjectName(QStringLiteral("min-button"));
    minBtn->setProperty("system-button", true);
    minBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    auto maxBtn = new Ttigone::WindowButton();
    maxBtn->setCheckable(true);
    maxBtn->setObjectName(QStringLiteral("max-button"));
    maxBtn->setProperty("system-button", true);
    maxBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    auto closeBtn = new Ttigone::WindowButton();
    closeBtn->setObjectName(QStringLiteral("close-button"));
    closeBtn->setProperty("system-button", true);
    closeBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    // create WindowBar
    auto windowBar = new Ttigone::WindowBar();
    // windowBar.
    windowBar->setIconButton(iconBtn);
    windowBar->setMinButton(minBtn);
    windowBar->setMaxButton(maxBtn);
    windowBar->setCloseButton(closeBtn);

    windowBar->setTitleLabel(titleLabel);
    windowBar->setMenuBar(menuBar);

    windowBar->setHostWidget(this);

    // windowBar->setFixedHeight(24);
    windowAgent->setTitleBar(windowBar);
    windowAgent->setSystemButton(QWK::WindowAgentBase::WindowIcon, iconBtn);
    windowAgent->setSystemButton(QWK::WindowAgentBase::Minimize, minBtn);
    windowAgent->setSystemButton(QWK::WindowAgentBase::Maximize, maxBtn);
    windowAgent->setSystemButton(QWK::WindowAgentBase::Close, closeBtn);

    windowAgent->setHitTestVisible(menuBar, true);


    m_layout->setMenuBar(windowBar);

    connect(iconBtn, &QAbstractButton::clicked, windowAgent, [this, iconBtn] {
        iconBtn->setProperty("double-click-close", false);

        // WindowBar's icon show a menu to choose
        QTimer::singleShot(75, windowAgent, [this, iconBtn]() {
            if (iconBtn->property("double-click-close").toBool()) {
                return;
            }
            windowAgent->showSystemMenu(iconBtn->mapToGlobal(QPoint(0, iconBtn->height())));
        });
    });

    connect(iconBtn, &Ttigone::WindowButton::doubleClicked, this, [iconBtn, this]() {
        iconBtn->setProperty("double-click-close", true);
        close();
    });

    connect(windowBar, &Ttigone::WindowBar::minimizeRequested, this, &QWidget::showMinimized);
    connect(windowBar, &Ttigone::WindowBar::maximizeRequested, this, [this, maxBtn](bool max) {
        if (max) {
            showMaximized();
        } else {
            showNormal();
        }
        // slove hover event
        emulateLeaveEvent(maxBtn);

    });
    connect(windowBar, &Ttigone::WindowBar::closeRequested, this, &QWidget::close);

}

void Widget::loadStyleSheet(Theme theme) {
    if (!styleSheet().isEmpty() && theme == currentTheme) {
        return;
    }
    currentTheme = theme;
    QFile qss(QStringLiteral(":/resources/theme/dark-style.qss"));
    qss.open(QIODevice::ReadOnly | QIODevice::Text);
    setStyleSheet(QString::fromUtf8(qss.readAll()));
    Q_EMIT themeChanged();


}

