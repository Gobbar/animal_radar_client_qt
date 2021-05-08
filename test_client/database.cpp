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



// возвращает кол-во строк заданного запроса
int database::getSize(QString str){
    QSqlQuery ind(str);

    ind.next();
    qDebug()<<ind.value(0).toInt()<<"a";
    return ind.value(0).toInt();
}

//возвращает массив объектов класса animal, полученный из заданного запроса к бд
animal* database::getAnimals(QString str){

    QSqlQuery query(str);


    animal* a=new animal[getSize("select count(*) from animals;")];

    int i=0;
    while (query.next()){
           animal A(query.value(1).toDouble(), query.value(2).toDouble(), query.value(3).toInt(), query.value(4).toBool(), query.value(0).toInt());
           a[i]=A;
           qDebug()<<A.get_latitude();
           ++i;
    }
    return a;
}




// отправляет данные в бд, но на вход получает отдельные поля, а не класс
// работает в main.qml
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
