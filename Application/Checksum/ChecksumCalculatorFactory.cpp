#include "ChecksumCalculatorFactory.h"
#include "CryptoPPCalculator.h"
#include "CRCPPCalculator.h"
#include "FileHandle.h"

ChecksumCalculatorFactory::ChecksumCalculatorFactory(QObject *parent)
    : QObject{parent}
{

}

AbstractChecksumCalculator *ChecksumCalculatorFactory::createCalculator(FileHandle *handle, const QString &algorithm) {
    // Check if calculator already exists
    auto constructorMapping = nameAndConstructors();
    if(constructorMapping.contains(algorithm)) {
        return constructorMapping[algorithm](handle);
    } else return nullptr;
}

QList<QString> ChecksumCalculatorFactory::availableAlgorithms()
{
    return nameAndConstructors().keys();
}

QMap<QString, std::function<AbstractChecksumCalculator *(FileHandle *)> > ChecksumCalculatorFactory::nameAndConstructors()
{
    return {
        {"CRC-8", [](FileHandle *handle){return new CRCPPCalculator<uint8_t, 8>(handle, CRC::CRC_8());}},
        {"CRC-16", [](FileHandle *handle){return new CRCPPCalculator<uint16_t, 16>(handle, CRC::CRC_16_ARC());}},
        {"CRC-32", [](FileHandle *handle){return new CRCPPCalculator<uint32_t, 32>(handle, CRC::CRC_32());}},
        {"MD2", [](FileHandle *handle){return new CryptoPPCalculator<CryptoPP::Weak1::MD2>(handle);}},
        {"MD4", [](FileHandle *handle){return new CryptoPPCalculator<CryptoPP::Weak1::MD4>(handle);}},
        {"MD5", [](FileHandle *handle){return new CryptoPPCalculator<CryptoPP::Weak1::MD5>(handle);}},
        {"SHA-1", [](FileHandle *handle){return new CryptoPPCalculator<CryptoPP::SHA1>(handle);}},
        {"SHA-224", [](FileHandle *handle){return new CryptoPPCalculator<CryptoPP::SHA224>(handle);}},
        {"SHA-256", [](FileHandle *handle){return new CryptoPPCalculator<CryptoPP::SHA256>(handle);}},
        {"SHA-384", [](FileHandle *handle){return new CryptoPPCalculator<CryptoPP::SHA384>(handle);}},
        {"SHA-512", [](FileHandle *handle){return new CryptoPPCalculator<CryptoPP::SHA512>(handle);}},
        {"Blake-2b", [](FileHandle *handle){return new CryptoPPCalculator<CryptoPP::BLAKE2b>(handle);}},
        {"Blake-2s", [](FileHandle *handle){return new CryptoPPCalculator<CryptoPP::BLAKE2s>(handle);}},
        {"Shake-128", [](FileHandle *handle){return new CryptoPPCalculator<CryptoPP::SHAKE128>(handle);}},
        {"Shake-256", [](FileHandle *handle){return new CryptoPPCalculator<CryptoPP::SHAKE256>(handle);}},
        {"LSH-224", [](FileHandle *handle){return new CryptoPPCalculator<CryptoPP::LSH224>(handle);}},
        {"LSH-256", [](FileHandle *handle){return new CryptoPPCalculator<CryptoPP::LSH256>(handle);}},
        {"LSH-384", [](FileHandle *handle){return new CryptoPPCalculator<CryptoPP::LSH384>(handle);}},
        {"LSH-512", [](FileHandle *handle){return new CryptoPPCalculator<CryptoPP::LSH512>(handle);}},
        {"Tiger", [](FileHandle *handle){return new CryptoPPCalculator<CryptoPP::Tiger>(handle);}},
        {"Ripemd-128", [](FileHandle *handle){return new CryptoPPCalculator<CryptoPP::RIPEMD128>(handle);}},
        {"Ripemd-160", [](FileHandle *handle){return new CryptoPPCalculator<CryptoPP::RIPEMD160>(handle);}},
        {"Ripemd-256", [](FileHandle *handle){return new CryptoPPCalculator<CryptoPP::RIPEMD256>(handle);}},
        {"Ripemd-320", [](FileHandle *handle){return new CryptoPPCalculator<CryptoPP::RIPEMD320>(handle);}},
        {"SM3", [](FileHandle *handle){return new CryptoPPCalculator<CryptoPP::SM3>(handle);}},
        {"Whirlpool", [](FileHandle *handle){return new CryptoPPCalculator<CryptoPP::Whirlpool>(handle);}},
    };
}
