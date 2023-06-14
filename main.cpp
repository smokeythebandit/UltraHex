//Qt Framework
#include <QIcon>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

//Internal headers
#include "Application/Core/Bootstrapper.h"

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/Icons/GUI/Icons/Hexadecimal.svg" ));
    // Bootstrap the application
    Bootstrapper bootstrapper;
    bootstrapper.start();

    return app.exec();
}
