#ifndef FILEREADER_H
#define FILEREADER_H

//Qt Framework
#include <QFile>
#include <QObject>
#include <QQmlEngine>


/**
 * @brief The FileReader class Allow the (concurrent) reading of data from a FileHandle
 */
class FileHandle;
class FileReader : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_UNCREATABLE("FileReader can only be used from a FileHandle")

public:
    explicit FileReader(FileHandle *parent);


public slots:
    /**
     * @brief read Reads a number of bytes at a specific offset
     * @param offset starting offset
     * @param bytes number of bytes to read
     * @return the bytes that where read
     */
    const QByteArray read(qint64 offset, quint32 bytes);

    /**
     * @brief dataToDecodedString converts raw data to string (unknown characters replaced with .
     * @param data data to decode
     * @return output string
     */
    const QString decodedString(qint64 offset, quint32 bytes);

private:
    QFile m_file;
    FileHandle *m_fileHandle;
};

#endif // FILEREADER_H
