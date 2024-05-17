#ifndef MAINMSGWIDGET_H
#define MAINMSGWIDGET_H

#include <QWidget>

#include "CommunicationView.h"
#include "SendMsgWidget.h"
#include "Sys/CellData.h"

QT_BEGIN_NAMESPACE

class QBoxLayout;
class QLabel;

QT_END_NAMESPACE

class MainMsgWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainMsgWidget(const CellData &data, QWidget *parent = nullptr);

private:
    void init(const CellData &data);

private:
    QBoxLayout *m_layout;

    QWidget *m_labelWidget;
    QBoxLayout *m_labellayout;
    QLabel *m_label;

    CommunicationView *m_communicationList;
    SendMsgWidget *m_sendMsgWidget;
};

#endif // MAINMSGWIDGET_H
