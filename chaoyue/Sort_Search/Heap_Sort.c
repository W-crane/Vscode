#include <stdio.h>
#include <stdlib.h>
#include "method.h"

int is_max_heap(int *arr, int length)
{
    int i;
    for (i = 0; 2 * i + 1 < length; i++)
    {
        if (2 * i + 2 < length)
        {
            if (arr[2 * i + 1] > arr[i])
                return 2 * i + 1;
            else if (arr[2 * i + 2] > arr[i])
                return 2 * i + 2;
        }
        else
        {
            if (arr[2 * i + 1] > arr[i])
                return 2 * i + 1;
        }
    }
    return -1;
}

int build_max_heap(int *arr, int length)
{
    int loc = is_max_heap(arr, length), temp;
    while (loc != -1)
    {
        temp = arr[loc];
        arr[loc] = arr[(loc - 1) / 2];
        arr[(loc - 1) / 2] = temp;
        loc = is_max_heap(arr, length);
    }
    temp = arr[0];
    arr[0] = arr[length - 1];
    arr[length - 1] = temp;
    return length - 1;
}

void heap_sort(int *arr, int length)
{
    while (length > 1)
        length = build_max_heap(arr, length);
}

int main(int argc, char const *argv[])
{
    int arr[10];
    init_arr(arr, 1);
    print_arr(arr, 10);
    heap_sort(arr, 10);
    print_arr(arr, 10);
    return 0;
}
