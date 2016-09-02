#include "tcpserver.h"
#include <QHostAddress>
#include <QSettings>
#include <QTcpSocket>
#include <memory>
#include "tcphandlerthread.h"

TcpServer::TcpServer()
{

}

TcpServer::~TcpServer()
{

}

void TcpServer::startServer()
{
    QSettings settings("config.ini", QSettings::IniFormat);
    settings.beginGroup("NetWork");
    int listPort = settings.value("port").toInt();
    settings.endGroup();

    if (!this->listen(QHostAddress::Any, listPort)) {
        emit netMsgChanged("服务器启动失败");
    } else {
        emit netMsgChanged("服务器启动成功 监听端口:" + QString::number(listPort));
    }
}

void TcpServer::stopServer()
{

}

void TcpServer::incomingConnection(qintptr socketDescriptor)
{
    TcpHandlerThread *tcpThread = new TcpHandlerThread(socketDescriptor);
    connect(tcpThread, SIGNAL(finished()), tcpThread, SLOT(deleteLater()));
    tcpThread->start();
}

