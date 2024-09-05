#include <stdio.h>
#include "method.h"

int take_pivot(int *arr, int low, int high)
{

    int pivot = arr[low];
    while (low < high)
    {
        for (; high > low; high--)
        {
            if (arr[high] <= pivot)
            {
                arr[low] = arr[high];
                break;
            }
        }
        for (; low < high; low++)
        {
            if (arr[low] > pivot)
            {
                arr[high] = arr[low];
                break;
            }
        }
    }
    arr[low] = pivot;
    return low;
}
void quick_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int i;
        i = take_pivot(arr, low, high);
        quick_sort(arr, low, i - 1);
        quick_sort(arr, i + 1, high);
    }
}

int main(int argc, char const *argv[])
{
    int arr[10];
    init_arr(arr, 1);
    print_arr(arr, 10);
    quick_sort(arr, 0, 9);
    print_arr(arr, 10);
    return 0;
}
