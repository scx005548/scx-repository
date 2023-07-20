#ifndef QPERSON_H
#define QPERSON_H

#include <QObject>

#include<qstring.h>
class QPerson : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name MEMBER mName)
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChange)
    Q_PROPERTY(QString sex MEMBER mSex)
    Q_PROPERTY(int score MEMBER mscore)

public:
    explicit QPerson(QString name, QObject *parent = nullptr);
    ~QPerson();
    quint8 age();
    void setAge(quint8 ageValue);
    void inoAge();  //年龄自增一
signals:
    void ageChange(quint8 ageValue);
public slots:

private:
    QString mName;    //姓名
    quint8 mAge=10;    //年龄
    QString mSex;
    quint8 mscore;

};

#endif // QPERSON_H
