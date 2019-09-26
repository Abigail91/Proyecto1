#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class NetworkManager: public QObject
{
    Q_OBJECT
public:
    explicit NetworkManager(QObject*parent = nullptr);
    void makeRequest(QString endpointRequest);
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

signals:
void dataReadyRead(QByteArray);

public slots:
void readRead(QNetworkReply*reply);

private:


};

#endif // NETWORKMANAGER_H
