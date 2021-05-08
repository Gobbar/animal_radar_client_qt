#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

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

    // заводим массив
    animals_list animals;
    animals.set_list(database.getAnimals("select * from "+QString(TA)+";"));//помещаем в него все данные из таблицы в бд))))
    animals.set_n(database.getSize("select * from "+QString(TA)+";"));//записываем размер
    animal a(3,3,3); //тестовый объект



    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("database", &database);
    engine.rootContext()->setContextProperty("animals", &animals);
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
