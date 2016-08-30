#ifndef QINIFILEMANAGER_H
#define QINIFILEMANAGER_H

#include <QObject>

class IniFileManager : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE void setIniFile();
public:
    explicit IniFileManager(QObject *parent = 0);
signals:
    void messageChange(QString msg);
public slots:
};

#endif // QINIFILEMANAGER_H
