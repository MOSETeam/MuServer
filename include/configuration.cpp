#include "configuration.h"

namespace MOSE {
namespace Configuration {

QJsonDocument jsonDocument;
QJsonObject jsonObjectGlobal;

void loadGlobal(const char* filename) {
    QString settings;
    QFile file(QString("../DataFiles/%1.json").arg(filename));
    if(file.open(QIODevice::ReadOnly | QIODevice::Text) == true) {
        qDebug() << "[Configuration]" << "Global settings loaded";
    }
    else {
        qCritical() << "[Configuration]" << "Global settings load failed!";
        return;
    }

    settings = file.readAll();
    file.close();

    jsonDocument = QJsonDocument::fromJson(settings.toUtf8());

    if(jsonDocument.isNull() == true) {
        qCritical() << "[Configuration]" << "Failed parsing global settings";
        return;
    }
    else {
        jsonObjectGlobal = jsonDocument.object();
    }
}

QJsonObject* getGlobal() {
    return &jsonObjectGlobal;
}


}
}
