#include "BubbleItem.h"

#include "../TextWidget.h"
#include "../TimeWidget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <iostream>

BubbleItem::BubbleItem(QWidget *parent)
    : QWidget(parent),
    m_layout(nullptr),
    m_label(nullptr),
    m_name(nullptr),
    m_item(nullptr)
{
    this->setStyleSheet("background-color:#ffffff");
    this->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_layout = new QHBoxLayout(this);
    m_layout->setContentsMargins(QMargins());
    m_item = new QWidget;
}

BubbleItem::BubbleItem(const BubbleInfo *info, QWidget *parent)
    : BubbleItem(parent)
{
    switch (info->getType()) {
        case MsgType::Text: {
            m_item = new TextWidget(info, this);
            break;
        }
        case MsgType::File: {
            break;
        }
        case MsgType::Picture: {
            break;
        }
    }

    if (info->getSender() == MsgSender::Client) {
        m_layout->addStretch();
        m_layout->addWidget(m_item);
    }
    this->setLayout(m_layout);
}

BubbleItem::BubbleItem(std::string msg, MsgSender sender, MsgType type, QWidget *parent)
    : BubbleItem(parent)
{
    if (type == MsgType::Text) {
        // std::cout << "sssdasdsadsada" << msg;
        m_item = new TextWidget(new BubbleInfo(msg, sender, type, parent), this);
    }
    if (sender == MsgSender::Client) {
        m_layout->addStretch();
        m_layout->addWidget(m_item);
    }
    this->setLayout(m_layout);
}

BubbleItem::BubbleItem(const QDateTime &time, QWidget *parent)
    : BubbleItem(parent)
{
    // m_item
    m_item = new TimeWidget(time, this);
    m_layout->addStretch();
    m_layout->addWidget(m_item);
    m_layout->addStretch();
    this->setLayout(m_layout);
}
