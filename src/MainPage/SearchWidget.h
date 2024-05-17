#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QHBoxLayout>
#include <QPushButton>
#include <QWidget>
#include "qt-material/components/qtmaterialautocomplete.h"

class QtMaterialAutoComplete;
class AutoCompleteSettingsEditor;

class SearchWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SearchWidget(QWidget *parent = nullptr);

private:
    void init();

private:
    QHBoxLayout                  *m_layout;
    QHBoxLayout                  *m_baselayout;
    QWidget                      *m_baseWidget;
    QPushButton                  *m_addMsgBtn;
    QtMaterialAutoComplete       *const m_searchEditor;
};


// class AutoCompleteSettingsEditor : public QWidget
// {
//     Q_OBJECT

// public:
//     explicit AutoCompleteSettingsEditor(QWidget *parent = 0);
//     ~AutoCompleteSettingsEditor();

// protected slots:
//     void setupForm();
//     void updateWidget();
//     void selectColor();

// private:
// };


#endif // SEARCHWIDGET_H
