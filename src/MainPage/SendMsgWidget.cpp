#include "SendMsgWidget.h"

#include <QDateTime>
#include <QFile>

SendMsgWidget::SendMsgWidget(QWidget *parent)
    : QWidget{parent}
{
    init();
}

SendMsgWidget::~SendMsgWidget() { }

void SendMsgWidget::init() {
    m_baseLayout = new QVBoxLayout(this);
    m_baseLayout->setContentsMargins(QMargins());
    m_baseLayout->setSpacing(0);

    m_mainWidget = new QWidget;
    m_mainWidget->setObjectName(QStringLiteral("MainPage-main-Widget"));
    m_mainLayout = new QHBoxLayout(m_mainWidget);
    m_mainLayout->setContentsMargins(QMargins());
    m_mainLayout->setSpacing(0);
    m_mainLayout->addSpacerItem(new QSpacerItem(16, 1));

    m_baseLayout->addWidget(m_mainWidget);

    m_toolWidget = new QWidget;
    m_toolWidget->setObjectName(QStringLiteral("MainPage-tool-Widget"));
    m_toolLayout = new QHBoxLayout(m_toolWidget);
    m_toolLayout->setContentsMargins(QMargins());
    m_toolLayout->setSpacing(0);



    QString pixmap_url;
    QImage image;

    pixmap_url = ":/resources/Icon/sys/tool/expression.svg";
    image = QImage(pixmap_url);

    m_expressionBtn = new QPushButton;
    m_expressionBtn->setIcon(QIcon(QPixmap::fromImage(image)));
    m_expressionBtn->setIconSize(QSize(24, 22));
    m_expressionBtn->setObjectName(QStringLiteral("MainPage-expression-button"));
    pixmap_url = ":/resources/Icon/sys/tool/folder.svg";
    image = QImage(pixmap_url);
    m_folderBtn = new QPushButton;
    m_folderBtn->setIcon(QIcon(QPixmap::fromImage(image)));
    m_folderBtn->setIconSize(QSize(24, 22));
    m_folderBtn->setObjectName(QStringLiteral("MainPage-folder-button"));
    pixmap_url = ":/resources/Icon/sys/tool/screenshot.svg";
    image = QImage(pixmap_url);
    m_screenshotBtn = new QPushButton;
    m_screenshotBtn->setIcon(QIcon(QPixmap::fromImage(image)));
    m_screenshotBtn->setIconSize(QSize(24, 22));
    m_screenshotBtn->setObjectName(QStringLiteral("MainPage-screenshot-button"));
    pixmap_url = ":/resources/Icon/sys/tool/chat-history.svg";
    image = QImage(pixmap_url);
    m_chathistoryBtn = new QPushButton;
    m_chathistoryBtn->setIcon(QIcon(QPixmap::fromImage(image)));
    m_chathistoryBtn->setIconSize(QSize(24, 22));
    m_chathistoryBtn->setObjectName(QStringLiteral("MainPage-chathistory-button"));
    m_toolLayout->addWidget(m_expressionBtn);
    m_toolLayout->addSpacerItem(new QSpacerItem(8, m_toolWidget->height()));
    m_toolLayout->addWidget(m_folderBtn);
    m_toolLayout->addSpacerItem(new QSpacerItem(8, m_toolWidget->height()));
    m_toolLayout->addWidget(m_screenshotBtn);
    m_toolLayout->addSpacerItem(new QSpacerItem(8, m_toolWidget->height()));
    m_toolLayout->addWidget(m_chathistoryBtn);
    m_toolLayout->addStretch();

    m_toolWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    m_toolWidget->setFixedHeight(34);



    m_textEdit = new QTextEdit;
    m_textEdit->setStyleSheet("QTextEdit { border: none; }");
    m_textEdit->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_textEdit->setMinimumHeight(30);


    m_baseSendBtnWidget = new QWidget;
    m_baseSendBtnLayout = new QHBoxLayout(m_baseSendBtnWidget);
    m_baseSendBtnWidget->setFixedHeight(50);
    m_baseSendBtnWidget->setObjectName(QStringLiteral("MainPage-baseSendBtn-Widget"));
    m_baseSendBtnLayout->setContentsMargins(QMargins());
    m_baseSendBtnLayout->setSpacing(0);

    m_sendBtn = new QPushButton;
    m_sendBtn->setObjectName(QStringLiteral("MainPage-send-button"));
    m_sendBtn->setText(tr("发送(S)"));
    m_sendBtn->setFixedSize(100, 34);
    m_baseSendBtnLayout->addStretch();
    m_baseSendBtnLayout->addWidget(m_sendBtn);
    m_baseSendBtnLayout->addSpacerItem(new QSpacerItem(50, 1));

    m_layout = new QVBoxLayout;
    m_layout->setContentsMargins(QMargins());
    m_layout->setSpacing(0);
    m_layout->addWidget(m_toolWidget);
    m_layout->addWidget(m_textEdit);
    m_layout->addWidget(m_baseSendBtnWidget);

    m_layout->addSpacerItem(new QSpacerItem(1, 12));

    m_mainLayout->addLayout(m_layout);

    connect(m_sendBtn, &QPushButton::clicked, this, &SendMsgWidget::sendMsg);

}

void SendMsgWidget::sendMsg()
{
    if (!m_textEdit->toPlainText().isEmpty()) {
        // emit
        emit sigSendMsg(m_textEdit->toPlainText(), QDateTime::currentDateTime());
        m_textEdit->clear();
    } else {

    }
}
