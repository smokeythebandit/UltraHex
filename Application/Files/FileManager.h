#ifndef FILEMANAGER_H
#define FILEMANAGER_H

// Qt Framework
#include <QDebug>
#include <QObject>
#include <QFileInfo>
#include <QJSEngine>
#include <QQmlEngine>

//Internal Headers
#include "FileHandle.h"
#include "ChecksumCalculatorFactory.h"

/**
 * @brief The FileManager singleton class Manages all the opened files
 */
class FileManager : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
private:
    explicit FileManager(QObject *parent = nullptr);

public:
    /**
     * @brief create Gets the static instance of the FileManager class
     * @param engine instance of QQmlEngine invoking this function
     * @param scriptEngine instance of QJSEngine invoking this function
     * @return instance of the FileManager class
     */
    static FileManager *create(QQmlEngine *engine = nullptr,  QJSEngine *scriptEngine = nullptr);

public slots:

    /**
     * @brief open Attempts to open a file
     * @param url url to the file we want to open
     * @return returns true on success
     */
    bool open(const QUrl &url);

    /**
     * @brief open Attempts to open a file
     * @param path path to the file we want to open
     * @return returns true on success
     */
    bool open(const QString &path);

    /**
     * @brief open Attempts to open a file
     * @param fileinfo file info of the file we want to open
     * @return returns true on success
     */
    bool open(const QFileInfo &fileInfo);

signals:
    void newFileOpened(const FileHandle *fileHandle);

private:
    static FileManager *m_instance;
    QList<pFileHandle> m_fileHandles;

};

#endif // FILEMANAGER_H
