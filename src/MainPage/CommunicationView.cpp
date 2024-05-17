#include "CommunicationView.h"

#include <QTextEdit>
#include <iostream>


CommunicationView::CommunicationView(QWidget *parent)
    : QListWidget(parent)
{
    // 设置间隙
    this->setSpacing(8);

    this->setStyleSheet("QListWidget::item:hover { background-color: none; }");
    this->setStyleSheet("border: none;");

    // BubbleItem *q = createChatRecord(std::string("测试奇偶"), MsgSender::Client, MsgType::Text, this);
    // insertChatRecord(q);

    // BubbleItem *q1 = createChatRecord(std::string("使得撒\n\n\n\n\n\n\n旦撒旦萨东盛科技"), MsgSender::Client, MsgType::Text, this);
    // insertChatRecord(q1);

}

BubbleItem *CommunicationView::createChatRecord(std::string msg, MsgSender sender, MsgType type, QWidget *parent)
{
    return new BubbleItem(msg, sender, type, parent);
}

void CommunicationView::insertChatRecord(BubbleItem *i)
{
    QListWidgetItem *item = new QListWidgetItem("");
    item->setSizeHint(i->sizeHint());
    this->addItem(item);
    this->setItemWidget(item, i);
}

void CommunicationView::receiveMsg(QString msg)
{
    BubbleItem *item = createChatRecord(std::string(msg.toStdString()), MsgSender::Client, MsgType::Text, this);
    insertChatRecord(item);
}
