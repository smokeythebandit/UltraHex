#include "FileHandle.h"

FileHandle::FileHandle(const QFileInfo &fileInfo, QObject *parent) :
    m_fileInfo(fileInfo), m_fileReader(this), m_calculatorManager(this)
{

}

const QFileInfo &FileHandle::fileInfo() const {
    return m_fileInfo;
}

const QString FileHandle::fileName() const {
    return m_fileInfo.fileName();
}

const quint64 FileHandle::fileSize() const {
    return m_fileInfo.size();
}

FileReader *FileHandle::fileReader() {
    return &m_fileReader;
}

ChecksumCalculatorManager *FileHandle::calculatorManager()
{
    return &m_calculatorManager;
}
