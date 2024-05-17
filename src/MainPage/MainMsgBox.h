#ifndef MAINMSGBOX_H
#define MAINMSGBOX_H

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QButtonGroup>

class MainMsgBox : public QWidget
{
    Q_OBJECT

public:
    explicit MainMsgBox(QWidget *parent = nullptr);
    ~MainMsgBox();

public:
    enum Theme1 {
        Dark,
        Light,
    };
    Q_ENUM(Theme1)

    void init();

private:
    void loadStyleSheet(Theme1 theme);

private:
    Theme1 currentTheme;
    QVBoxLayout *m_baseLayout;
    QVBoxLayout *m_layout;
    QWidget *m_mainWidget;

    QButtonGroup *m_btnGroup;
    QPushButton *m_usrBtn;

    QPushButton *m_chatBtn;
    QPushButton *m_friendsBtn;
    QPushButton *m_storeBtn;

    QPushButton *m_settingBtn;


};

#endif // MAINMSGBOX_H
