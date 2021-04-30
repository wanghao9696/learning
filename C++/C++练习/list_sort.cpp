#include<iostream>
#include<list>
#include<string>

using namespace std;

class Person
{
public:
    Person(string name, int age, int height)
    {
        this->m_Name = name;
        this->m_Age = age;
        this->m_Height = height;
    }
public:
    string m_Name;
    int m_Age;
    int m_Height;
};

bool ComparePerson(Person & p1, Person & p2)
{
    if(p1.m_Age == p2.m_Age)
    {
        return p1.m_Height > p2.m_Height;
    }
    else
    {
        return p1.m_Age < p2.m_Age;
    }
}

void test01()
{
    list<Person> l;
    Person p1("刘备", 35, 175);
    Person p2("曹操", 45, 180);
    Person p3("孙权", 40, 170);
    Person p4("赵云", 25, 190);
    Person p5("张飞", 35, 160);
    Person p6("关羽", 35, 200);

    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);
    l.push_back(p6);

    for(list<Person>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout << "姓名：" << it->m_Name << "  年龄：" << it->m_Age << "  身高：" << it->m_Height << endl;
    }

    cout << "------------------------" << endl;

    l.sort(ComparePerson);

    for(list<Person>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout << "姓名：" << it->m_Name << "  年龄：" << it->m_Age << "  身高：" << it->m_Height << endl;
    }
}

int main()
{
    test01();

    return 0;
}