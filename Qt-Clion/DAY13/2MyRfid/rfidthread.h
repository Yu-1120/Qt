#ifndef RFIDTHREAD_H
#define RFIDTHREAD_H

#include <QThread>

#define DEV_PATH   "/dev/ttySAC1" //con2

class RfidThread : public QThread
{
    Q_OBJECT
public:
    explicit RfidThread(QObject *parent=nullptr);
    void run();

private:
    unsigned int cardid ;
    struct timeval timeout;

    void init_tty(int fd);
    unsigned char CalBCC(unsigned char *buf, int n);
    int PiccRequest(int fd);
    int PiccAnticoll(int fd);

signals:
    void send_id(unsigned int id);
};

#endif // RFIDTHREAD_H
