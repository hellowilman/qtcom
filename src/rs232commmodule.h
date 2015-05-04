#ifndef RS232COMMMODULE_H
#define RS232COMMMODULE_H

#include <QObject>
#include <QtSerialPort>

/**
  this is a classs for RS232 communication. it runs in a standalone thread which will accept signals for  open comm and send data; and will emit signal for data received. 
  !!! IMPORTANT! this class do not handle the error (when error on open the port or sending data)!!!! Be aware of this issue!!
*/
class RS232CommModule : public QObject
{
    Q_OBJECT
public:
    explicit RS232CommModule(QObject *parent = 0);
    ~RS232CommModule();
	/**
	* get the current com name. e.g. "COM1"
	*/
    QString getComName() const;
	/**
	  before we open the com port, please send the com port first. thx. 
	*/
    void setComName(const QString &value);

signals:
    /**
     * @brief onDataReceived emit when data received.
     */
    void sigDataReceived(QByteArray);
    /**
     * @brief onOpenComm; this will emit a signal to 
     * @param comName, the rs232 name, e.g. "com1"
     */
    void sigOpenComm(QString comName);
	/**
	 * @brief sigSendDatagram for internal used. 
	*/
    void sigSendDatagram(QByteArray);

public slots:
    void sendDatagram(QByteArray);
    void openComm(QString comName);
private:
    QString comName;
    QSerialPort *serial;
    QThread thread;
private slots:
    void dataReceived();


};

#endif // RS232COMMMODULE_H
