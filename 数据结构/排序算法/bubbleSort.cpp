#include<iostream>
#include<vector>

#include"SortTestHelper.h"

using namespace std;

void bubbleSort(vector<int> & v, int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(v[j] > v[j+1])
            {
                swap(v[j], v[j+1]);
            }
        }
    }
}

int main()
{
    int n = 10000;
    vector<int> v = generateRandomVector(n, 1, n);

    // bubbleSort(v, n);
    testSort("bubbleSort", bubbleSort, v, n);

    return 0;
}