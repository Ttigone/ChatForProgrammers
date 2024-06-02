#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <QDir>

class Utils
{
public:


    static bool mkDirs(QString dirPath){
        QDir dir(dirPath);
        if(dir.exists()){
          return true;
        }else{
           bool result = dir.mkpath(dirPath);//创建多级目录
           return result;
        }
    }
};

#endif // UTILS_H
