#include "workmanager.h"
#include "threadmanager.h"

WorkManager::WorkManager(QObject *parent) : QObject(parent)
{

}

void WorkManager::startWork()
{
    mTcpServer = std::make_shared<TcpServer>();
    connect(mTcpServer.get(), SIGNAL(netRecvMsg(QString)), this, SIGNAL(workMsgChange(QString)));
}
