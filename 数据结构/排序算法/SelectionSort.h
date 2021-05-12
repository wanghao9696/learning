#include<iostream>

using namespace std;

template<typename T>
void selectionSort(T arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        int minIndex = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}