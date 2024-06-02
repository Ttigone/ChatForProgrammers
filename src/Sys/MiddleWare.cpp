#include "MiddleWare.h"
#include "CellData.h"
#include "MainPage/MainMsgWidget.h"

#include <QDateTime>
#include <QListView>
#include <QStackedLayout>
#include <unordered_map>

#include <MainPage/MainChatModel.h>

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
            // 切换
            CellData q = qvariant_cast<CellData>(view->model()->data(index, Qt::UserRole));
            if (map.find(q.m_id) == map.end()) {
                map[q.m_id] = onlineUser();
            }
            if (!layout->itemAt(map[q.m_id])) {
                auto i = new MainMsgWidget(q);

                // qDebug() << "sss: index : " << index.row();
                connect(i, &MainMsgWidget::updateTimeStamp, [view, index](const QDateTime &time) {
                    // view->model();
                    // (MainChatModel)view->model();
                    MainChatModel *model = qobject_cast<MainChatModel *>(view->model());
                    model->updateModel(index, time);
                });

                layout->insertWidget(map[q.m_id], i);
                // layout->insertWidget(q.m_id, new MainMsgWidget(q));
                // layout->setCurrentIndex(q.m_id);
                layout->setCurrentIndex(map[q.m_id]);
            } else {
                layout->setCurrentIndex(map[q.m_id]);
            }
        }
    });
}

void MiddleWare::searchStackWidget(int64_t index, QStackedLayout *layout)
{
    // if (layout->currentIndex() != index)
    // 没有这个用户聊天, 需要添加对应的窗口  新用户
}
