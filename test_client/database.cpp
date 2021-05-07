#include "database.h"
#include <QStandardPaths>


database::database(QObject *parent) : QObject(parent)
{

}

database::~database(){

}
void database::connectToDataBase(){
    if(!QFile(DATABASE_NAME).exists()){
            QFile::copy(":/" DATABASE_NAME , DATABASE_NAME);
            QFile::setPermissions(DATABASE_NAME, QFile::WriteOwner | QFile::ReadOwner);
        }
        this->openDataBase();
}

bool database::restoreDataBase(){
    if(this->openDataBase()){
            // Производим восстановление базы данных
            return (this->createTable()) ? true : false;
        } else {
            qDebug() << "Не удалось восстановить базу данных";
            return false;
        }
        return false;
}


bool database::openDataBase()
{
    /* База данных открывается по заданному пути
     * и имени базы данных, если она существует
     * */

    //QString DatabaseDataStoragePath = QStandardPaths::writableLocation(QStandardPaths::StandardLocation::AppDataLocation);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName(DATABASE_NAME);
    if(db.open()){
        return true;

    } else {
        return false;
    }
}

/* Методы закрытия базы данных
 * */
void database::closeDataBase()
{
    db.close();
}



//QSqlQuery* database::getRows(){

//    QSqlQuery query("select * from "+QString(TA)+";");
//    while (query.next()){
//        qDebug()<<query.value(0).toInt();
//        qDebug()<<query.result();
//    }

//    return &query;

//}
int database::getSize(){
    QSqlQuery ind("select count(*) from "+QString(TA)+";");

    ind.next();
    return ind.value(0).toInt();
}
animal* database::getAnimals(QString str){

    QSqlQuery query(str);


    animal* a=new animal[getSize()];

    int i=0;
    while (query.next()){
           animal A(query.value(0).toInt(), query.value(1).toDouble(), query.value(2).toDouble(), query.value(3).toInt(), query.value(4).toBool());
           a[i]=A;
           qDebug()<<A.get_latitude();
           ++i;
    }
    return a;
}

bool database::setAnimal(animal &a){
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

bool database::setAnimal(double _longitude, double _latitude, int _time, bool _check){
    QSqlQuery query;
    query.prepare("insert into animals (longitude, latitude, animal_date_time, on_server) values (:long, :lati, :time, :check);");
    query.bindValue(":long", QString::number(_longitude,'f', 3));
    query.bindValue(":lati", QString::number(_latitude,'f', 3));
    query.bindValue(":time", QString::number(_time));
    query.bindValue(":check", QString::number(_check));
    //query.prepare("insert into animals (longitude, latitude, animal_date_time, on_server) values (3,3,3,0)");
    if(!query.exec()){
            qDebug() << "error insert into " << TA;
            qDebug() << query.lastError().text();
            return false;
        } else {

            return true;
        }
    return false;
}

//если с бд опять что-то случится
bool database::createTable(){
    QSqlQuery query;
    if(!query.exec("CREATE TABLE " TA " ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                        TA_longitude "double not null, "
                        TA_latitude "double not null, "
                        TA_time "integer not null, "
                        TA_check "integer not null)")){
        qDebug() << "DataBase: error of create " << TA;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}


//void database::connectToDataBase()
//{


//    if(!QFile(DATABASE_NAME).exists()){
//        this->restoreDataBase();
//    }
//    else{
//        this->openDataBase();
//    }
//}
