#ifndef CryptoPPCalculator_H
#define CryptoPPCalculator_H

//Qt framework
#include <QObject>

//Cryptopp
#include <cryptopp/sm3.h>
#include <cryptopp/sha.h>
#include <cryptopp/md2.h>
#include <cryptopp/md4.h>
#include <cryptopp/md5.h>
#include <cryptopp/blake2.h>
#include <cryptopp/keccak.h>
#include <cryptopp/shake.h>
#include <cryptopp/tiger.h>
#include <cryptopp/ripemd.h>
#include <cryptopp/lsh.h>
#include <cryptopp/whrlpool.h>

//Internal headers
#include "AbstractChecksumCalculator.h"

template <typename T>
class CryptoPPCalculator : public AbstractChecksumCalculator
{
public:
    explicit CryptoPPCalculator(FileHandle *fileHandle, QObject *parent = nullptr) : AbstractChecksumCalculator{fileHandle, parent} {
        m_hash.Restart();
    }

    virtual void processChunck(const QByteArray &data) {
        m_hash.Update(reinterpret_cast<const CryptoPP::byte*>(data.constData()), data.size());
    }

    virtual void finalizeCalculation() {
        QByteArray digest(m_hash.DigestSize(), 0x00);
        m_hash.Final(reinterpret_cast<CryptoPP::byte*>(digest.data()));
        setChecksum(digest);
    }


private:
    T m_hash;
};


#endif // CryptoPPCalculator_H
