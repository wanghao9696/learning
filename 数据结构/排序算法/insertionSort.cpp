// 插入排序
#include<iostream>
#include<vector>

#include"SortTestHelper.h"

using namespace std;

void insertionSort(vector<int> & v, int n)
{
    for(int i=1; i<n; i++)
    {
        int temp = v[i];
        int j;
        for(j=i; j>0 && v[j-1] > temp; j--)
        {
            v[j] = v[j-1];
        }
        v[j] = temp; // 内层循环比较完之后再做赋值操作
    }
}

int main()
{
    int n = 10000;
    vector<int> v = generateRandomVector(n, 1, n);

    testSort("insertionSort", insertionSort, v, n);

    return 0;
}