#include "request.h"

Request::Request(QString url, class database *database)
{
    this->url = url;
    this->database = database;
}

void Request::GetData(int longitude, int latitude, uint time_stamp)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager();

    QJsonObject obj;
    obj.insert("longitude", QJsonValue(longitude));
    obj.insert("latitude", QJsonValue(latitude));

    QByteArray reqString = QJsonDocument(obj).toJson();

    QNetworkRequest request(QUrl(url + "getLocationData"));
    request.setRawHeader("Content-Type", "application/json");

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(WriteData(QNetworkReply*)));
    connect(manager, SIGNAL(finished(QNetworkReply*)), manager, SLOT(deleteLater()));
    manager->post(request, reqString);
}

void Request::WriteData(QNetworkReply *reply)
{
    QByteArray ba = reply->readAll();
    QString str(ba);
    QJsonDocument document = QJsonDocument::fromJson(ba);
    QJsonArray ar = document.array();
    int current_size = 0;
    std::for_each(ar.begin(), ar.end(), [&](QJsonValue i){
        QJsonObject item = i.toObject();
        animal record(
                    item.value("longitude").toDouble(),
                    item.value("latitude").toDouble(),
                    item.value("animal_date_time").toInt(),
                    true,
                    item.value("id").toString());
        (*database).setAnimal(record);

    });
}

void Request::ServerAnswer(QNetworkReply *reply)
{
    qDebug() << reply->readAll();
}

void Request::SendData(animals_list &list) {
    int n = list.get_n();
    QJsonArray json_array;
    for (int i = 0; i < n; ++i) {
        json_array.append(QJsonObject {
                          {"id", list[i]->get_id()},
                          {"longitude", list[i]->get_longitude()},
                          {"latitude", list[i]->get_latitude()},
                          {"animal_date_time", list[i]->get_time()}
                      });
    }
    QByteArray reqString = QJsonDocument(json_array).toJson();
    QNetworkAccessManager *manager = new QNetworkAccessManager();

    QNetworkRequest request(QUrl(url + "add_record"));
    request.setRawHeader("Content-Type", "application/json");

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(ServerAnswer(QNetworkReply*)));
    connect(manager, SIGNAL(finished(QNetworkReply*)), manager, SLOT(deleteLater()));
    manager->post(request, reqString);
}
