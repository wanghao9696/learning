#include "student.h"
#include<QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug() << "请老师吃饭";
}

void Student::treat(QString foodName)
{
    // QString 转化为 char*
    //   QByteArray (.toUtf())  再转成 char* (.data())
    qDebug() << "请老师吃饭，老师要吃：" << foodName.toUtf8().data();
}
