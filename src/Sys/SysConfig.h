#ifndef SYSCONFIG_H
#define SYSCONFIG_H

#include <map>
#include "CellData.h"


const QStringList icons = {
    ":/resources/Icon/sys/tool/file_transfer.svg",
    ":/resources/Icon/sys/interface/usrPic.jpg"
    // ":/resources/Icon/sys/interface/friend.svg",
    // ":/resources/Icon/sys/interface/setting.svg"
};

const QStringList names = {
    "文件传输助手", "硝子"
};

const QStringList earilyMsgs = {
    "1", "2"
};

const QStringList times = {
    "", ""
};



class SysConfig
{
public:
    static SysConfig &instance();

    void insertUserLabelMsg(int64_t index, CellData data) {
        m_userMap.insert(std::pair(index, data));
    }

    std::map<int64_t, CellData> getUserLabelMap() {
        return m_userMap;
    }
private:
    SysConfig();


    std::map<int64_t, CellData> m_userMap;


};

#endif // SYSCONFIG_H
