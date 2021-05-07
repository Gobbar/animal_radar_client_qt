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
    int getSize();
    bool setAnimal(animal &a);
    bool setAnimal(double _longitude, double _latitude, int _time, bool _check=0);
signals:

};

#endif // DATABASE_H
