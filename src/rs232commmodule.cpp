#include "rs232commmodule.h"

RS232CommModule::RS232CommModule(QObject *parent) : QObject(parent),
    serial(0)
{
    comName = "";
    this->moveToThread(&thread);
    connect(this,SIGNAL(sigOpenComm(QString)),this,SLOT(openComm(QString)));
    connect(this,SIGNAL(sigSendDatagram(QByteArray)),this,SLOT(sendDatagram(QByteArray)));

    thread.start();
}

RS232CommModule::~RS232CommModule()
{
    //thread.quit();
}


QString RS232CommModule::getComName() const
{
    return comName;
}

void RS232CommModule::setComName(const QString &value)
{
    comName = value;
}


void RS232CommModule::sendDatagram(QByteArray data)
{
    serial->write(data.data(),data.size());
}

void RS232CommModule::openComm(QString comName)
{
   if(!serial){
       serial = new QSerialPort();
       connect(serial, SIGNAL(readyRead()),this,SLOT(dataReceived()));
   }
   if( serial->portName() != comName){

       if(serial->isOpen()){
           serial->close();
       }
       serial->setPortName(comName);
       serial->setBaudRate(QSerialPort::Baud115200);
       serial->setDataBits(QSerialPort::Data8);
       serial->setParity(QSerialPort::NoParity);
       serial->setStopBits(QSerialPort::OneStop);
       serial->setFlowControl(QSerialPort::NoFlowControl);
       bool rc = serial->open(QSerialPort::ReadWrite);
       if(rc){
           qDebug()<<"Opened " << comName;
       }
   }
}

void RS232CommModule::dataReceived()
{
    QByteArray data = serial->readAll();
    emit sigDataReceived(data);
}

