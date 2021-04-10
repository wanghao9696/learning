#include<iostream>

using namespace std;

class Cube{
public:
    // 获取立方体的长、宽、高
    void setcube_L(int rel_L){
        m_L = rel_L;
    }
    void setcube_W(int rel_W){
        m_W = rel_W;
    }
    void setcube_H(int rel_H){
        m_H = rel_H;
    }

    // 获取立方体的长、宽、高
    int getcube_L(){
        return m_L;
    }
    int getcube_W(){
        return m_W;
    }
    int getcube_H(){
        return m_H;
    }

    // 获取立方体面积
    int cube_S(){
        return 2 * m_L * m_W + 2 * m_L * m_H + 2 * m_H * m_W;
    }

    // 获取立方体体积
    int cube_V(){
        return m_L * m_W * m_H;
    }

    //成员函数判断两个立方体是否相等
    bool isSameByClass(Cube & c){
        if(m_L == c.getcube_L() && m_W == c.getcube_W() && m_H == c.getcube_H()){
            return true;
        }
        return false;
    }

private:
    int m_L;
    int m_W;
    int m_H;

};

// 全局函数判断两个立方体是否相等
bool isSame(Cube &c1, Cube &c2){
    if(c1.getcube_L() == c2.getcube_L() && c1.getcube_W() == c2.getcube_W() && c1.getcube_H() == c2.getcube_H()){
        return true;
    }
    return false;
}

int main(){
    Cube c1;
    c1.setcube_L(2);
    c1.setcube_W(5);
    c1.setcube_H(4);

    Cube c2;
    c2.setcube_L(2);
    c2.setcube_W(3);
    c2.setcube_H(4);

    bool ret = c1.isSameByClass(c2);
    if(ret){
        cout << "1 is equal" <<endl;
    }
    else{
        cout << "1 is not equal" <<endl;
    }

    bool ret2 = isSame(c1, c2);
    if(ret2){
        cout << "2 is equal" <<endl;
    }
    else{
        cout << "2 is not equal" <<endl;
    }

    return 0;
}