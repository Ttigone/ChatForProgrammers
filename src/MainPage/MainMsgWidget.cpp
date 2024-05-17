#include "MainMsgWidget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QSplitter>

MainMsgWidget::MainMsgWidget(const CellData &data, QWidget *parent)
    : QWidget{parent}
{
    init(data);
}

void MainMsgWidget::init(const CellData &data)
{
    // 标签
    m_labelWidget = new QWidget;
    m_labelWidget->setObjectName(QStringLiteral("MainPage-label-Widget"));
    m_labelWidget->setFixedHeight(42);
    m_labellayout = new QHBoxLayout;
    m_labellayout->setContentsMargins(QMargins());
    m_labelWidget->setLayout(m_labellayout);
    m_label = new QLabel;
    m_label->setText(data.m_name);
    m_label->setFont(QFont("微软雅黑", 18));
    m_labellayout->addSpacerItem(new QSpacerItem(20, 1));
    m_labellayout->addWidget(m_label);


    m_communicationList = new CommunicationView;
    m_sendMsgWidget = new SendMsgWidget;

    QSplitter *splitter2 = new QSplitter(Qt::Vertical);
    QList<int> sizes2;
    sizes2 << 420 << 200;

    splitter2->addWidget(m_communicationList);

    splitter2->addWidget(m_sendMsgWidget);

    splitter2->setSizes(sizes2);
    splitter2->setCollapsible(0, false);
    splitter2->setCollapsible(1, false);
    splitter2->setHandleWidth(1);

    m_layout = new QVBoxLayout(this);
    m_layout->setContentsMargins(QMargins());
    m_layout->setSpacing(0);
    m_layout->addWidget(m_labelWidget);
    m_layout->addWidget(splitter2);

    connect(m_sendMsgWidget, &SendMsgWidget::sigSendMsg, m_communicationList, &CommunicationView::receiveMsg);

}

