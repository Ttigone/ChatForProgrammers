#ifndef COMMUNICATIONVIEW_H
#define COMMUNICATIONVIEW_H

#include <QListWidget>

#include "BubbleWidget/Bubble/BubbleItem.h"
#include "BubbleWidget/Bubble/BubbleInfo.h"

QT_BEGIN_NAMESPACE


QT_END_NAMESPACE

class CommunicationView: public QListWidget
{
public:
    explicit CommunicationView(QWidget *parent = nullptr);


    BubbleItem *createChatRecord(std::string msg, MsgSender sender, MsgType type, QWidget *parent);
    void insertChatRecord(BubbleItem *item);

    // BubbleItem *createTimeStamp(const QDateTime &time, MsgSender sender, MsgType type, QWidget *parent);
    BubbleItem *createTimeStamp(const QDateTime &time, QWidget *parent);
    void insertTimeStamp(BubbleItem *item);


public slots:
    void receiveMsg(QString msg, const QDateTime &time);

};

#endif // COMMUNICATIONVIEW_H
