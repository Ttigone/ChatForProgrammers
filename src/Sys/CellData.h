#ifndef CELLDATA_H
#define CELLDATA_H

#include <QObject>

QT_BEGIN_NAMESPACE


QT_END_NAMESPACE

class CellData
{
public:
    CellData() { };
    CellData(int64_t id, QString iconPath, QString name, QString earilyMsg, QString time)
        : m_id(id), m_iconPath(iconPath), m_name(name), m_earilyMsg(earilyMsg), m_time(time)
    {

    }
    int64_t m_id;                 // id 号
    QString m_iconPath;         // 图标路径
    QString m_name;             // 名称
    QString m_earilyMsg;        // 最近消息
    QString m_time;             // 最近聊天时间
};

// 声明自定义类型
Q_DECLARE_METATYPE(CellData)

#endif // CELLDATA_H
