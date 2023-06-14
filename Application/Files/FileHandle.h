#ifndef FILEHANDLE_H
#define FILEHANDLE_H

//Qt Framework
#include <QObject>
#include <QFileInfo>
#include <QQmlEngine>

//Internal headers
#include "FileReader.h"

/**
 * @brief The FileHandle class Represents the handle to a opened file
 */
class FileHandle : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(quint64 fileSize READ fileSize CONSTANT)
    Q_PROPERTY(QString fileName READ fileName CONSTANT)
    Q_PROPERTY(QFileInfo fileInfo READ fileInfo CONSTANT)
    Q_PROPERTY(FileReader* fileReader READ fileReader CONSTANT)

    QML_UNCREATABLE("Can only be created by opening files in FileManager")
public:
    /**
     * @brief FileHandle Constructs the file handle
     * @param fileInfo information about the file this handle handles
     * @param parent pointer to parent object
     */
    explicit FileHandle(const QFileInfo &fileInfo, QObject *parent = nullptr);

    /**
     * @brief fileInfo Gets the QFileInfo about the file this handle handles
     * @return QFileInfo about the file this handle handles
     */
    const QFileInfo &fileInfo() const;

    const QString fileName() const;

    const quint64 fileSize() const;

    FileReader* fileReader();

private:
    const QFileInfo m_fileInfo;
    FileReader m_fileReader;
};
typedef QSharedPointer<FileHandle> pFileHandle;

#endif // FILEHANDLE_H
