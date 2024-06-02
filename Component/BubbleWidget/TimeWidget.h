#ifndef TIMEWIDGET_H
#define TIMEWIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE

class QBoxLayout;
class QLabel;

QT_END_NAMESPACE

class TimeWidget : public QWidget
{
public:
    TimeWidget(const QDateTime &time, QWidget *parent);

private:
    QBoxLayout *m_layout;
    QLabel *m_timeLabel;
};

#endif // TIMEWIDGET_H
