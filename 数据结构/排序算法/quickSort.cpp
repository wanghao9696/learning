#include<iostream>
#include<vector>

#include"SortTestHelper.h"

using namespace std;

int __partition(vector<int> & v, int l, int r)
{
    int p = v[l];

    int j = l;
    for(int i=l+1; i<=r; i++)
    {
        if(v[i] < p)
        {
            swap(v[j+1], v[i]);
            j++;
        }
    }

    swap(v[l], v[j]);

    return j;
}

void __quickSort(vector<int> & v, int l, int r)
{
    if(l >= r)
        return;
    
    int p = __partition(v, l, r);
    __quickSort(v, l, p-1);
    __quickSort(v, p+1, r);
}

void quickSort(vector<int> & v, int n)
{
    __quickSort(v, 0, n-1);
}

int main()
{
    int n = 10000;
    vector<int> v = generateRandomVector(n, 1, n);

    testSort("quickSort", quickSort, v, n);

    return 0;
}