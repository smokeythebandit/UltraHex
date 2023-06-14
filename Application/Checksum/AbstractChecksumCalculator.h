#ifndef ABSTRACTCHECKSUMCALCULATOR_H
#define ABSTRACTCHECKSUMCALCULATOR_H

//Qt framework
#include <QFile>
#include <QDebug>
#include <QThread>

//Internal headers
#include "FileHandle.h"

/**
 * @brief The AbstractChecksumCalculator class Defines an interface for calculating checksums
 */
class AbstractChecksumCalculator : public QThread
{
    Q_OBJECT
    Q_PROPERTY(quint8 progress READ progress NOTIFY progressChanged)
    Q_PROPERTY(QByteArray checksum READ checksum NOTIFY checksumChanged)
    Q_PROPERTY(quint32 chunckSize READ chunckSize NOTIFY chunckSizeChanged)
public:
    AbstractChecksumCalculator(pFileHandle fileHandle, QObject *parent = nullptr);

    /**
     * @brief progress Gets the progress of the checksum calculation in percent (0-100%)
     * @return progress of the checksum calculation in percent
     */
    quint8 progress() const;

    /**
     * @brief chunckSize Gets The chuncksize in which the file is read in bytes
     * @return size chuncksize in which the file is read in bytes
     */
    quint32 chunckSize() const;

    /**
     * @brief checksum Gets the calculated checksum (the result of the work this class performs)
     * @return the calculate checksum
     */
    QByteArray checksum() const;

protected:
    virtual void run();
    virtual void processChunck(const QByteArray &data) const = 0;
    void setProgress(quint8 newProgress);
    void setChunckSize(quint32 newChunckSize);
    void setChecksum(const QByteArray &newChecksum);

signals:
    void progressChanged();
    void chunckSizeChanged();
    void checksumChanged();

private:
    pFileHandle m_fileHandle;
    QByteArray m_checksum;
    quint32 m_chunckSize;
    quint8 m_progress;
};

#endif // ABSTRACTCHECKSUMCALCULATOR_H
