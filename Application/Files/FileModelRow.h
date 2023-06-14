#ifndef FILEMODELROW_H
#define FILEMODELROW_H

#include <QDebug>
#include <QObject>
#include <QQmlEngine>

class FileModelRow : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QByteArray data READ data CONSTANT)
    Q_PROPERTY(quint64 offset READ offset CONSTANT)
    Q_PROPERTY(quint64 dataSize READ dataSize CONSTANT)

    QML_UNCREATABLE("FileModel can only be retrieved from the FileModelRow")
public:
    explicit FileModelRow(const quint64 offset, const QByteArray &data, QObject *parent = nullptr);
    ~FileModelRow();

    quint64 offset() const;

    quint64 dataSize() const;

    QByteArray data() const;

public slots:
    QString byteString(const quint64 offset) const;
    QString toString() const;

private:
    const quint64 m_offset;
    const QByteArray m_data;
};

#endif // FILEMODELROW_H
