#ifndef CRCPPCalculator_H
#define CRCPPCalculator_H

//Qt framework
#include <QObject>

//Standard library
#include <algorithm>

//CRCpp
#include <inc/CRC.h>

//Internal headers
#include "AbstractChecksumCalculator.h"

template<typename CRCType , crcpp_uint16 CRCWidth>
class CRCPPCalculator : public AbstractChecksumCalculator
{
public:
    explicit CRCPPCalculator(FileHandle *fileHandle, CRC::Parameters<CRCType, CRCWidth> parameters, QObject *parent = nullptr) :
        AbstractChecksumCalculator{fileHandle, parent}, m_parameters(parameters)
    {

    }

    virtual void processFirstChunck(const QByteArray &data) {
        previousCRC = CRC::Calculate<CRCType, CRCWidth>(data.constData(), data.size(), m_parameters);
    }

    virtual void processChunck(const QByteArray &data) {
        previousCRC = CRC::Calculate<CRCType, CRCWidth>(data.constData(), data.size(), m_parameters, previousCRC);
    }

    virtual void finalizeCalculation() {
        auto result = QByteArray::fromRawData(reinterpret_cast<const char*>(&previousCRC), sizeof(CRCType));
        QByteArray reverse(result.size(), 0x00);
        std::copy(result.crbegin(),result.crend(),reverse.begin());
        setChecksum(reverse);
    }

private:
    CRC::Parameters<CRCType, CRCWidth> m_parameters;
    CRCType previousCRC;
};


#endif // CRCPPCalculator_H
