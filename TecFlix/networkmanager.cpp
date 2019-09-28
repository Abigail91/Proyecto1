#include "networkManager.h"
#include <iostream>
/**
 * @brief Se encarga de las peticiones http.
 */
NetworkManager::NetworkManager(QObject*parent):
QObject(parent)
{
connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(readRead(QNetworkReply*)));
}
/**
 * @brief Hace una peticion GET al url.
 * @param endpointRequest dirección web a la que se le realizará la petición.
 */
void NetworkManager::makeRequest(QString endpointRequest){
    std::cout << manager->get(QNetworkRequest(QUrl(endpointRequest)));
}
void NetworkManager::readRead(QNetworkReply*reply){
    QByteArray Data;
    Data = reply->readAll();
    emit(dataReadyRead(Data));

}
