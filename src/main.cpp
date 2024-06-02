#include "App.h"
#include "LoginPage/LoginDialog.h"
#include "Sys/SysConfig.h"
#include "ComApi/Utils.h"

#include <QApplication>
// #include <unistd.h>

// #include "QsLog.h"


// void initLogger(const QString &logDir) {
//     if (Utils::mkDirs(logDir)) {
//         QsLogging::Logger& logger = QsLogging::Logger::instance();
//         logger.setLoggingLevel(QsLogging::TraceLevel);
//         //    QString timeStr = QDate::currentDate().toString("yyyy-MM-dd");
//         //    QDateTime time = QDateTime::fromString(timeStr,"yyyy-MM-dd");

//         QString logFile = QString("%1/run.log").arg(logDir);
//         QsLogging::DestinationPtr des(
//             QsLogging::DestinationFactory::MakeFileDestination(logFile,
//                                                                QsLogging::EnableLogRotation,
//                                                                QsLogging::MaxSizeBytes(1*1024*1024),
//                                                                QsLogging::MaxOldLogCount(1))
//         );
//         logger.addDestination(des);
//         QLOG_INFO() << "initLogger() success logDir=" << logDir;
//     } else {
//         QLOG_INFO() << "initLogger() error logDir=" << logDir;
//     }
// }





int main(int argc, char *argv[])
{

    QCoreApplication::setOrganizationName("C3H3_Ttigone");
    QCoreApplication::setOrganizationDomain("8.219.252.145");
    QCoreApplication::setApplicationName("ChatForProgrammers");
    QCoreApplication::setApplicationVersion("1.0");

#if (QT_VERSION >= QT_VERSION_CHECK(6, 0, 0))
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::Floor);
#elif (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
#endif

    QApplication a(argc, argv);


    // QString logDir = QApplication::applicationDirPath() + "/logs";
    // initLogger(logDir);



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
