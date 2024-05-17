#include "MainChatModel.h"
#include "MainChatList.h"
#include "Sys/CellData.h"
#include "Sys/SysConfig.h"

#include <QStandardItem>
#include <QVariant>



MainChatModel::MainChatModel(QObject *parent)
    : QAbstractListModel{parent}
{
    m_userMap = SysConfig::instance().getUserLabelMap();
    // m_userMap = new std::map<int64_t, LabelData>;
    // 插入数据
    // for (int i = 0; i < 2; ++i) {
    //     // LabelData data;
    //     // data.m_iconPath =
    //     m_userMap.insert(std::pair(i, CellData(i, icons[i], names[i], earilyMsgs[i], times[i])));
    // }

    init();
}

MainChatModel::~MainChatModel() {}

void MainChatModel::init() {
    // for (int i = 0; i < m_userMap.size(); ++i) {
    // for (int i = 0; i < SysConfig::getUserLabelMap().size(); ++i) {
    for (int i = 0; i < m_userMap.size(); ++i) {
        this->insertRow(i, QModelIndex());
        // this->setData(this->index(i), QVariant::fromValue(SysConfig::getUserLabelMap()[i]), Qt::UserRole);
        // this->setData(this->index(i), QVariant::fromValue(map.getUserLabelMap()[i]), Qt::UserRole);
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
        data.m_time = times.at(index.row());
        return QVariant::fromValue(data);
    } else {
        return QVariant();
    }
    return QVariant();
}
