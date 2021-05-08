#ifndef ANIMAL_H
#define ANIMAL_H

#include <QObject>
#include <QDateTime>

class animal : public QObject
{
    Q_OBJECT
private:
    int id;
    double longitude;
    double latitude;
    int time;
    bool check;

public:
    explicit animal(QObject *parent = nullptr);

    animal (double _longitude, double _latitude, int _time, bool _check=0, int _id=0){
        id=_id;
        longitude=_longitude;
        latitude=_latitude;
        time = _time;
        check=_check;
    }
    void operator = (animal &A){
        id=A.get_id();
        longitude=A.get_longitude();
        latitude=A.get_latitude();
        time = A.get_time();
        check=A.on_server();
    }

public slots:
    int get_id(){return id;}
    double get_longitude(){return longitude;}
    double get_latitude(){return latitude;}
    int get_time(){return time;}
    bool on_server(){return check;}

    void set_id(int _id){id = _id;}
    void set_longitude(double _longitude){longitude = _longitude;}
    void set_latitude(int _latitude){latitude = _latitude;}
    void set_time(int _time){time = _time;}
    void set_check(int _check){check = _check;}
    //устанавливает текущее время
    void set_time(){
        time = QDateTime::currentSecsSinceEpoch();
        qDebug()<<time;
    }
};

#endif // ANIMAL_H
