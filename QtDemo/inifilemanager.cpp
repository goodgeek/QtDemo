#include "inifilemanager.h"
#include <QSettings>
#include <QDebug>

IniFileManager::IniFileManager(QObject *parent) : QObject(parent)
{

}

void IniFileManager::setIniFile()
{
    QSettings settings("config.ini", QSettings::IniFormat);
    settings.beginGroup("network");
    QString port = settings.value("port").toString();
    //settings.setValue("port", "1234");
    settings.endGroup();

    if (port != "") {
        emit messageChange("端口:" + port);
    }
    qDebug() << "port:" << port << endl;
}
