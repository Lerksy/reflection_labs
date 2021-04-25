#include <QCoreApplication>
#include <QMetaObject>
#include <QMetaMethod>
#include "lab1.h"
#include "lab2.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //lab1 output section
    timeTable myTimeTable;
    myTimeTable.addPair(lesson("Алгебра", 103, QDateTime(QDate(), QTime())));
    myTimeTable.addPair(lesson("Геометрия", 210, QDateTime(QDate(), QTime())));
    myTimeTable.addPair(lesson("Прокрастинация", 666, QDateTime(QDate(), QTime())));
    std::cout<< myTimeTable.getTimeTable().toStdString();

    const QMetaObject *metaTimeTable = myTimeTable.metaObject();

    std::cout<<"Название класса: "<< metaTimeTable->className()<<std::endl;
    for(qint32 i = metaTimeTable->methodOffset(); i < metaTimeTable->methodCount(); i++){
        std::cout<<metaTimeTable->method(i).methodSignature().toStdString()<<std::endl;
    }
    bool returnedVal;
    QMetaObject::invokeMethod(&myTimeTable,
                              "addPair",
                              Qt::DirectConnection,
                              Q_RETURN_ARG(bool,returnedVal),
                              Q_ARG(lesson, lesson("Информатика", 35, QDateTime(QDate(), QTime()))));
    QString newTimeTableText;
    QMetaObject::invokeMethod(&myTimeTable,
                              "getTimeTable",
                              Qt::DirectConnection,
                              Q_RETURN_ARG(QString, newTimeTableText));
    std::cout<<std::endl<<std::endl<<newTimeTableText.toStdString();

    //lab2 output section
    QTest::qExec(new lab2);


    return a.exec();
}
