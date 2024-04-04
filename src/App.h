#ifndef APP_H
#define APP_H

#include <QVBoxLayout>
#include <QWidget>
#include <QWKWidgets/widgetwindowagent.h>



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

    void showCenter();

Q_SIGNALS:
    void themeChanged();

private:
    void installWindowAgent();
    void loadStyleSheet(Theme theme);

private:
    QWK::WidgetWindowAgent *windowAgent;
    QVBoxLayout *m_layout;

    Theme currentTheme;


};
#endif // APP_H
