#ifndef CHECKSUMCALCULATORMANAGER_H
#define CHECKSUMCALCULATORMANAGER_H

//Qt framework
#include <QObject>
#include <QQmlEngine>

//Internal headers
#include "AbstractChecksumCalculator.h"

class FileHandle;
/**
 * @brief The ChecksumCalculatorManager class Manages checksum calculators for a FileHandle
 */
class ChecksumCalculatorManager : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_UNCREATABLE("ChecksumCalculatorManager can only be used from a FileHandle")

public:
    explicit ChecksumCalculatorManager(FileHandle *fileHandle, QObject *parent = nullptr);

    AbstractChecksumCalculator* getCalculator(const QString &algorithm);

    QList<AbstractChecksumCalculator *> calculators() const;

signals:
    void calculatorsChanged();

private:
    FileHandle* m_fileHandle;
    QMap<QString, AbstractChecksumCalculator*> m_calculators;
};

#endif // CHECKSUMCALCULATORMANAGER_H
