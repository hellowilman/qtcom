#include "test_rs232.h"

test_rs232::test_rs232(QObject *parent) : QObject(parent)
{
   /** how to use it? **/
     // open com3
   emit com.sigOpenComm("com11");
     // send data to com3
   emit com.sigSendDatagram("Hello RS232 \n\r");
     // handle the received data
   connect(&com,SIGNAL(sigDataReceived(QByteArray)),
         this,SLOT(onDataReceived(QByteArray)));


}

test_rs232::~test_rs232()
{

}

void test_rs232::onDataReceived(QByteArray data){
    qDebug()<<"Received: " <<data.size() << " bytes. "<<data.toHex();
    // echo
    emit com.sigSendDatagram(data);
}
