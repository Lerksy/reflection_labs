#include "lab1.h"


lesson::lesson(QString name, qint32 auditory, QDateTime timeOfStart){
    this->lessonName = name;
    this->audNum = auditory;
    this->timeOfStart = timeOfStart;
}

lesson::lesson(const lesson &old){
    this->lessonName = old.lessonName;
    this->audNum = old.audNum;
    this->timeOfStart = old.timeOfStart;
}

lesson lesson::operator=(const lesson &old){
    return lesson(old);
}

QString lesson::timeToStart(){
    return QString("До пары осталось: %1").arg(convert(timeOfStart.secsTo(QDateTime::currentDateTimeUtc().toLocalTime())));
}

QString lesson::getStat(){
    QString returnable = "Дисциплина: %1\nНомер аудтории: %2\nДата и время начала: %3";
    return returnable
            .arg(lessonName)
            .arg(audNum)
            .arg(timeOfStart.toLocalTime().toString());
}

QString lesson::convert(qint64 time){
    qint64 hours, mins, secs;
    QString hTxt, mTxt, sTxt;
    QStringList returnableAparted;
    mins = time/60;
    secs = time % 60;
    hours = mins / 60;
    mins -= hours*60;
    hTxt = (hours%10 == 1 && hours != 11) ? "" :
    (hours%10 == 2 || hours%10 == 3 || hours%10 == 4) ? "а" : "ов";
    mTxt = (mins%10 == 1 && mins != 11) ? "а" :
    ((mins%10 == 2 || mins%10 == 3 || mins%10 == 4) && (mins != 12 && mins != 13 && mins != 14)) ? "ы" : "";
    sTxt = (secs%10 == 1 && secs != 11) ? "а" :
    ((secs%10 == 2 || secs%10 == 3 || secs%10 == 4) && (secs != 12 && secs != 13 && secs != 14)) ? "ы" : "";
    returnableAparted = (QString("%1 час%4 %2 минут%5 %3 секунд%6").arg(hours).arg(mins).arg(secs).arg(hTxt, mTxt, sTxt)).split(" ");
    if(hours == 0) returnableAparted.remove(0, 2);
    if(mins == 0) returnableAparted.remove(2, 2);
    if(secs == 0) returnableAparted.remove(4, 2);
    return returnableAparted.join(" ");
}

timeTable::timeTable(){
}

bool timeTable::addPair(lesson pair){
    if(listOfPairs.size() <= 5) {
        listOfPairs.append(pair);
        return true;
    }else return false;
}

QString timeTable::getTimeTable(){
    QString returnable;
    for(qint32 i = 0; i < listOfPairs.size(); i++){
        returnable += "Номер пары: " + QString::number(i) + "\n";
        returnable += listOfPairs[i].getStat() + "\n\n";
    }
    return returnable;
}
