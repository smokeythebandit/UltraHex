#ifndef BOOTSTRAPPER_H
#define BOOTSTRAPPER_H

//Qt Framework
#include <QObject>
#include <QCoreApplication>
#include <QQmlApplicationEngine>

/**
 * @brief The Bootstrapper class Configures the application and load other parts of the code at startup
 */
class Bootstrapper : public QObject
{
    Q_OBJECT
public:
    explicit Bootstrapper(QObject *parent = nullptr);

    /**
     * @brief start Start the bootstrapping process
     */
    void start();

protected:
    /**
     * @brief configureApplicationInfo Set the application info
     */
    void configureApplicationInfo();

    /**
     * @brief loadQml Start the QML engine and loads Main.qml
     */
    void loadQml();

signals:
    /**
     * @brief started Signals that the bootstrapping process has started
     */
    void started();

    /**
     * @brief finished Signals that the bootstrapping process has finished
     */
    void finished();

private:
    QSharedPointer<QQmlApplicationEngine> m_qmlApplicationEngine;

};

#endif // BOOTSTRAPPER_H
