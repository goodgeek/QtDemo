#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>

class TcpServer : public QObject
{
    Q_OBJECT
public:
    TcpServer();
    ~TcpServer();
private:
    QTcpServer *mTcpServer = nullptr;
signals:
    void netRecvMsg(QString msg);
public slots:
    void netNewConnection();
};

#endif // TCPSERVER_H
