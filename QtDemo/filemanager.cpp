#include "filemanager.h"
#include <QFile>
#include <QDebug>
#include <QFileInfo>
#include <QDir>

FileManager::FileManager(QObject *parent) : QObject(parent)
{

}

void FileManager::fileHandler()
{
    QDir dir;
    QStringList files = dir.entryList();
    for (auto file : files) {
        qDebug() << file << endl;
    }
    QFileInfo fileInfo;
}
