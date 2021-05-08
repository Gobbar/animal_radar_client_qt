#ifndef ANIMALS_LIST_H
#define ANIMALS_LIST_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>

#include "animal.h"
#include <ctime>

class animals_list : public QObject
{
    Q_OBJECT
private:
    animal *a; //массив
    int n; //кол-во элементов массива
    int dt; //время последнего изменения
public:
    explicit animals_list(QObject *parent = nullptr);
//    animals_list(QSqlQuery q){
//        QSqlQuery query = q;

//        //a = new animal*[query.size()];
//        int i=0;
//        while (query.next()){
//               //a[i] = new animal(query.value(0).toInt(), query.value(1).toDouble(), query.value(2).toDouble(), query.value(3).toInt(), query.value(4).toBool());
//               qDebug()<<query.value(0).toInt();
//           }
//    }

public slots:
    void set_list(animal *_a){
        a = _a;
        qDebug()<<"sss"<<n;
    }
    void set_n(int _n){
        n=_n;
    }
    void set_dt(int _dt){
        dt=_dt;
    }
signals:

};
Q_DECLARE_METATYPE(animals_list);
#endif // ANIMALS_LIST_H
