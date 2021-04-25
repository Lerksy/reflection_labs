#ifndef LAB1_H
#define LAB1_H

#include <QObject>
#include <QDateTime>
#include <QList>


class lesson : public QObject{

    Q_OBJECT

public:
    Q_INVOKABLE lesson(QString name, qint32 auditory, QDateTime timeOfStart);
    Q_INVOKABLE lesson(const lesson& old);
    Q_INVOKABLE lesson operator=(const lesson& old);
    Q_INVOKABLE QString timeToStart();
    Q_INVOKABLE QString getStat();

private:
    QString lessonName;
    qint32 audNum;
    QDateTime timeOfStart;
    QString convert(qint64 time);
};

class timeTable : public QObject{

    Q_OBJECT

public:
    Q_INVOKABLE timeTable();
    Q_INVOKABLE bool addPair(lesson pair);
    Q_INVOKABLE QString getTimeTable();

private:
    QList<lesson> listOfPairs;
};


#endif // LAB1_H
