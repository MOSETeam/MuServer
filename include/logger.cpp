#include "logger.h"

namespace MOSE {
namespace Logger {

void main(const char* modulename) {
    qDebug() << "\n"
             << "\t|  MU ONLINE SERVER EMULATOR\n"
             << "\t|   Module:" << modulename << "\n"
             << "\t|    Authors: MOSE Team\n"
             << "\t|     Thanks!\n"
             << "\t+-----------------------------------\n\n";

    qInstallMessageHandler(MessageHandler);

    qDebug() << "Application started";
}

void MessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    Q_UNUSED(context)
    QString datetime = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
    QString txt = QString("[%1]\t").arg(datetime);

    switch(type) {

        case QtDebugMsg:
            txt += QString("%1").arg(msg);
            break;

        case QtWarningMsg:
            txt += QString("[Warning] %1").arg(msg);
            break;

        case QtCriticalMsg:
            txt += QString("[Critical] %1").arg(msg);
            break;

        case QtFatalMsg:
            txt += QString("[Fatal] %1").arg(msg);
            break;

    }

    QFile logfile(QString("logs/").append(QDateTime::currentDateTime().toString("dd-MM-yyyy").append(".log")));
    logfile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream textstream(&logfile);
    textstream << txt << endl;
    std::cout << txt.toStdString().c_str() << std::endl;
}

}
}
