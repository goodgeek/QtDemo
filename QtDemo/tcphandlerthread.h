#ifndef TCPHANDLERTHREAD_H
#define TCPHANDLERTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <memory>

class TcpHandlerThread : public QThread
{
    Q_OBJECT
public:
    TcpHandlerThread(int socketfd);
    void stopThread();
protected:
    virtual void run() override;
private:
    int clientSocketfd;
    int isQuit = false;
};

#endif // TCPHANDLERTHREAD_H
