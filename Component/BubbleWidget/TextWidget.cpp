#include "TextWidget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>


TextWidget::TextWidget(const BubbleInfo *info, QWidget *parent)
{
    m_layout = new QHBoxLayout(this);
    m_layout->setContentsMargins(QMargins());
    QTextEdit *m_textEdit = new QTextEdit(this);
    // 根据不同的发送方, 决定布局靠做还是靠右
    switch (info->getSender()) {
        case MsgSender::Client: {
            // m_textEdit->setReadOnly(true);
            // m_textEdit->setStyleSheet("border: none");
            // m_textEdit->setText(QString::fromStdString(info->getMsg()));
            // m_textEdit->setText((info->getMsg()));
            // qDebug() << QString(QString::fromStdString(info->getMsg()));
            break;
        }
        case MsgSender::Server: {
            break;
        }
        case MsgSender::System: {
            break;
        }
    }

    m_textEdit->setReadOnly(true);

    m_textEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);  // 设置大小策略，使其能够自动调整宽度
    m_textEdit->setSizeAdjustPolicy(QTextEdit::AdjustToContents);  // 设置宽度自动调整

    m_textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);  // 取消垂直滚动条
    m_textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);  // 取消水平滚动条
    m_textEdit->setAlignment(Qt::AlignCenter);

    // m_textEdit->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::LinksAccessibleByMouse);
    // m_textEdit->setAttribute(Qt::WA_TransparentForMouseEvents);

    m_textEdit->setPlainText(QString(QString::fromStdString(info->getMsg())));

    // 创建QTextDocument并设置文本内容
    QTextDocument* document = m_textEdit->document();
    document->setPlainText(m_textEdit->toPlainText());

    // 获取每行的宽度，并找到最长行的宽度
    QFontMetrics fontMetrics(document->defaultFont());
    QStringList lines = document->toPlainText().split('\n');

    int maxWidth = 0;
    for (const QString& line : lines) {
        int lineWidth = fontMetrics.horizontalAdvance(line);
        maxWidth = qMax(maxWidth, lineWidth);
    }
    int textHeight = fontMetrics.height() * lines.size();
    // 根据宽度调整QTextEdit的大小
    m_textEdit->setFixedWidth(maxWidth + 10);
    m_textEdit->setFixedHeight(textHeight + 15);


    m_labelBtn = new QPushButton();
    m_labelBtn->setStyleSheet(
        "padding: 0;"
        "border: none;"
        "background-color: transparent;"
    );
    QImage image(":/resources/Icon/sys/interface/usrPic.jpg");
    m_labelBtn->setIcon(QIcon(QPixmap::fromImage(image)));
    m_labelBtn->setFixedSize(36, 36);
    m_labelBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_labelBtn->setIconSize(QSize(34, 34));


    m_textEdit->setStyleSheet("border: none; background-color: lightgray; border-radius: 8px");


    m_layout->addStretch();

    m_layout->addWidget(m_textEdit, 0, Qt::AlignTop);
    m_layout->addWidget(m_labelBtn, 0, Qt::AlignTop);
    m_layout->addSpacerItem(new QSpacerItem(15, 1));
}

Qt::Orientation TextWidget::getOrientation()
{
    return Qt::Horizontal;
}


