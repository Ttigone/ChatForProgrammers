#ifndef APP_H
#define APP_H

#include <QVBoxLayout>
#include <QWidget>
#include <QWKWidgets/widgetwindowagent.h>
#include "WidgetFrame/windowbar.h"
#include "WidgetFrame/windowbutton.h"

#include "MainPage/MainMsgBox.h"
#include "MainPage/MainChatList.h"
#include "MainPage/SearchWidget.h"
#include "MainPage/MainMsgWidget.h"
#include "MainPage/CommunicationView.h"
#include "MainPage/SendMsgWidget.h"


QT_BEGIN_NAMESPACE

class QListWidget;
class QStackedLayout;

QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    enum Theme {
        Dark,
        Light,
    };

    Q_ENUM(Theme)

    void init();

    void showCenter();

Q_SIGNALS:
    void themeChanged();

private:
    void installWindowAgent();
    void loadStyleSheet(Theme theme);

public slots:
    // void updateMsgFromInput();

private:
    QWK::WidgetWindowAgent *windowAgent;
    QVBoxLayout *m_layout;


    QHBoxLayout *m_mainLayout;

    MainMsgBox *m_msgBox;

    QWidget *m_msgLWidget;
    QVBoxLayout *m_msgLLayout;

    SearchWidget *m_searchWidget;
    MainChatList *m_msgList;

    QVBoxLayout *m_msgRLayout;
    QWidget *m_msgRWidget;


    QStackedLayout *m_stackLayout;
    MainMsgWidget *m_mainMsgWidget;
    // CommunicationView *m_communicationList;


    // SendMsgWidget *m_sendMsgWidget;

    Theme currentTheme;


};
#endif // APP_H
