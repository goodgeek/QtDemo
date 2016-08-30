#include "threadmanager.h"
#include <QDebug>

ThreadManager::ThreadManager()
{

}

void ThreadManager::run()
{
    qDebug() << "我是线程: " << QThread::currentThreadId() << endl;
}

void ThreadManager::stopWork()
{
    this->exit(0);
}
