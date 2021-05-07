#include<iostream>
#include<vector>

#include"heap.h"

using namespace std;

template<typename T>
void heapSort(T arr[], int n)
{
    MaxHeap<T> maxheap = MaxHeap<T>(n);
    for(int i=0; i<n; i++)
        maxheap.insert(arr[i]);
        
    for(int i=n-1; i>=0; i--)
        arr[i] = maxheap.extractMax();
}