#include"SortTestHelper.h"
#include"SelectionSort.h"
#include"InsertionSort.h"

int main()
{
    int n = 10000;
    // int* arr = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr = SortTestHelper::generateNearlyOrderArray(n, 10);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);
    SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);

    delete[] arr;
    delete[] arr2;

    return 0;
}