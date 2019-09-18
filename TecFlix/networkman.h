#ifndef NETWORKMAN_H
#define NETWORKMAN_H

#include <QObject>

class NetworkMan : public QObject
{
    Q_OBJECT
public:
    explicit NetworkMan(QObject *parent = nullptr);

signals:

public slots:
};

#endif // NETWORKMAN_H
