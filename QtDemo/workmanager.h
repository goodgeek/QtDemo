#ifndef WORKMANAGER_H
#define WORKMANAGER_H

#include <QObject>
#include <memory>
#include "tcpserver.h"

class WorkManager : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE void startWork();
public:
    explicit WorkManager(QObject *parent = 0);

signals:
    void workMsgChange(QString msg);
public slots:
    void imWrok(QString msg);
private:
    std::shared_ptr<TcpServer> mTcpServer = nullptr;
};

#endif // WORKMANAGER_H
