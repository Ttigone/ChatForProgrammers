#ifndef MAINCHATLIST_H
#define MAINCHATLIST_H

#include <QListView>
#include <QLabel>
#include <QStyledItemDelegate>
#include <QApplication>
#include <QPainter>
#include <QMetaType>

#include "MainChatModel.h"

class LabelData;

class LabelDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    LabelDelegate(QObject *parent = nullptr);

protected:
    // 绘制
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    // 大小
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

class MainChatList : public QListView
{
    Q_OBJECT
public:
    explicit MainChatList(QWidget *parent = nullptr);
    ~MainChatList();


private:
    void init();

signals:
    void chatChanged(int64_t index);

private:
    LabelDelegate *m_labelDelegate;
    MainChatModel *m_labelModel;
};


#endif // MAINCHATLIST_H
