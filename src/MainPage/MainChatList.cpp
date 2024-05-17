#include "MainChatList.h"
#include "MainChatModel.h"
#include "Sys/CellData.h"

#include <QStringListModel>
#include <QVariant>
#include <QPainterPath>

LabelDelegate::LabelDelegate(QObject *parent) { }

void LabelDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    if (index.isValid()) {
        painter->save();
        QVariant var = index.data(Qt::UserRole);
        // 获取自定义数据
        CellData data = var.value<CellData>();

        QRectF rect;
        rect.setX(option.rect.x());
        rect.setY(option.rect.y());
        rect.setWidth(option.rect.width() - 1);
        rect.setHeight(option.rect.height() - 1);

        QPainterPath path;
        path.moveTo(rect.topLeft());
        path.lineTo(rect.topRight());
        path.quadTo(rect.topRight(), rect.topRight());
        path.lineTo(rect.bottomRight());
        path.quadTo(rect.bottomRight(), rect.bottomRight());
        path.lineTo(rect.bottomLeft());
        path.quadTo(rect.bottomLeft(), rect.bottomLeft());
        path.lineTo(rect.topLeft());
        path.quadTo(rect.topLeft(), rect.topLeft());

        // 当前被选中
        if (option.state.testFlag(QStyle::State_Selected)) {
            painter->setPen(QPen(QColor("#e3e3e5")));
            painter->setBrush(QBrush(QColor("#e3e3e5")));
            painter->drawPath(path);
        }
        // 鼠标移动到上面
        if (option.state.testFlag(QStyle::State_MouseOver)) {
            painter->setPen(QPen(QColor("#ebeced")));
            painter->setBrush(QBrush(QColor("#ebeced")));
            painter->drawPath(path);
        }

        // 设定图片, 名称, 最新消息, 时间 的位置
        QRectF iconRect = QRectF(rect.x() + 6, rect.y() + 11, 35, 35);
        QRectF nameRect = QRectF(iconRect.right() + 3, iconRect.top() - 3, rect.width() - 36, 20);
        QRectF msgRect = QRectF(nameRect.x(), nameRect.bottom() + 3, nameRect.width() - 36, 20);
        QRectF timeRect = QRectF(rect.width() - 30, iconRect.top(), 30,20);

        // 绘制图片
        painter->drawImage(iconRect, QImage(data.m_iconPath));
        // painter->drawPixmap(iconRect.topLeft(), QPixmap::fromImage((QImage(data.m_iconPath))));
        // painter->drawPicture(iconRect.topLeft(), QPicture::)

        // 绘制名称
        painter->setPen(QPen(Qt::black));
        painter->setFont(QFont("Microsoft YaHei", 10));
        painter->drawText(nameRect, data.m_name);

        // 绘制最新消息
        painter->setPen(QPen(Qt::gray));
        painter->drawText(msgRect, data.m_earilyMsg);

        // 绘制时间
        painter->setPen(QPen(Qt::red));
        painter->drawText(timeRect, data.m_time);

        painter->restore();
    }
}

QSize LabelDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const {
    Q_UNUSED(index);
    // 指定返回的大小
    // return QSize(option.rect.width(), 40);
    return QSize(200, 58);
}

MainChatList::MainChatList(QWidget *parent)
    : QListView(parent)
{
    init();

    // connect(this, &QListView::clicked, [this](const QModelIndex& index) {
    //     // 获取点击项的索引
    //     if (index.isValid()) {
    //         if (index != currentIndex()) {
    //             // 切换
    //             CellData q = qvariant_cast<CellData>(this->model()->data(index, Qt::UserRole));
    //             emit chatChanged(q.m_id);
    //         } else {

    //         }
    //     }
    // });

}

MainChatList::~MainChatList() {
}

void MainChatList::init() {
    m_labelDelegate = new LabelDelegate(this);
    this->setItemDelegate(m_labelDelegate);
    m_labelModel = new MainChatModel;
    this->setModel(m_labelModel);

}
