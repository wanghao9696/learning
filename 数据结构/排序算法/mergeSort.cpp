#include"mergeSort.h"
#include"SortTestHelper.h"
#include"SelectionSort.h"
#include"InsertionSort.h"

int main()
{
    int n = 10000;

    // int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr1 = SortTestHelper::generateNearlyOrderArray(n, 10);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("merge Sort", mergeSort, arr1, n);

    delete[] arr1;
    delete[] arr2;

    return 0;
}