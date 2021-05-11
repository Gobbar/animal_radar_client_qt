#ifndef REQUEST_H
#define REQUEST_H

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <algorithm>
#include "animal.h"
#include "database.h"
#include "animals_list.h"

class Request : public QObject
{
    Q_OBJECT
public:
    Request(QString ulr, database *database);
    void SendData(animals_list &list);
    void GetData(int longitude, int latitude, uint time_stamp);
    QString last = "";
private:
    QString url;
    database *database;
public slots:
    void collectData(QString *res);
    void WriteData(QNetworkReply *reply);
    void ServerAnswer(QNetworkReply *reply);
//signals:
//    void readyRead();
//    void finished();
};

#endif // REQUEST_H
