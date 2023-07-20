#include "qperson.h"
#include <qdebug.h>
QPerson::QPerson(QString name,QObject *parent) :
    QObject(parent),mName(name)
{

}

QPerson::~QPerson()
{
    qDebug()<<"QPerson对象销毁。";
}

quint8 QPerson::age()
{
    return mAge;
}

void QPerson::setAge(quint8 ageValue)
{
    if(ageValue!=mAge){
        mAge=ageValue;
        emit ageChange(mAge);
    }
}

void QPerson::inoAge()
{
    if(mAge<120){
        mAge++;
        emit ageChange(mAge);
    }
}
