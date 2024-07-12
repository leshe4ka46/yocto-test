#include "main.h"
void QTDbusClass::quit() {
    QMetaObject::invokeMethod(QCoreApplication::instance(),
                              &QCoreApplication::quit, Qt::QueuedConnection);
}
void QTDbusClass::method(int data) {
    std::cout << "got " << data << std::endl;
}
int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);
    QObject obj;
    QTDbusClass *pinsHandler = new QTDbusClass(&obj);
    QObject::connect(&app, &QCoreApplication::aboutToQuit, pinsHandler,
                     &QTDbusClass::aboutToQuit);
    auto connection = QDBusConnection::sessionBus();
    if (!connection.isConnected()) {
        std::cerr << "Cannot connect to the D-Bus session bus." << std::endl;
        return 1;
    }
    connection.registerObject("/", &obj);
    if (!connection.registerService(SERVICE_NAME)) {
        std::cerr << connection.lastError().message().toStdString() << std::endl;
        return 1;
    }
    std::cout << "started succesfully with name " << SERVICE_NAME << std::endl;
    app.exec();
    return 0;
}