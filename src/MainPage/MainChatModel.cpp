#include "MainChatModel.h"
#include "MainChatList.h"
#include "Sys/CellData.h"
#include "Sys/SysConfig.h"

#include <QDateTime>
#include <QStandardItem>
#include <QVariant>



MainChatModel::MainChatModel(QObject *parent)
    : QAbstractListModel{parent}
{
    m_userMap = SysConfig::instance().getUserLabelMap();
    init();
}

MainChatModel::~MainChatModel() {}

void MainChatModel::init() {
    for (int i = 0; i < m_userMap.size(); ++i) {
        this->insertRow(i, QModelIndex());
        this->setData(this->index(i), QVariant::fromValue(m_userMap[i]), Qt::UserRole);
    }
}

int MainChatModel::rowCount(const QModelIndex &parent) const {
    // 返回行数
    return icons.size();
}

QVariant MainChatModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() > icons.size())
        return QVariant();

    if (role == Qt::UserRole) {
        CellData data;
        data.m_id = index.row();
        data.m_iconPath = icons.at(index.row());
        data.m_name = names.at(index.row());
        data.m_earilyMsg = earilyMsgs.at(index.row());

        data.m_time = m_userMap.at(index.row()).m_time;
        return QVariant::fromValue(data);
    } else {
        return QVariant();
    }
    return QVariant();
}

void MainChatModel::updateModel(const QModelIndex &index, const QDateTime &time)
{
    m_userMap[index.row()].m_time = time.toLocalTime().toString("hh:mm");
    this->setData(index, QVariant::fromValue(m_userMap.at(index.row())), Qt::UserRole);
    emit dataChanged(index, index, {Qt::UserRole});
}
