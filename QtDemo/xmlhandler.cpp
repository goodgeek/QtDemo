#include "xmlhandler.h"
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include <QDateTime>
#include <QDebug>

XmlHandler::XmlHandler(QObject *parent) : QObject(parent)
{

}

void XmlHandler::startXml()
{
    QFile xmlFile("text.xml");
    if (!xmlFile.open(QIODevice::WriteOnly)) {
        emit xmlInfoChanged("打开文件失败:" + xmlFile.errorString());
        return;
    }

    QStringList list;
    QXmlStreamWriter xmlWriter;
    xmlWriter.setDevice(&xmlFile);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("root");
        xmlWriter.writeTextElement("姓名", "周锦路");
        xmlWriter.writeTextElement("性别", "男");
        xmlWriter.writeTextElement("电话", "13326135702");
        xmlWriter.writeTextElement("地址", "浙江省临安市河桥镇聚秀村");
        xmlWriter.writeTextElement("完成时间", QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();

    if (xmlWriter.hasError()) {
        emit xmlInfoChanged("创建xml文件发生了错误");
    }
    xmlFile.close();
    emit xmlInfoChanged("文件创建完成");
}

void XmlHandler::readXml()
{
    QFile xmlFile("text.xml");
    if (!xmlFile.open(QIODevice::ReadOnly)) {
        emit xmlInfoChanged("打开文件失败:" + xmlFile.errorString());
        return;
    }

    QXmlStreamReader xmlReader;
    xmlReader.setDevice(&xmlFile);

    while (!xmlReader.atEnd()) {
        xmlReader.readNext();
        if (xmlReader.isStartElement()) {
            if (xmlReader.name() == "姓名") {
                QString name = xmlReader.readElementText();
                qDebug() << "姓名:" << name << endl;
            } else if (xmlReader.name() == "电话") {
                QString phone = xmlReader.readElementText();
                qDebug() << "电话:" << phone << endl;
            }
        }
    }

    if (xmlReader.hasError()) {
        emit xmlInfoChanged("读取xml文件发生错误:" + xmlReader.errorString());
    }
    xmlFile.close();
}
