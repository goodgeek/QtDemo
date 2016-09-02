TEMPLATE = app

QT += qml quick widgets sql

CONFIG += c++11

SOURCES += main.cpp \
    inifilemanager.cpp \
    sqlitehelper.cpp \
    filemanager.cpp \
    threadmanager.cpp \
    workmanager.cpp \
    tcpserver.cpp \
    tcphandlerthread.cpp \
    xmlhandler.cpp \
    jsonhandler.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    inifilemanager.h \
    sqlitehelper.h \
    filemanager.h \
    threadmanager.h \
    workmanager.h \
    tcpserver.h \
    tcphandlerthread.h \
    xmlhandler.h \
    jsonhandler.h
