#ifndef CHECKSUMCALCULATIONMANAGER_H
#define CHECKSUMCALCULATIONMANAGER_H

//Qt framework
#include <QObject>
#include <QQmlEngine>

//Internal headers
#include "FileHandle.h"
#include "AbstractChecksumCalculator.h"

class FileHandle;
/**
 * @brief The ChecksumCalculationManager class Can be used to instantiate checksum calculators
 */
class ChecksumCalculatorFactory : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QString> availableAlgorithms READ availableAlgorithms CONSTANT)    
    QML_ELEMENT
    QML_SINGLETON
public:
    explicit ChecksumCalculatorFactory(QObject *parent = nullptr);

    /**
     * @brief availableAlgorithms Gets list of available algorithms
     * @return list of available algorithms
     */
    static QList<QString> availableAlgorithms();

private:
    static QMap<QString, std::function<AbstractChecksumCalculator *(FileHandle*)> > nameAndConstructors();

public slots:
    /**
     * @brief getCalculator Gets or creates and instance of a checksum calculator for a given algorithm
     * @param algorithm the name of the algorithm the create a calculator for
     * @return null if an calculator could not be found, or pointer to instance of matching calculator
     */
    static AbstractChecksumCalculator* createCalculator(FileHandle *handle, const QString &algorithm);
};

#endif // CHECKSUMCALCULATIONMANAGER_H
