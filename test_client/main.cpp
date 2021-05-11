#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "request.h"
#include "database.h"
#include "animal.h"
#include "animals_list.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    // подключение бд
    database database;
    database.connectToDataBase();


//    qRegisterMetaType<animal>();
//    qmlRegisterType<animal>("Custom.Types", 1, 0, "Animal");

    Request request("http://localhost:5000/", &database);

    // заводим массив
    animals_list animals;
    animals.set_n(database.getSize(QString(TA)));//записываем размер
    animals.set_list(database.getAnimals(QString(TA)));//помещаем в него все данные из таблицы в бд))))
    animal a(3,3,3); //тестовый объект

    //database.setAnimal("animals", {"latitude, longitude"}, {"3.15", "2.18"});
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("database", &database);
    engine.rootContext()->setContextProperty("animals", &animals);
    engine.rootContext()->setContextProperty("request", &request);
    engine.rootContext()->setContextProperty("a", &a);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
