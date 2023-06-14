#include "FileReader.h"
#include "FileHandle.h"

FileReader::FileReader(FileHandle *parent)
    : QObject{parent}, m_fileHandle(parent), m_file(parent->fileInfo().absoluteFilePath())
{
    if(!m_file.open(QIODevice::ReadOnly)) {
        qWarning() << "Failed to open file" << parent->fileInfo() << "read-only";
    }
}

const QByteArray FileReader::read(qint64 offset, quint32 bytes) {
    m_file.seek(offset);
    return m_file.read(bytes);
}

const QString FileReader::decodedString(qint64 offset, quint32 bytes) {
    const QByteArray data = read(offset, bytes);
    QString returnString;
    QByteArray::iterator iteratorByte;
    for(int i = 0; i < data.size(); i++){
        const char character = data.at(i);
        if(character >= 0x20) {
            returnString.append(character);
        } else {
            returnString.append('.');
        }
    }
    return returnString;
}
