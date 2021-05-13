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

#define sys          "sys_values"
#define TA           "animals"
#define TA_id        "id"
#define TA_longitude "longitude"
#define TA_latitude  "latitude"
#define TA_time      "animal_date_time"
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
    void test(){
        qDebug()<<"AAA";
    }
        // отправляет данные в бд - на данный момент данный вариант функции не работает из main.qml
        // так как не настроено подключение класса animal
    bool setAnimal(animal &a);
    bool setAnimal(QString _id, double _longitude, double _latitude, int _time, bool _check=0);
    bool setAnimal(QString tableName, QStringList fields, QStringList values);
    bool checkAnimal();
signals:

};

#endif // DATABASE_H
