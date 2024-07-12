#ifndef _MAIN_H_INC_
#define _MAIN_H_INC_
#include <QtCore/QObject>
#include <QtDBus/QDBusAbstractAdaptor>
#include <QtDBus/QDBusVariant>
#include <QCoreApplication>
#include <QDBusConnection>
#include <QDBusError>
#include <QDataStream>
#include <QDebug>
#include <QTimer>
#include <iostream>
#define SERVICE_NAME "com.test"
class QTDbusClass : public QDBusAbstractAdaptor {
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", SERVICE_NAME ".test")

  public:
    QTDbusClass(QObject *obj) : QDBusAbstractAdaptor(obj) {}

  signals:
    void aboutToQuit();
  public slots:
    Q_NOREPLY void quit();
    void method(int data);
};
#endif /* _MAIN_H_INC_ */