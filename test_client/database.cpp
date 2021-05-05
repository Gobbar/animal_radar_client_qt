#include "database.h"


database::database(QObject *parent) : QObject(parent)
{

}

database::~database(){

}

void database::connectToDataBase()
{



    if(!QFile(DATABASE_NAME).exists()){
        QFile::copy(":/" DATABASE_NAME , DATABASE_NAME);
    }
    this->openDataBase();
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
animal* database::getAnimals(){

    QSqlQuery query("select * from "+QString(TA)+";");


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
