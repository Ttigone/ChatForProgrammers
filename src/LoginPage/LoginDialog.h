#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QWidget>
#include <QMouseEvent>
#include <QMoveEvent>
#include <QEvent>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include "../lib/qt-material/components/qtmaterialtextfield.h"
#include "../lib/qt-material/components/qtmaterialraisedbutton.h"

class LoginDialog : public QWidget
{
    Q_OBJECT
public:
    explicit LoginDialog(QWidget *parent = nullptr);

    enum Theme1 {
        Dark,
        Light,
    };
    Q_ENUM(Theme1)

    void init();

protected:
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    // 屏蔽 移动窗口事件
    bool eventFilter(QObject *watched, QEvent *event) override;

signals:
    void needLogin();
    void needSwitchUsr();

private:
    void loadStyleSheet(Theme1 theme);

private:
    Theme1 currentTheme;
    qreal m_globalPx;
    qreal m_globalPy;
    qreal m_delPx;
    qreal m_delPy;
    qreal m_clickPx;
    qreal m_clickPy;
    bool m_isDrag;



    QVBoxLayout *m_layout;
    QHBoxLayout *m_titleBarLayout;

    QWidget *m_titleBar;
    QPushButton *m_iconLabel;
    QPushButton *m_minBtn;
    QPushButton *m_closeBtn;
    QPushButton *m_maxBtn;

    QLabel *m_imgLabel;
    QtMaterialTextField *m_usrLineEdit;
    QtMaterialTextField *m_pwdLineEdit;

    QtMaterialRaisedButton *m_loginBtn;
    QtMaterialRaisedButton *m_switchUsrBtn;




};

#endif // LOGINDIALOG_H
