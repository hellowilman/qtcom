#ifndef RS232COMMMODULE_H
#define RS232COMMMODULE_H

#include <QObject>
#include <QtSerialPort>

class RS232CommModule : public QObject
{
    Q_OBJECT
public:
    explicit RS232CommModule(QObject *parent = 0);
    ~RS232CommModule();
    QString getComName() const;
    void setComName(const QString &value);

signals:
    /**
     * @brief onDataReceived emit when data received.
     */
    void sigDataReceived(QByteArray);
    /**
     * @brief onOpenComm for internal used.
     * @param comName, the rs232 name, e.g. "com1"
     */
    void sigOpenComm(QString comName);
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
