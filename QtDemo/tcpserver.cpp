#include "tcpserver.h"
#include <QHostAddress>
#include <QSettings>
#include <QTcpSocket>
#include <memory>

TcpServer::TcpServer()
{
    QSettings settings("config.ini", QSettings::IniFormat);
    settings.beginGroup("network");
    int port = settings.value("port").toInt();
    settings.endGroup();

    mTcpServer = new QTcpServer();
    connect(mTcpServer, SIGNAL(newConnection()), this, SLOT(netNewConnection()));
    mTcpServer->listen(QHostAddress::Any, port);
    emit netRecvMsg("服务器已经启动 端口:" + QString::number(port));
}

TcpServer::~TcpServer()
{
    if (mTcpServer != nullptr) {
        delete mTcpServer;
    }
}

void TcpServer::netNewConnection()
{
    if (mTcpServer->hasPendingConnections()) {
        QTcpSocket *socket = mTcpServer->nextPendingConnection();
        QString recvData = socket->readAll();
        qDebug() << "收到数据" << recvData << endl;
        emit netRecvMsg(recvData);
    }
}
