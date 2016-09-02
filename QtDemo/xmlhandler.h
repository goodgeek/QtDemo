#ifndef XMLHANDLER_H
#define XMLHANDLER_H

#include <QObject>

class XmlHandler : public QObject
{
    Q_OBJECT
public:
    explicit XmlHandler(QObject *parent = 0);
    void startXml();
    void readXml();
signals:
    void xmlInfoChanged(QString info);
public slots:
};

#endif // XMLHANDLER_H
