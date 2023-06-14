#ifndef FILEMODEL_H
#define FILEMODEL_H

//Qt framework
#include <QObject>
#include <QFileInfo>
#include <QQmlEngine>
#include <QAbstractItemModel>

//Internal headers
#include "FileModelRow.h"

/**
 * @brief The FileModel class provides a model like interface to a file
 */
class FileModel : public QAbstractItemModel
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(int columnCount READ columnCount WRITE setColumnCount NOTIFY columnCountChanged)
    QML_UNCREATABLE("FileModel can only be used from a FileHandle")
public:
    explicit FileModel(const QFileInfo &fileInfo, QObject *parent = nullptr);

    void setColumnCount(int newColumnCount);
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    virtual QModelIndex parent(const QModelIndex &index = QModelIndex()) const;

signals:
    void columnCountChanged();

protected:
    void processFile();

private:
    QFile m_file;
    int m_columnCount;
    const QFileInfo m_fileInfo;
};

#endif // FILEMODEL_H
