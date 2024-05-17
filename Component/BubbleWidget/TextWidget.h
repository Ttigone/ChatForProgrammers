#ifndef TEXTWIDGET_H
#define TEXTWIDGET_H

#include <QWidget>

#include "Bubble/BubbleInfo.h"

QT_BEGIN_NAMESPACE

class QBoxLayout;
class QTextEdit;
class QPushButton;

QT_END_NAMESPACE

class TextWidget : public QWidget {
public:
    TextWidget(const BubbleInfo *info, QWidget *parent);

    Qt::Orientation getOrientation();


private:
    QBoxLayout *m_layout;
    QTextEdit *m_textEdit;
    QPushButton *m_labelBtn;

};

#endif // TEXTWIDGET_H
