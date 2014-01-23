#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QDebug>

namespace MOSE {
namespace Configuration {

void loadGlobal(const char* filename);
QJsonObject* getGlobal();

}
}

#endif // CONFIGURATION_H
