#include "FileModelRow.h"

FileModelRow::FileModelRow(const quint64 offset, const QByteArray &data, QObject *parent)
    : QObject{parent}, m_offset(offset), m_data(data)
{

}

FileModelRow::~FileModelRow()
{
    qDebug() << "Destruction";
}

quint64 FileModelRow::offset() const {
    return m_offset;
}

quint64 FileModelRow::dataSize() const {
    return m_data.size();
}

QByteArray FileModelRow::data() const {
    return m_data;
}

QString FileModelRow::byteString(const quint64 offset) const {
    return m_data.mid(offset, 1).toHex();
}

QString FileModelRow::toString() const {
    QString returnString;
    QByteArray::iterator iteratorByte;
    for(int i = 0; i < m_data.size(); i++){
        char data = m_data.at(i);
        if(data >= 0x20) {
            returnString.append(data);
        } else {
            returnString.append('.');
        }
    }
    return returnString;
}
