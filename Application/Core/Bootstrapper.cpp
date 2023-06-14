#include "Bootstrapper.h"

Bootstrapper::Bootstrapper(QObject *parent)
    : QObject{parent}
{

}

void Bootstrapper::start() {
    emit started();
    configureApplicationInfo();
    loadQml();
    emit finished();
}

void Bootstrapper::configureApplicationInfo() {
    QCoreApplication::setApplicationName("UltraHex");
    QCoreApplication::setApplicationVersion("1.0.0");
}

void Bootstrapper::loadQml() {
    m_qmlApplicationEngine = QSharedPointer<QQmlApplicationEngine>::create(this);
    m_qmlApplicationEngine->loadFromModule("UltraHex", "Main");
}
