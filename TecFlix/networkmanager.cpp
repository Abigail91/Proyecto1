#include "networkManager.h"
#include <iostream>

NetworkManager::NetworkManager(QObject*parent):
QObject(parent)
{
connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(readRead(QNetworkReply*)));
}
void NetworkManager::makeRequest(QString endpointRequest){
    std::cout<< manager->get(QNetworkRequest(QUrl(endpointRequest)));
}
void NetworkManager::readRead(QNetworkReply*reply){
    QByteArray Data;
    Data = reply->readAll();
    emit(dataReadyRead(Data));
}
