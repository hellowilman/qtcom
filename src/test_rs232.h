#ifndef TEST_RS232_H
#define TEST_RS232_H
#include "rs232commmodule.h"
#include <QObject>

class test_rs232 : public QObject
{
    Q_OBJECT
public:
    explicit test_rs232(QObject *parent = 0);
    ~test_rs232();

signals:

public slots:
    void onDataReceived(QByteArray data);
private:
    RS232CommModule com;
};

#endif // TEST_RS232_H
