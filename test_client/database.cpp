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

QVector<animal> database::getAnimals(){
    QVector<animal> animals;
    QSqlQuery query("select * from "+QString(TA)+";");

    while (query.next()){
        animal A(query.value(0).toInt(), query.value(1).toDouble(), query.value(2).toDouble(), query.value(3).toInt(), query.value(4).toBool());
        qDebug()<<A.get_latitude();
    }
//    for (QVector<animal>::Iterator it = animals.begin(); it!=animals.end();++it){
//        qDebug()<<it->get_id()<<" "<<it->get_time();
//    }
    return animals;
}
