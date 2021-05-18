#ifndef MYPUSHBOTTON_H
#define MYPUSHBOTTON_H

#include <QPushButton>

class MyPushBotton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushBotton(QWidget *parent = nullptr);

    ~MyPushBotton();

signals:

};

#endif // MYPUSHBOTTON_H
