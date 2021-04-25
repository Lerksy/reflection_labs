#include "lab2.h"

lab2::lab2()
{

}

void lab2::addPair(){
    timeTable testTable;
    QCOMPARE(testTable.addPair(lesson("Предмет 1", 12, QDateTime())), true);
    QCOMPARE(testTable.addPair(lesson("Предмет 2", 13, QDateTime())), true);
    QCOMPARE(testTable.addPair(lesson("Предмет 3", 14, QDateTime())), true);
    QCOMPARE(testTable.addPair(lesson("Предмет 4", 15, QDateTime())), true);
    QCOMPARE(testTable.addPair(lesson("Предмет 5", 16, QDateTime())), true);
    QCOMPARE(testTable.addPair(lesson("Предмет 6", 17, QDateTime())), false);
}
