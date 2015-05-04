#include "test_rs232.h"

test_rs232::test_rs232(QObject *parent) : QObject(parent)
{
   /** how to use it? **/
     // open com3
   emit com.sigOpenComm("com3");
     // send data to com3 (it is very very easy to send data to com port. 
   emit com.sigSendDatagram("Hello RS232 \n\r");
     // handle the signal from com for data received. 
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
