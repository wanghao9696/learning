// 选择排序
#include<iostream>
#include<vector>

#include"SortTestHelper.h"

using namespace std;

void selectionSort(vector<int> & v, int n)
{
    for(int i=0; i<n; i++)
    {
        // 寻找[i, n)区间里的最小值
        for(int j=i+1; j<n; j++)
        {
            if(v[j] < v[i])
            {
                swap(v[j], v[i]);
            }
        }
    }
}

int main()
{
    int n = 10000;
    vector<int> v = generateRandomVector(n, 1, n);

    testSort("selectionSort", selectionSort, v, n);

    return 0;
}