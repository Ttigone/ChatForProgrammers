#include "BubbleInfo.h"

BubbleInfo::BubbleInfo(QObject *parent)
    : QObject(parent)
{
}

BubbleInfo::BubbleInfo(std::string msg, MsgSender sender, MsgType type, QObject *parent)
    : QObject(parent),
    m_msg(msg),
    m_msgSender(sender),
    m_msgType(type)
{
}

void BubbleInfo::setType(MsgType type)
{
    m_msgType = type;
}

MsgType BubbleInfo::getType() const
{
    return m_msgType;
}

void BubbleInfo::setSender(MsgSender sender)
{
    m_msgSender = sender;
}

MsgSender BubbleInfo::getSender() const
{
    return m_msgSender;
}

void BubbleInfo::setMsg(std::string msg)
{
    m_msg = msg;
}

std::string BubbleInfo::getMsg() const
{
    return m_msg;
}

