#include "FileManager.h"

FileManager *FileManager::m_instance=nullptr;

FileManager::FileManager(QObject *parent)
    : QObject{parent}
{

}

FileManager *FileManager::create(QQmlEngine *engine, QJSEngine *scriptEngine) {
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);
    if(m_instance==nullptr){ m_instance = new FileManager();}
    return m_instance;
}

bool FileManager::open(const QUrl &url) {
    return open(url.toLocalFile());
}

bool FileManager::open(const QString &path) {
    return open(QFileInfo(path));
}

bool FileManager::open(const QFileInfo &fileInfo) {
    if (fileInfo.exists() && fileInfo.isReadable()) {
        qInfo() << "Opening file" << fileInfo.absoluteFilePath();
        auto newHandle = pFileHandle::create(fileInfo, this);
        m_fileHandles << newHandle;
        emit newFileOpened(newHandle.data());
        return true;
    } else if(!fileInfo.isReadable()) {
        qWarning() << "Tried to open file" << fileInfo.absoluteFilePath() << "but it is not readable!";
    } else {
        qWarning() << "Tried to open file" << fileInfo.absoluteFilePath() << "but it does not exist!";
    }
    return false;
}
