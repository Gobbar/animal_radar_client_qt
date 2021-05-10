#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>
#include <QStringList>
#include <QList>

#include "animal.h"

#define DATABASE_HOSTNAME   "test"
#define DATABASE_NAME       "test.db"

#define TA           "animals"
#define TA_id        "id"
#define TA_longitude "longitude"
#define TA_latitude  "latitude"
#define TA_time      "animals_date_time"
#define TA_check     "on_server"


class database : public QObject
{
    Q_OBJECT
public:
    explicit database(QObject *parent = 0);
    ~database();
    void connectToDataBase();
private:
    // Сам объект базы данных, с которым будет производиться работа
    QSqlDatabase    db;

private:
    /* Внутренние методы для работы с базой данных
     * */
    bool openDataBase();        // Открытие базы данных
    bool restoreDataBase();     // Восстановление базы данных
    void closeDataBase();       // Закрытие базы данных
    bool createTable();

public slots:
//    QSqlQuery* getRows();
    animal* getAnimals(QString str);
    int getSize(QString str);
    // отправляет данные в бд - на данный момент данный вариант функции не работает из main.qml
    // так как не настроено подключение класса animal
    bool setAnimal(animal &a){
        QSqlQuery query;
        query.prepare("insert into animals (longitude, latitude, animal_date_time, on_server) values (:long, :lati, :time, :check);");
        query.bindValue(":long", QString::number(a.get_longitude(),'f', 3));
        query.bindValue(":lati", QString::number(a.get_latitude(),'f', 3));
        query.bindValue(":time", QString::number(a.get_time()));
        query.bindValue(":check", QString::number(a.on_server()));
        //query.prepare("insert into animals (longitude, latitude, animal_date_time, on_server) values (3,3,3,0)");
        if(!query.exec()){
                qDebug() << "error insert into " << TA;
                qDebug() << query.lastError().text();
                return false;
            } else {
                qDebug()<<a.get_latitude();
                return true;
            }
        return false;
    }
    bool setAnimal(double _longitude, double _latitude, int _time, bool _check=0);
    bool setAnimal(QString tableName, QStringList fields);
signals:

};

#endif // DATABASE_H
