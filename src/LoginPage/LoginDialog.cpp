#include "LoginDialog.h"
#include <QFile>
#include <unistd.h>

LoginDialog::LoginDialog(QWidget *parent)
    : QWidget{parent}
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMaximizeButtonHint);
    setFixedSize(420, 590);
    init();
    loadStyleSheet(Theme1::Dark);

}

void LoginDialog::init() {
    m_titleBarLayout = new QHBoxLayout();
    m_layout = new QVBoxLayout(this);
    m_layout->setSpacing(0);

    m_titleBar = new QWidget();
    m_titleBar->setLayout(m_titleBarLayout);
    m_titleBar->setFixedHeight(30);

    m_iconLabel = new QPushButton;
    m_iconLabel->setObjectName(QStringLiteral("Login-icon-button"));
    m_iconLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_iconLabel->setIconSize(QSize(25, 25));

    m_minBtn = new QPushButton;
    m_minBtn->setObjectName(QStringLiteral("Login-min-button"));
    m_minBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    m_closeBtn = new QPushButton;
    m_closeBtn->setObjectName(QStringLiteral("Login-close-button"));
    m_closeBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    m_titleBarLayout->addWidget(m_iconLabel);
    m_titleBarLayout->addStretch();
    m_titleBarLayout->addWidget(m_minBtn);
    m_titleBarLayout->addWidget(m_closeBtn);
    // 四周边距为 0
    m_titleBarLayout->setContentsMargins(QMargins());
    // 控件间隙为 0
    m_titleBarLayout->setSpacing(0);


    // m_layout->setMenuBar(m_titleBar);
    m_usrLineEdit = new QtMaterialTextField();
    m_usrLineEdit->setMaximumWidth(400);
    m_pwdLineEdit = new QtMaterialTextField();
    m_pwdLineEdit->setMaximumWidth(400);


    m_imgLabel = new QLabel();
    m_imgLabel->setPixmap(QPixmap::fromImage(QImage(":/resources/windowbar/app/chat.png")).scaled(100, 100));
    m_imgLabel->setMaximumSize(100, 100);

    m_loginBtn = new QtMaterialRaisedButton(tr("登录"));
    m_loginBtn->setObjectName(QStringLiteral("Login-login-button"));
    m_loginBtn->setMinimumSize(250, 30);
    m_loginBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_switchUsrBtn = new QtMaterialRaisedButton(tr("切换"));
    m_switchUsrBtn->setObjectName(QStringLiteral("Login-switchUsr-button"));
    m_switchUsrBtn->setMinimumSize(40, 30);
    m_switchUsrBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);


    // 标题栏
    m_layout->setMenuBar(m_titleBar);

    QVBoxLayout *operateLatout = new QVBoxLayout;

    operateLatout->addSpacerItem(new QSpacerItem(0, 80));

    operateLatout->addWidget(m_imgLabel, 0, Qt::AlignHCenter);
    // usr edit
    operateLatout->addSpacerItem(new QSpacerItem(0, 10));

    operateLatout->addWidget(m_usrLineEdit, 0, Qt::AlignHCenter);

    operateLatout->addSpacerItem(new QSpacerItem(0, 8));
    // pwd edit
    operateLatout->addWidget(m_pwdLineEdit, 0, Qt::AlignHCenter);

    operateLatout->addSpacerItem(new QSpacerItem(0, 10));

    operateLatout->addWidget(m_loginBtn, 0, Qt::AlignHCenter);

    operateLatout->addSpacerItem(new QSpacerItem(0, 40));

    operateLatout->addWidget(m_switchUsrBtn, 0, Qt::AlignHCenter);
    operateLatout->addSpacerItem(new QSpacerItem(0, 40));

    m_layout->addLayout(operateLatout);

    m_iconLabel->installEventFilter(this);

    connect(m_loginBtn, &QPushButton::pressed, this, [this]() {
        m_isDrag = true;
        emit needLogin();
    });
    connect(m_switchUsrBtn, &QPushButton::pressed, this, [this](){
        m_isDrag = true;
        emit needSwitchUsr();
    });
    connect(m_minBtn, &QPushButton::pressed, this, [this](){
        m_isDrag = true;
        this->showMinimized();
    });
    connect(m_closeBtn, &QPushButton::pressed, this, [this](){
        m_isDrag = true;
        this->close();
    });
}

void LoginDialog::mouseDoubleClickEvent(QMouseEvent *event) {

}

void LoginDialog::mouseMoveEvent(QMouseEvent *event) {
    if (m_isDrag) {
        event->ignore();
        return;
    }
    if (event->buttons() == Qt::LeftButton) {
        move(event->globalPosition().x() - m_clickPx, event->globalPosition().y() - m_clickPy);
        event->accept();
    }
}

void LoginDialog::mousePressEvent(QMouseEvent *event) {
    auto winPx = event->pos().x();
    auto winPy = event->pos().y();

    // if (m_loginBtn->pressed()) {
    //     m_notMove = true;
    //     qDebug() << "isD";
    // }
    // if ((winPx >= m_loginBtn->geometry().x()) && (winPx <= (m_loginBtn->geometry().x() + m_loginBtn->width()))) {
    //     if ((winPy >= m_loginBtn->geometry().y()) && (winPy <= (m_loginBtn->geometry().y() + m_loginBtn->height()))) {
    //         // 处于 loginBtn 控件内按下 不需要移动事件
    //         qDebug() << "in";
    //         m_notMove = true;
    //         event->accept();
    //         return;
    //     }
    // }
    // if ((winPx >= m_switchUsrBtn->geometry().x()) && (winPx <= (m_switchUsrBtn->geometry().x() + m_switchUsrBtn->width()))) {
    //     if ((winPy >= m_switchUsrBtn->geometry().y()) && (winPy <= (m_switchUsrBtn->geometry().y() + m_switchUsrBtn->height()))) {
    //         // 处于 loginBtn 控件内 不需要移动事件
    //         m_notMove = true;
    //         return;
    //     }
    // }
    // 相对于屏幕的坐标
    m_globalPx = event->globalPosition().x();
    m_globalPy = event->globalPosition().x();

    // 窗口左上角的坐标
    m_delPx = m_globalPx - winPx;
    m_delPy = m_globalPy - winPy;

    m_clickPx = m_globalPx - m_delPx;
    m_clickPy = m_globalPy - m_delPy;

    // 开启移动事件
    event->accept();
}

void LoginDialog::mouseReleaseEvent(QMouseEvent *event) {
    m_isDrag = false;
    event->accept();
}

bool LoginDialog::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == m_iconLabel) {
        if (event->type() == QEvent::MouseButtonPress) {
            event->ignore();
            return true;
        } else {
            return false;
        }
    } else {
        return QWidget::eventFilter(watched, event);
    }
    // return true;
    // return false;
}

void LoginDialog::loadStyleSheet(Theme1 theme) {
    if (!styleSheet().isEmpty() && theme == currentTheme) {
        return;

    }
    currentTheme = theme;
    QFile qss(QStringLiteral(":/resources/theme/Login/dark-style.qss"));
    if (qss.open(QIODevice::ReadOnly | QIODevice::Text)) {
        setStyleSheet(QString::fromUtf8(qss.readAll()));
        qss.close();
    }
}

