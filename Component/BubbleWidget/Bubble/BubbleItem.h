#ifndef BUBBLEITEM_H
#define BUBBLEITEM_H

#include <QWidget>

#include "BubbleInfo.h"

QT_BEGIN_NAMESPACE

class QBoxLayout;
class QLabel;

QT_END_NAMESPACE

class BubbleItem : public QWidget {
public:
    BubbleItem(QWidget *parent = nullptr);
    BubbleItem(const BubbleInfo *info, QWidget *parent);
    BubbleItem(std::string msg, MsgSender sender, MsgType type, QWidget *parent);
    BubbleItem(const QDateTime &time, QWidget *parent);

private:
    QBoxLayout *m_layout;
    QLabel *m_label;
    QLabel *m_name;
    QWidget *m_item;

};

#endif // BUBBLEITEM_H
