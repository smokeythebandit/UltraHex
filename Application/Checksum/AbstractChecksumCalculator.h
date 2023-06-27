#ifndef ABSTRACTCHECKSUMCALCULATOR_H
#define ABSTRACTCHECKSUMCALCULATOR_H

//Qt framework
#include <QFile>
#include <QDebug>
#include <QThread>
#include <QQmlEngine>

class FileHandle;
/**
 * @brief The AbstractChecksumCalculator class Defines an interface for calculating checksums
 */
class AbstractChecksumCalculator : public QThread
{
    Q_OBJECT
    Q_PROPERTY(quint8 progress READ progress NOTIFY progressChanged)
    Q_PROPERTY(QByteArray checksum READ checksum NOTIFY checksumChanged)
    Q_PROPERTY(quint32 chunckSize READ chunckSize NOTIFY chunckSizeChanged)
    QML_ELEMENT
    QML_UNCREATABLE("Can only retrieve instances from ChecksumCalculationManager")
public:
    explicit AbstractChecksumCalculator(FileHandle *fileHandle, QObject *parent = nullptr);

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
    virtual void processFirstChunck(const QByteArray &data);
    virtual void processChunck(const QByteArray &data) = 0;
    virtual void finalizeCalculation() = 0;

    void setProgress(quint8 newProgress);
    void setChunckSize(quint32 newChunckSize);
    void setChecksum(const QByteArray &newChecksum);

signals:
    void progressChanged();
    void chunckSizeChanged();
    void checksumChanged();

private:
    FileHandle *m_fileHandle;
    QByteArray m_checksum;
    quint32 m_chunckSize;
    quint8 m_progress;
};
Q_DECLARE_OPAQUE_POINTER(AbstractChecksumCalculator*)

#endif // ABSTRACTCHECKSUMCALCULATOR_H
