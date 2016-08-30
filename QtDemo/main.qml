import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import zhou.app 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    IniFileManager {
        id: iniFileManager
        onMessageChange: {
            text.text = msg;
        }
    }

    SQLiteHelper {
        id: sqliteHelper;
    }

    FileManager {
        id: fileManager;
    }

    WorkManager {
        id: workManager;
        onWorkMsgChange: {
            text.text = msg;
        }
    }

    Column {
        TextField {
            id: text;
        }

        Button {
            id: btn;
            text: "确定";
            onClicked: {
                iniFileManager.setIniFile();
            }
        }

        Button {
            id: btndb;
            text: "数据库";
            onClicked: {
                sqliteHelper.dbOperator();
            }
        }

        Button {
            id: btnFile;
            text: "文件处理";
            onClicked: {
                fileManager.fileHandler();
            }
        }

        Button {
            id: btnWork;
            text: "开始工作";
            onClicked: {
                workManager.startWork();
            }
        }
    }


}
