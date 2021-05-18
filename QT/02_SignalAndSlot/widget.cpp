#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>

// Teacher 类 老师类
// Student 类 学生类
// 下课后，老师会触发一个信号，饿了，学生响应信号，请客吃饭

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建一个老师对象
    this->zt = new Teacher(this);

    // 创建一个学生对象
    this->st = new Student(this);

//    // 老师饿了 学生请客的连接
//    connect(zt, &Teacher::hungry, st, &Student::treat);

//    // 调用下课函数
//    classIsOver();

    // 连接带参数的 信号和槽
    // 指针->地址
    // 函数指针->函数地址
    void(Teacher:: *teacherSignal)(QString) = &Teacher::hungry;
    void(Student:: *studentSignal)(QString) = &Student::treat;
    connect(zt, teacherSignal, st, studentSignal);
    classIsOver();


    // 点击一个下课按钮，再触发下课
    QPushButton * btn = new QPushButton("下课", this);
    // 重置窗口大小
    this->resize(600, 400);
    // 点击按钮，触发下课
    connect(btn, &QPushButton::clicked, this, &Widget::classIsOver);

}

void Widget::classIsOver()
{
    // 下课函数，调用后，触发老师饿了的信号
//    emit zt->hungry();
    emit zt->hungry("宫爆鸡丁");
}

Widget::~Widget()
{
    delete ui;
}

