#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

/**
 * @brief Gestiona las peticiones http
 *
 */
class NetworkManager: public QObject
{
    Q_OBJECT
public:
    /**
     * @brief 
     *
     * @param parent
     */
    explicit NetworkManager(QObject*parent = nullptr);
    /**
     * @brief Hace un metodo GET.
     *
     * @param endpointRequest url al que se le hace el metodo GET
     */
    void makeRequest(QString endpointRequest);
    QNetworkAccessManager *manager = new QNetworkAccessManager(this); /**< TODO: describe */

signals:
/**
 * @brief 
 *
 * @param QByteArray
 */
void dataReadyRead(QByteArray);

public slots:
/**
 * @brief 
 *
 * @param reply
 */
void readRead(QNetworkReply*reply);

private:


};

#endif // NETWORKMANAGER_H
