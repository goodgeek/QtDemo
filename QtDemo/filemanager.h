#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>

class FileManager : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE void fileHandler();
public:
    explicit FileManager(QObject *parent = 0);

signals:

public slots:
};

#endif // FILEMANAGER_H
