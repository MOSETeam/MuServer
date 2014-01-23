#ifndef LOGGER_H
#define LOGGER_H

#include <QDebug>
#include <QFile>
#include <iostream>
#include <QDateTime>

namespace MOSE {
namespace Logger {

void main(const char* modulename);
void MessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

}
}

#endif // LOGGER_H
