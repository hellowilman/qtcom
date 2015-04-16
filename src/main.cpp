
#include <QApplication>
#include <QSerialPort>
#include <QSerialPortInfo>


#include "test_rs232.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    test_rs232 test;

    return a.exec();
}
