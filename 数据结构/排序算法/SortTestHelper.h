#include<iostream>
#include<vector>
#include<ctime>
#include<cassert>

using namespace std;

// 生成有n个元素的随机数组，没个元素的随机范围为[rangeL, rangeR]
vector<int> generateRandomVector(int n, int rangeL, int rangeR)
{
    assert(rangeL <= rangeR);
    vector<int> v;
    srand(time(NULL));
    for(int i=0; i<n; i++)
    {
        v.push_back(rand() % (rangeR - rangeL + 1) + rangeL);
    }
    return v;
}

// 判断排序是否成功
bool isSorted(vector<int> v, int n)
{
    for(int i=0; i<n-1; i++)
    {
        if(v[i] > v[i+1])
        {
            return false;
        }
    }
    return true;
}

// 计算算法排序时间
void testSort(string sortName, void(*sort)(vector<int> &, int), vector<int> v, int n)
{
    clock_t startTime = clock();
    sort(v, n);
    clock_t endTime = clock();

    assert(isSorted(v, n));

    cout << sortName << ": " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    return;
}