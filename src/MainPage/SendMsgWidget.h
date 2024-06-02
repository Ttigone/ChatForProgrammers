#ifndef SENDMSGWIDGET_H
#define SENDMSGWIDGET_H

#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

class SendMsgWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SendMsgWidget(QWidget *parent = nullptr);
    ~SendMsgWidget();


private:
    void init();

public slots:
    void sendMsg();

signals:
    void sigSendMsg(QString msg, const QDateTime &time);

private:
    QVBoxLayout *m_baseLayout;
    QHBoxLayout *m_mainLayout;
    QWidget *m_mainWidget;

    QVBoxLayout *m_layout;

    // 工具窗口
    QWidget *m_baseToolWidget;
    QHBoxLayout *m_baseToolLayout;
    QWidget *m_toolWidget;
    QHBoxLayout *m_toolLayout;
    QPushButton *m_expressionBtn;
    QPushButton *m_folderBtn;
    QPushButton *m_screenshotBtn;
    QPushButton *m_chathistoryBtn;

    // 编辑窗口
    QTextEdit *m_textEdit;

    // 发送窗口
    QWidget *m_baseSendBtnWidget;
    QHBoxLayout *m_baseSendBtnLayout;
    QWidget *m_sendBtnWidget;
    QHBoxLayout *m_sendBtnLayout;
    QPushButton *m_sendBtn;

    // 发送时间
    QDateTime *sendMsgTime;
};

#endif // SENDMSGWIDGET_H
