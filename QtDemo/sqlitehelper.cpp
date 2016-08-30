#include "sqlitehelper.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <qtsql/QSqlError>
#include <QDebug>

SQLiteHelper::SQLiteHelper(QObject *parent) : QObject(parent)
{

}

void SQLiteHelper::dbOperator()
{
    QSqlDatabase db;
    if (QSqlDatabase::contains("test_db_connect"))
        db = QSqlDatabase::database("test_db_connect");
    else
        db = QSqlDatabase::addDatabase("QSQLITE", "test_db_connect");
    db.setDatabaseName("test.db");
    if (!db.open()) {
        qDebug() << "数据库打开失败" << db.lastError().text() << endl;
        return;
    }

    QSqlQuery query(db);

    if (!query.exec("select * from t_user")) {
        qDebug() << "查询数据库失败:" << query.lastError().text() << endl;
    }
    while (query.next()) {
        auto name = query.value(0).toString();
        auto address = query.value(1).toString();
        auto age = query.value(2).toString();
        qDebug() << "查询到的数据:" << name << address << age << endl;
    }

    query.clear();

    QString connectName;
    {
        connectName = QSqlDatabase::database().connectionName();
    }
    db.close();
    db.removeDatabase(connectName);
}
