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

signals:
void dataReadyRead(QByteArray);

public slots:
void readRead(QNetworkReply*reply);

private:
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

};

#endif // NETWORKMANAGER_H
