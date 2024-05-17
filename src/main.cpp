#include "App.h"
#include "LoginPage/LoginDialog.h"
#include "Sys/SysConfig.h"

#include <QApplication>
#include <unistd.h>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);

    // LoginDialog l;
    // l.show();

    // Widget w;
    // w.show();

    // QObject::connect(&l, &LoginDialog::needLogin, [&l, &w]() {
    //     l.hide();
    //     w.show();
    //     w.showCenter();
    // });

    Widget w;
    w.show();

    return a.exec();
}
