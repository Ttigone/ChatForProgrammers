#include "CommunicationView.h"

#include <QDateTime>
#include <QTextEdit>
#include <iostream>


CommunicationView::CommunicationView(QWidget *parent)
    : QListWidget(parent)
{
    // 设置间隙
    this->setSpacing(8);

    this->setStyleSheet("QListWidget::item:hover { background-color: none; }");
    this->setStyleSheet("border: none;");
    this->setSelectionMode(QAbstractItemView::ExtendedSelection);

}

BubbleItem *CommunicationView::createChatRecord(std::string msg, MsgSender sender, MsgType type, QWidget *parent)
{
    return new BubbleItem(msg, sender, type, parent);
}

void CommunicationView::insertChatRecord(BubbleItem *item)
{
    QListWidgetItem *newItem = new QListWidgetItem("");
    newItem->setSizeHint(item->sizeHint());
    this->addItem(newItem);
    this->setItemWidget(newItem, item);
}

BubbleItem *CommunicationView::createTimeStamp(const QDateTime &time, QWidget *parent)
{
    return new BubbleItem(time, parent);
}

void CommunicationView::insertTimeStamp(BubbleItem *item)
{
    QListWidgetItem *newItem = new QListWidgetItem("");
    newItem->setSizeHint(item->sizeHint());
    this->addItem(newItem);
    this->setItemWidget(newItem, item);
}

void CommunicationView::receiveMsg(QString msg, const QDateTime &time)
{
    insertTimeStamp(createTimeStamp(time, this));

    insertChatRecord(createChatRecord(std::string(msg.toStdString()), MsgSender::Client, MsgType::Text, this));

}
