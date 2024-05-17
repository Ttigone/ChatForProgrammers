#ifndef MIDDLEWARE_H
#define MIDDLEWARE_H

#include <QObject>
#include <unordered_map>

QT_BEGIN_NAMESPACE

class QListView;
class QStackedLayout;

QT_END_NAMESPACE

class MiddleWare : QObject
{
    Q_OBJECT
public:
    static MiddleWare &instance();

    // 转发 切换不同聊天 的事件
    void installListenerService(QListView *view, QStackedLayout *layout);

private:
    MiddleWare();

    std::unordered_map<int64_t, int64_t>::size_type onlineUser();

private slots:
    void searchStackWidget(int64_t index, QStackedLayout *layout);

private:
    // 映射表
    std::unordered_map<int64_t, int64_t> map;
};

#endif // MIDDLEWARE_H
