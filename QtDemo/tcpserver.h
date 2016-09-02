#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    TcpServer();
    ~TcpServer();
    void startServer();
    void stopServer();
private:
signals:
    void netMsgChanged(QString msg);
public slots:
protected:
    virtual void incomingConnection(qintptr socketDescriptor) override;
};

#endif // TCPSERVER_H
