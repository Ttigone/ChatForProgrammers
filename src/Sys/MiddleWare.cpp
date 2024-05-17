#include "MiddleWare.h"
#include "CellData.h"
#include "MainPage/MainMsgWidget.h"

#include <QListView>
#include <QStackedLayout>
#include <unordered_map>>

MiddleWare &MiddleWare::instance()
{
    static MiddleWare singleton;
    return singleton;
}

MiddleWare::MiddleWare()
{
}

std::unordered_map<int64_t, int64_t>::size_type MiddleWare::onlineUser()
{
    return map.size();
}

void MiddleWare::installListenerService(QListView *view, QStackedLayout *layout)
{
    connect(view, &QListView::clicked, [view, layout, this](const QModelIndex &index) {
        if (index.isValid()) {
            // if (index != view->currentIndex()) {
                qDebug() << "cl";
                // 切换
                CellData q = qvariant_cast<CellData>(view->model()->data(index, Qt::UserRole));
                // qDebug() << "id" << q.m_id;
                // qDebug() << "name" << q.m_name;
                // map[q.m_id] = 1;
                // if (map.empty()) {

                // }
                // map[q.m_id] = 0;
                if (map.find(q.m_id) == map.end()) {
                    map[q.m_id] = onlineUser();
                }
                if (!layout->itemAt(map[q.m_id])) {
                    // qDebug() << "id: " << q.m_id;
                    // qDebug() << "c";
                    // map[q.m_id] = 0;
                    layout->insertWidget(map[q.m_id], new MainMsgWidget(q));
                    // layout->insertWidget(q.m_id, new MainMsgWidget(q));
                    // layout->setCurrentIndex(q.m_id);
                    layout->setCurrentIndex(map[q.m_id]);
                } else {
                    // qDebug() << "t";
                    layout->setCurrentIndex(map[q.m_id]);
                }

            // } else {

            // }
        }
    });
}

void MiddleWare::searchStackWidget(int64_t index, QStackedLayout *layout)
{
    // if (layout->currentIndex() != index)
    // 没有这个用户聊天, 需要添加对应的窗口  新用户
}
