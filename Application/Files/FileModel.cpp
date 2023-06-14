#include "FileModel.h"

FileModel::FileModel(const QFileInfo &fileInfo, QObject *parent)
    : QAbstractItemModel{parent}, m_fileInfo(fileInfo), m_file(fileInfo.absoluteFilePath()), m_columnCount(8)
{
    m_file.open(QIODevice::ReadOnly);
}

int FileModel::columnCount(const QModelIndex &parent) const {
    return m_columnCount;
}

int FileModel::rowCount(const QModelIndex &parent) const {
    return m_fileInfo.size() / columnCount();
}

QVariant FileModel::data(const QModelIndex &index, int role) const{
    if(role == Qt::DisplayRole) {
        const quint64 offset = index.row() * columnCount();
        const_cast<QFile*>(&m_file)->seek(offset);
        const QByteArray data = const_cast<QFile*>(&m_file)->read(columnCount());

        //Create ModelRow
        return QVariant::fromValue<FileModelRow*>(new FileModelRow(offset, data));
    } else return QVariant();
}

QModelIndex FileModel::index(int row, int column, const QModelIndex &parent) const {
    return createIndex(row, column);
}

QModelIndex FileModel::parent(const QModelIndex &index) const {
    Q_UNUSED(index);
    return QModelIndex();
}

void FileModel::processFile() {
    beginResetModel();
    endResetModel();
}

void FileModel::setColumnCount(int newColumnCount)
{
    if (m_columnCount == newColumnCount)
        return;
    beginResetModel();
    m_columnCount = newColumnCount;
    emit columnCountChanged();
    endResetModel();
}
