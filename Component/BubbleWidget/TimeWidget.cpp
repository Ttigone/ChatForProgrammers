#include "TimeWidget.h"

#include <QDateTime>
#include <QHBoxLayout>
#include <QLabel>

TimeWidget::TimeWidget(const QDateTime &time, QWidget *parent)
    : QWidget(parent)
{
    m_layout = new QHBoxLayout(this);
    m_layout->setContentsMargins(QMargins());

    QLabel *m_timeLabel = new QLabel();

    m_timeLabel->setText(time.toLocalTime().toString("hh:mm"));
    // m_timeLabel->setFont(QFont(""));
    m_timeLabel->setStyleSheet("background-color: #dadada");

    m_layout->addWidget(m_timeLabel);
}
