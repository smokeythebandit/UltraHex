#include "AbstractChecksumCalculator.h"
#include "FileHandle.h"

AbstractChecksumCalculator::AbstractChecksumCalculator(FileHandle *fileHandle, QObject *parent) :
    m_fileHandle(fileHandle), m_chunckSize(1024), m_progress(0)
{

}

quint8 AbstractChecksumCalculator::progress() const
{
    return m_progress;
}

void AbstractChecksumCalculator::setProgress(quint8 newProgress)
{
    if (m_progress == newProgress)
        return;
    m_progress = newProgress;
    emit progressChanged();
}

QByteArray AbstractChecksumCalculator::checksum() const
{
    return m_checksum;
}

void AbstractChecksumCalculator::setChecksum(const QByteArray &newChecksum)
{
    if (m_checksum == newChecksum)
        return;
    m_checksum = newChecksum;
    qDebug() << newChecksum.toHex();
    emit checksumChanged();
}

quint32 AbstractChecksumCalculator::chunckSize() const
{
    return m_chunckSize;
}

void AbstractChecksumCalculator::run()
{
    //Open the file
    QFile file(m_fileHandle->fileInfo().absoluteFilePath());
    if (file.open(QIODevice::ReadOnly)) {
        // Process first chunck
        const QByteArray chunck = file.read(m_chunckSize);
        processFirstChunck(chunck);
        while (file.size() > file.pos()) {
            // Read and process next chunck
            const QByteArray chunck = file.read(m_chunckSize);
            processChunck(chunck);
            // Calculate new progress
            setProgress((float)file.pos() / (float)file.size() * 100);
        }
        finalizeCalculation();
    } else {
        qCritical() << "Could not calculate checksum for" << m_fileHandle->fileInfo() << "because the file could not be openend.";
    }
}

void AbstractChecksumCalculator::processFirstChunck(const QByteArray &data) {
    processChunck(data);
}

void AbstractChecksumCalculator::setChunckSize(quint32 newChunckSize)
{
    if (m_chunckSize == newChunckSize)
        return;
    m_chunckSize = newChunckSize;
    emit chunckSizeChanged();
}


