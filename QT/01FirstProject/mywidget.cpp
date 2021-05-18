#include"mywidget.h"
#include<QPushButton> // 按钮头文件
#include"mypushbotton.h"
#include<QDebug>

// 命名规范
// 类名 首字母大写 单词和单词之间首字母大写
// 函数名 变量名称 首字母小写 单词和单词之间首字母大写
// 快捷键
// 运行 command r
// 编译 command b
// 字体缩放 command +(-)
// 整行移动 command shift 上(下)
// 自动对齐 command i

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    // 创建一个按钮
    QPushButton * btn = new QPushButton;
    // btn->show(); // show以顶层的方式弹出窗口控件

    btn->setParent(this); // 让btn对象 依赖在mywidget窗口中
    btn->setText("第一个按钮"); // 显示文本


    // 创建第二个按钮
    QPushButton *btn2 = new QPushButton("第二个按钮", this); // 按照控件大小创建窗口
//    btn2->resize(50, 50); // 设置按钮的大小
//    resize(600, 400); // 重置窗口大小，用户可拖拽
    setFixedSize(600, 400); // 设置固定窗口大小，用户不可拖拽
    btn2->move(100, 100); // 移动按钮
    setWindowTitle("第二个窗口");


    // 创建一个自己的按钮对象
    MyPushBotton *myBtn = new MyPushBotton;
    myBtn->setText("我的按钮");
    myBtn->move(200, 200);
    myBtn->setParent(this);

    // 需求 点击我的按钮 关闭窗口
    // 参数1 信号的发送者 参数2 发送的信号（函数的地址） 参数3 信号的接受者 参数4 处理的槽函数
    connect(myBtn, &QPushButton::clicked, this, &QWidget::close);


}

myWidget::~myWidget()
{
    qDebug() << "myWidget的析构调用";
}
