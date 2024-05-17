#ifndef BUBBLEINFO_H
#define BUBBLEINFO_H

#include <QWidget>
// #include <string>

#include "../../ComApi/unit.h"

class BubbleInfo : public QObject {
public:
    BubbleInfo(QObject *parent);
    explicit BubbleInfo(std::string msg, MsgSender sender, MsgType type, QObject *parent);

    void setType(MsgType type);
    MsgType getType() const;

    void setSender(MsgSender sender);
    MsgSender getSender() const;

    void setMsg(std::string msg);
    std::string getMsg() const;


    void setSender();
private:
    MsgType m_msgType;
    MsgSender m_msgSender;

    std::string m_msg;
    // Msg
};

#endif // BUBBLEINFO_H
