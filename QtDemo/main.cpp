#include <QApplication>
#include <QQmlApplicationEngine>
#include "inifilemanager.h"
#include "sqlitehelper.h"
#include "filemanager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<IniFileManager>("zhou.app", 1, 0, "IniFileManager");
    qmlRegisterType<SQLiteHelper>("zhou.app", 1, 0, "SQLiteHelper");
    qmlRegisterType<FileManager>("zhou.app", 1, 0, "FileManager");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
