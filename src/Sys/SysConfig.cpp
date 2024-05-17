#include "SysConfig.h"

SysConfig &SysConfig::instance()
{
    static SysConfig singleton;
    return singleton;
}

SysConfig::SysConfig() {

    for (int i = 0; i < 2; ++i) {
        m_userMap.insert(std::pair(i, CellData(i, icons[i], names[i], earilyMsgs[i], times[i])));
    }
}
