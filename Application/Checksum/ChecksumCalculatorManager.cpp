#include "ChecksumCalculatorManager.h"
#include "ChecksumCalculatorFactory.h"
#include "FileHandle.h"

ChecksumCalculatorManager::ChecksumCalculatorManager(FileHandle *fileHandle, QObject *parent) :
    QObject{parent}, m_fileHandle(fileHandle)
{

}

AbstractChecksumCalculator *ChecksumCalculatorManager::getCalculator(const QString &algorithm)
{
    if(m_calculators.contains(algorithm)) {
        return m_calculators[algorithm];
    } else {
        auto newCalculator = ChecksumCalculatorFactory::createCalculator(m_fileHandle, algorithm);
        if(newCalculator) {
            m_calculators.insert(algorithm, newCalculator);
            emit calculatorsChanged();
        }
        return newCalculator;
    }
}

QList<AbstractChecksumCalculator *> ChecksumCalculatorManager::calculators() const {
    return m_calculators.values();
}

