#include<iostream>
#include<string>

using namespace std;

class Caculator{
public:

    int getResult(string oper)
    {
        if(oper == "+")
        {
            return m_Num1 + m_Num2;
        }
        else if(oper == "-")
        {
            return m_Num1 - m_Num2;
        }
        else if(oper == "*")
        {
            return m_Num1 * m_Num2;
        }
    }

    int m_Num1;
    int m_Num2;
};

void test01()
{
    // 创建计算器对象
    Caculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 10;

    cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl;
}

// 利用多态实现计算器
// 多态好处：
    // 1.组织结构清晰；
    // 2.可读性强；
    // 3.方便后期的扩展和维护
// 先定义一个抽象计算器类
class AbstractCalculator
{
public:
    virtual int getResult()
    {
        return 0;
    }

    int m_Num1;
    int m_Num2;

};

// 加法计算器
class AddCalculator: public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 + m_Num2;
    }
};

// 减法计算器
class SubCalculator: public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 - m_Num2;
    }
};

// 乘法计算器
class MulCalculator: public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 * m_Num2;
    }
};

void test02()
{
    // 多态使用条件
    // 父类指针或者引用指向子类对象

    // 加法运算
    AbstractCalculator * abc = new AddCalculator;
    abc->m_Num1 = 12;
    abc->m_Num2 = 12;

    cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;

    // 堆区数据用完后记得销毁
    delete abc;

    // 减法运算
    abc = new SubCalculator;
    abc->m_Num1 = 12;
    abc->m_Num2 = 12;

    cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;

    // 堆区数据用完后记得销毁
    delete abc;

    // 乘法运算
    abc = new MulCalculator;
    abc->m_Num1 = 12;
    abc->m_Num2 = 12;

    cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->getResult() << endl;

    // 堆区数据用完后记得销毁
    delete abc;
}


int main(){

    cout << "普通实现" << endl;
    test01();

    cout << "多态实现" << endl;
    test02();

    return 0;
}