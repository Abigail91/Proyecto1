#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include <fstream>
#include "Archivo.h"
#include <sstream>
#include <QStandardItemModel>
#include <QNetworkAccessManager>
#include<QNetworkReply>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{




    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

        QCoreApplication::exit(-1);
}, Qt::QueuedConnection);
     engine.load(url);
    Archivo h;
    h.Leer();

                   QNetworkAccessManager  manager;
                   QNetworkRequest req(QUrl("https://opensourceforu.com/2017/06/qt-programming-http-rest-clients/"));

                    QNetworkReply*reply = manager.get(req);{
                        QByteArray read = reply->readAll();
                        std::cout << read.toStdString();
                        reply->close();
                        reply->deleteLater();

                    }
                    QObject::connect(reply,&QNetworkReply::finished,[&])()



                    return app.exec();
                }



