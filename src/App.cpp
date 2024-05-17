#include <QFile>
#include <QLabel>
#include <QMenuBar>
#include <QTimer>
#include <QBoxLayout>
#include <QThread>
#include <QtWidgets/QApplication>
#include <QListWidget>
#include <QSizePolicy>
#include <QSplitter>
#include <QStackedLayout>

#include "qt-easy-logger-main/logger.h"

#include "App.h"
#include "Sys/SysConfig.h"
#include "Sys/MiddleWare.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent) {

    qInstallMessageHandler(h::Logger::messageHandler);  // 启用功能

    m_layout = new QVBoxLayout;
    installWindowAgent();
    init();
    loadStyleSheet(Theme::Dark);

    m_layout->setContentsMargins(QMargins());


    this->setMinimumSize(1000, 730);
    this->setLayout(m_layout);

    windowAgent->centralize();

}

Widget::~Widget() {}

void Widget::init() {
    m_mainLayout = new QHBoxLayout;
    m_mainLayout->setContentsMargins(QMargins());
    m_mainLayout->setSpacing(0);

    m_msgBox = new MainMsgBox;
    m_msgBox->setFixedWidth(50);


    m_msgList = new MainChatList;


    m_mainLayout->addWidget(m_msgBox);

    m_mainLayout->addSpacerItem(new QSpacerItem(0, 0));

    m_msgList->setMinimumWidth(200);
    // 关闭水平条
    m_msgList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_msgList->setStyleSheet("QListView { border: none; }");
    m_msgRWidget->setMinimumWidth(420);

    m_searchWidget = new SearchWidget;
    m_searchWidget->setFixedHeight(66); // 固定的高

    m_msgLWidget = new QWidget;
    m_msgLWidget->setMinimumWidth(200);
    m_msgLLayout = new QVBoxLayout(m_msgLWidget);
    m_msgLLayout->setContentsMargins(QMargins());
    m_msgLLayout->setSpacing(0);
    m_msgLLayout->addWidget(m_searchWidget);
    m_msgLLayout->addWidget(m_msgList);


    QSplitter *splitter = new QSplitter;
    QList<int> sizes;
    sizes << 200 << 420;
    splitter->addWidget(m_msgLWidget);
    splitter->addWidget(m_msgRWidget);
    splitter->setSizes(sizes);
    splitter->setCollapsible(0, false);
    splitter->setCollapsible(1, false);
    splitter->setHandleWidth(1);
    m_mainLayout->addWidget(splitter);


    m_stackLayout = new QStackedLayout;
    // m_mainMsgWidget = new MainMsgWidget;
    // m_stackLayout->insertWidget(0, m_mainMsgWidget);
    MiddleWare::instance().installListenerService(m_msgList, m_stackLayout);


    // m_msgRLayout->addWidget(m_mainMsgWidget);
    m_msgRLayout->addLayout(m_stackLayout);


    m_layout->addLayout(m_mainLayout);

}

void Widget::showCenter()
{
    windowAgent->centralize();
}

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
    m_msgRLayout = new QVBoxLayout();
    m_msgRWidget = new QWidget;
    m_msgRWidget->setLayout(m_msgRLayout);
    m_msgRLayout->setContentsMargins(QMargins());
    m_msgRLayout->setSpacing(0);
    // m_layout = new QVBoxLayout();

    windowAgent = new QWK::WidgetWindowAgent(this);
    windowAgent->setup(this);

    // auto menuBar = [this](){
    auto menuBar = [this](){
        Q_UNUSED(this)
        auto menuBar = new QMenuBar();

        // auto file = new QMenu(tr("File(&F)"), menuBar);
        // file->addAction(new QAction(tr("New(&N)"), menuBar));
        // file->addSeparator();

        // auto edit = new QMenu(tr("Edit(&E)"), menuBar);
        // edit->addAction(new QAction(tr("Undo(&U)"), menuBar));
        // edit->addAction(new QAction(tr("Redo(&R)"), menuBar));


        // menuBar->addMenu(file);
        // menuBar->addMenu(edit);

        return menuBar;
    }();

    // set Object name
    menuBar->setObjectName(QStringLiteral("win-menu-bar"));

    auto titleLabel = new QLabel();
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setObjectName(QStringLiteral("win-title-label"));
    titleLabel->setText(tr("C3H3_Ttigone"));

    // auto iconBtn = new Ttigone::WindowButton();
    // iconBtn->setObjectName(QStringLiteral("icon-button"));
    // iconBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

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

    // connect(closeBtn, &QPushButton::clicked, [this](){
    //     // qDebug() << "enxia";
    // });


    // create WindowBar
    auto windowBar = new Ttigone::WindowBar();

    // qDebug() << windowBar;
    // windowBar.
    // windowBar->setIconButton(iconBtn);
    windowBar->setMinButton(minBtn);
    windowBar->setMaxButton(maxBtn);
    windowBar->setCloseButton(closeBtn);

    windowBar->setTitleLabel(titleLabel);
    windowBar->setMenuBar(menuBar);

    windowBar->setHostWidget(this);
    // windowBar->setHostWidget(m_msgWidget);

    // windowBar->setFixedHeight(24);
    windowAgent->setTitleBar(windowBar);
    // windowAgent->setSystemButton(QWK::WindowAgentBase::WindowIcon, iconBtn);
    windowAgent->setSystemButton(QWK::WindowAgentBase::Minimize, minBtn);
    windowAgent->setSystemButton(QWK::WindowAgentBase::Maximize, maxBtn);
    windowAgent->setSystemButton(QWK::WindowAgentBase::Close, closeBtn);

    windowAgent->setHitTestVisible(menuBar, true);

    // 没有 menubar 需要自己实现 窗口移动
    // windowBar->setFixedWidth(650);

    // m_layout->setMenuBar(windowBar);
    m_msgRLayout->setMenuBar(windowBar);



    // connect(iconBtn, &QAbstractButton::clicked, windowAgent, [this, iconBtn] {
    //     iconBtn->setProperty("double-click-close", false);

    //     // WindowBar's icon show a menu to choose
    //     QTimer::singleShot(75, windowAgent, [this, iconBtn]() {
    //         if (iconBtn->property("double-click-close").toBool()) {
    //             return;
    //         }
    //         windowAgent->showSystemMenu(iconBtn->mapToGlobal(QPoint(0, iconBtn->height())));
    //     });
    // });

    // connect(iconBtn, &Ttigone::WindowButton::doubleClicked, this, [iconBtn, this]() {
    //     iconBtn->setProperty("double-click-close", true);
    //     close();
    // });

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
    QFile qss(QStringLiteral(":/resources/theme/Widget/dark-style.qss"));
    qss.open(QIODevice::ReadOnly | QIODevice::Text);
    setStyleSheet(QString::fromUtf8(qss.readAll()));
    Q_EMIT themeChanged();


}

