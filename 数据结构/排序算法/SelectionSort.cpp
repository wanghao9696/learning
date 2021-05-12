#include"Student.h"
#include"SelectionSort.h"
#include"SortTestHelper.h"

int main()
{
    int n = 10000;
    int* arr = SortTestHelper::generateRandomArray(n, 0, n);

    SortTestHelper::testSort("selectionSort", selectionSort, arr, n);

    delete[] arr;

    // Student d[4] = {{"d", 90}, {"c", 100}, {"e", 95}, {"b", 95}};
    // selectionSort(d, 4);
    // for(int i=0; i<4; i++)
    // {
    //     cout << d[i];
    // }

    return 0;
}