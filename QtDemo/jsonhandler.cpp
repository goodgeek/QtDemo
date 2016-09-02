#include "jsonhandler.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QJsonParseError>
#include <QJsonArray>

JsonHandler::JsonHandler(QObject *parent) : QObject(parent)
{

}

void JsonHandler::writeJson()
{
    QFile file("json.txt");
    if (!file.open(QFile::WriteOnly)) {
        qDebug() << "打开文件失败:" << file.errorString() << endl;
        return;
    }
    QTextStream textStream(&file);

    QJsonDocument jsonDocment;
    QJsonObject jsonObject;

    jsonObject.insert("name", "zhoujinlu");
    jsonObject.insert("address", "zhejian");
    jsonObject.insert("cellphone", "13326135702");

    jsonDocment.setObject(jsonObject);
    QString jsonStr = jsonDocment.toJson();
    qDebug() << "josn:" << jsonStr << endl;
    textStream << jsonStr;
    textStream.flush();

    file.close();
}

void JsonHandler::readJson()
{
    QFile jsonFile("json.txt");
    if (!jsonFile.open(QFile::ReadOnly)) {
        qDebug() << "打开文件失败:" << jsonFile.errorString() << endl;
        return;
    }


    auto j = jsonFile.readAll();
    qDebug() << "读到数据:" << j << endl;
    QJsonParseError err;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(j, &err);
    if (err.error == QJsonParseError::NoError) {
        if (jsonDocument.isObject()) {
            QJsonObject jsonObj = jsonDocument.object();
            QJsonArray ay = jsonObj.value("name").toArray();
            qDebug() << ay.at(0) << ay.at(1) << endl;
            QString address = jsonObj.value("address").toString();
            QString cellphone = jsonObj.value("cellphone").toString();
            qDebug() << address << cellphone << endl;
        }
    } else {
        qDebug() << "解析时有错误发生:" << err.errorString() << endl;
    }

    jsonFile.close();
}
