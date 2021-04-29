#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> v1;
    
    for(int i=0; i<100; i++)
    {
        v1.push_back(i);
    }
    cout << "v1的容量为：" << v1.capacity() << endl;

    v1.reserve(1000);

    cout << "v1的容量为：" << v1.capacity() << endl;

    return 0;
}