#ifndef SQLITEHELPER_H
#define SQLITEHELPER_H

#include <QObject>

class SQLiteHelper : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE void dbOperator();
public:
    explicit SQLiteHelper(QObject *parent = 0);

signals:

public slots:
};

#endif // SQLITEHELPER_H
