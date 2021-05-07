#include<iostream>
#include<vector>

#include"SortTestHelper.h"

using namespace std;

void __merge(vector<int> & v, int l, int mid, int r)
{
    vector<int> aux;
    for(int i=l; i<=r; i++)
    {
        aux[i-l] = v[i];
    }

    int i = l, j = mid + 1;
    for(int k=l; k<=r; k++)
    {
        if(i > mid)
        {
            v[k] = aux[j-l];
            j++;
        }
        else if(j > r)
        {
            v[k] = aux[i-l];
            i++;
        }
        else if(aux[i-l] < aux[j-l])
        {
            v[k] = aux[i-l];
            i++;
        }
        else
        {
            v[k] = aux[j-l];
            j++;
        }
    }
}

void __mergeSort(vector<int> & v, int l, int r)
{
    if(l>=r)
        return;

    int mid = (l + r) / 2;
    __mergeSort(v, l, mid);
    __mergeSort(v, mid+1, r);
    __merge(v, l, mid, r);
}

void mergeSort(vector<int> & v, int n)
{
    __mergeSort(v, 0, n-1);
}

int main()
{
    int n = 10000;
    vector<int> v = generateRandomVector(n, 1, n);

    testSort("selectionSort", mergeSort, v, n);

    return 0;

    return 0;
}