#include "MainMsgBox.h"

#include <QFile>
#include <QMenu>

MainMsgBox::MainMsgBox(QWidget *parent)
    : QWidget{parent}
{
    init();
    // loadStyleSheet(Theme1::Dark);
}

MainMsgBox::~MainMsgBox() {}

void MainMsgBox::init() {
    QVBoxLayout *m_baseLayout = new QVBoxLayout(this);
    m_baseLayout->setContentsMargins(QMargins());
    m_baseLayout->setSpacing(0);

    m_layout = new QVBoxLayout();
    m_layout->setContentsMargins(QMargins());

    // 主界面
    m_mainWidget = new QWidget(this);
    m_baseLayout->addWidget(m_mainWidget);

    m_mainWidget->setLayout(m_layout);
    m_mainWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_mainWidget->setStyleSheet("background-color: #2e2e2e");

    QString pixmap_url;
    QImage image;

    pixmap_url = ":/resources/Icon/sys/interface/usrPic.jpg";
    image = QImage(pixmap_url);
    m_usrBtn= new QPushButton;
    m_usrBtn->setIcon(QIcon(QPixmap::fromImage(image)));
    m_usrBtn->setIconSize(QSize(34, 34));
    m_usrBtn->setObjectName(QStringLiteral("MainPage-usrPic-button"));
    m_usrBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_usrBtn->setMinimumSize(36, 36);
    m_usrBtn->setMaximumSize(42, 42);

    pixmap_url = ":/resources/Icon/sys/interface/chat.svg";
    image = QImage(pixmap_url);
    m_chatBtn = new QPushButton;
    m_chatBtn->setIcon(QIcon(QPixmap::fromImage(image)));
    m_chatBtn->setIconSize(QSize(24, 30));
    m_chatBtn->setObjectName(QStringLiteral("MainPage-chat-button"));
    m_chatBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_chatBtn->setMinimumSize(36, 36);
    m_chatBtn->setMaximumSize(42, 42);

    pixmap_url = ":/resources/Icon/sys/interface/friend.svg";
    image = QImage(pixmap_url);
    m_friendsBtn = new QPushButton;
    m_friendsBtn->setIcon(QIcon(QPixmap::fromImage(image)));
    m_friendsBtn->setIconSize(QSize(24, 30));
    m_friendsBtn->setObjectName(QStringLiteral("MainPage-friend-button"));
    m_friendsBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_friendsBtn->setMinimumSize(36, 36);
    m_friendsBtn->setMaximumSize(42, 42);

    pixmap_url = ":/resources/Icon/sys/interface/store.svg";
    image = QImage(pixmap_url);
    m_storeBtn = new QPushButton;
    m_storeBtn->setIcon(QIcon(QPixmap::fromImage(image)));
    m_storeBtn->setIconSize(QSize(24, 30));
    m_storeBtn->setObjectName(QStringLiteral("MainPage-store-button"));
    m_storeBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_storeBtn->setMinimumSize(36, 36);
    m_storeBtn->setMaximumSize(42, 42);

    pixmap_url = ":/resources/Icon/sys/interface/setting.svg";
    image = QImage(pixmap_url);
    m_settingBtn = new QPushButton;
    m_settingBtn->setIcon(QIcon(QPixmap::fromImage(image)));
    m_settingBtn->setIconSize(QSize(24, 30));
    m_settingBtn->setObjectName(QStringLiteral("MainPage-setting-button"));
    m_settingBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_settingBtn->setMinimumSize(36, 36);
    m_settingBtn->setMaximumSize(42, 42);

    m_layout->addSpacerItem(new QSpacerItem(0, 30));
    m_layout->addWidget(m_usrBtn, 0, Qt::AlignHCenter);
    m_layout->addSpacerItem(new QSpacerItem(0, 15));
    m_layout->addWidget(m_chatBtn, 0, Qt::AlignHCenter);
    m_layout->addSpacerItem(new QSpacerItem(0, 10));
    m_layout->addWidget(m_friendsBtn, 0, Qt::AlignHCenter);
    m_layout->addSpacerItem(new QSpacerItem(0, 10));
    m_layout->addWidget(m_storeBtn, 0, Qt::AlignHCenter);
    m_layout->addSpacerItem(new QSpacerItem(0, 50));

    m_layout->addStretch();

    m_layout->addWidget(m_settingBtn, 0, Qt::AlignHCenter);
    m_layout->addSpacerItem(new QSpacerItem(0, 10));

    m_btnGroup = new QButtonGroup;
    m_btnGroup->addButton(m_usrBtn);
    m_btnGroup->addButton(m_chatBtn);
    m_btnGroup->addButton(m_friendsBtn);
    m_btnGroup->addButton(m_storeBtn);
    m_btnGroup->addButton(m_usrBtn);

    QMenu* menu = new QMenu(m_settingBtn);
    QAction* callBack = menu->addAction(tr("意见反馈"));
    QAction* settings = menu->addAction(tr("设置"));

    QObject::connect(m_settingBtn, &QPushButton::clicked, [=]() {
        QPoint pos = m_settingBtn->mapToGlobal(QPoint(m_settingBtn->width(), -15));
        QAction *trig = menu->exec(pos);
        if (trig == callBack) {

        } else if (trig == settings) {

        }
    });

}

void MainMsgBox::loadStyleSheet(Theme1 theme) {
    if (!styleSheet().isEmpty() && theme == currentTheme) {
        return;

    }
    currentTheme = theme;
    QFile qss(QStringLiteral(":/resources/theme/MainPage/light-style.qss"));
    if (qss.open(QIODevice::ReadOnly | QIODevice::Text)) {
        setStyleSheet(QString::fromUtf8(qss.readAll()));
        qss.close();
    }
}
