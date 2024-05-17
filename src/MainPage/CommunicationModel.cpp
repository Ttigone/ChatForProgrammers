#include "CommunicationModel.h"
#include "CommunicationView.h"

const QStringList icons = {
    ":/resources/Icon/sys/tool/file_transfer.svg",
    ":/resources/Icon/sys/interface/usrPic.jpg"
};

const QStringList earilyMsgs = {
    "测试1", "测试2"
};

const QStringList times = {
    "1-1", "2-2", "3-3"
};

const QStringList pics = {
    ":/resources/Icon/sys/tool/file_transfer.svg",
    ":/resources/Icon/sys/interface/usrPic.jpg"
};

const QStringList dirs = {
    ""
};

CommunicationModel::CommunicationModel(QObject *parent)
    : QAbstractListModel{parent}
{
    init();
}

CommunicationModel::~CommunicationModel() { }

int CommunicationModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent)
    return earilyMsgs.size();
}

QVariant CommunicationModel::data(const QModelIndex &index, int role) const {
    // if (!index.isValid() || index.row() > earilyMsgs.size())
    //     return QVariant();
    // // if (role == Qt::DisplayRole || role == Qt::EditRole) {
    //     // return names.at(index.row());
    // if (role == Qt::EditRole || role == Qt::DisplayRole) {
    //     CommunicationData data;
    //     data.m_word = earilyMsgs.at(index.row());
    //     // qDebug() << data.m_word;
    //     // data.m_iconPath = icons.at(index.row());
    //     return QVariant::fromValue(data);
    // } else {
    //     return QVariant();
    // }
    return QVariant();
}

void CommunicationModel::init() {
    // for (int i = 0; i < earilyMsgs.size(); ++i) {
    //     CommunicationData data;
    //     data.m_word = earilyMsgs.at(i);
    //     qDebug() << data.m_word;
    //     // data.m_iconPath = icons.at(i);
    //     // data.m_time = times.at(i);
    //     // data.m_pic = pics.at(i);
    //     // data.m_dir = dirs.at(i);
    //     if (this->insertRow(i, QModelIndex())) {
    //         qDebug() << "tr";
    //     } else {
    //         qDebug() << "error";
    //     }
    //     if (this->setData(this->index(i), QVariant::fromValue(data), Qt::EditRole)) {
    //         qDebug() << "true";
    //     } else {
    //         qDebug() << "false";
    //     }
    // }
    // qDebug() << this->rowCount();
    int row = earilyMsgs.size();
    beginInsertRows(QModelIndex(), row, row);
    endInsertRows();
}
