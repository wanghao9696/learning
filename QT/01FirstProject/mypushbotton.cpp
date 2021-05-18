#include"mypushbotton.h"
#include<QDebug>

MyPushBotton::MyPushBotton(QWidget *parent) : QPushButton(parent)
{
    qDebug() << "我的按钮类构造调用";
}

MyPushBotton::~MyPushBotton()
{
    qDebug() << "我的按钮类析构";
}
