#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <QObject>
#include <QThread>

class ThreadManager : public QThread
{
public:
    ThreadManager();
    void stopWork();
protected:
    virtual void run() override;
};

#endif // THREADMANAGER_H
