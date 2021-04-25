#ifndef LAB2_H
#define LAB2_H

#include <QObject>
#include <QTest>
#include "lab1.h"

class lab2: public QObject{
    Q_OBJECT
public:
    lab2();

private slots:
    void addPair();
};

#endif // LAB2_H
