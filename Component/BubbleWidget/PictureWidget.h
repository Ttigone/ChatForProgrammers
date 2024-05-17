#ifndef PICTUREWIDGET_H
#define PICTUREWIDGET_H

#include <QWidget>
#include <QLabel>

QT_BEGIN_NAMESPACE


QT_END_NAMESPACE

class PictureWidget : public QLabel {
public:
    PictureWidget(QWidget *parent);
};

#endif // PICTUREWIDGET_H
