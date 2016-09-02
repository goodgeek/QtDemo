#include "workmanager.h"
#include "threadmanager.h"
#include "xmlhandler.h"
#include <QUuid>
#include <QCryptographicHash>
#include "jsonhandler.h"

WorkManager::WorkManager(QObject *parent) : QObject(parent)
{

}

void WorkManager::startWork()
{
    /*
    mTcpServer = std::make_shared<TcpServer>();
    connect(mTcpServer.get(), SIGNAL(netMsgChanged(QString)), this, SIGNAL(workMsgChange(QString)));
    mTcpServer.get()->startServer();
    */
    JsonHandler json;
    json.readJson();
}

void WorkManager::imWrok(QString msg)
{
    qDebug() << "槽函数接收到数据:" << msg << endl;
}
