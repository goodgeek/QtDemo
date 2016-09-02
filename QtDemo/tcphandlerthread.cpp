#include "tcphandlerthread.h"
#include <QHostAddress>

TcpHandlerThread::TcpHandlerThread(int socketfd) :
    clientSocketfd(socketfd)
{

}

void TcpHandlerThread::run()
{
    QTcpSocket socket;
    socket.setSocketDescriptor(clientSocketfd);
    qDebug() << "客户:" << socket.peerAddress().toString() << endl;

    while (!isQuit) {
        socket.waitForReadyRead(-1);

        if (socket.bytesAvailable() > 0) {
            QString recvMsg = socket.readAll();
            qDebug() << "Recv: " << recvMsg << endl;
            if (recvMsg == "quit")
                break;
            socket.write("Hello Client");
            socket.waitForBytesWritten();
        }
        if (socket.error() == QTcpSocket::RemoteHostClosedError) {
            qDebug() << "客户端关闭了" << endl;
            break;
        }
    }
    socket.close();
}

void TcpHandlerThread::stopThread()
{
    isQuit = true;
}
