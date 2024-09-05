#include <stdio.h>
#include <stdlib.h>
#include "method.h"

int merge_list(int *list_1, int len_1, int *list_2, int len_2, int *new_list)
{
    int i = 0, j = 0, k = 0;
    while (i < len_1 && j < len_2)
        new_list[k++] = (list_1[i] <= list_2[j]) ? list_1[i++] : list_2[j++];
    while (i < len_1)
        new_list[k++] = list_1[i++];
    while (j < len_2)
        new_list[k++] = list_2[j++];
    return len_1 + len_2;
}

int merge_sort(int *arr, int length)
{
    int *temp = (int *)malloc(sizeof(int) * length);
    int i, total_length = 0, each_length = 1, len_1, len_2;

    while (total_length < length)
    {
        i = 0;
        while (i < length)
        {
            len_1 = (i + each_length) < length ? each_length : length - i;
            len_2 = (len_1 != each_length) ? 0 : (i + 2 * each_length) < length ? each_length
                                                                                : length - i - each_length;
            total_length = merge_list(arr + i, len_1, arr + i + len_1, len_2, temp + i);
            i += total_length;
        }
        each_length *= 2;
        for (int j = 0; j < length; j++)
        {
            arr[j] = temp[j];
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[10];
    init_arr(arr, 1);
    print_arr(arr, 10);
    merge_sort(arr, 10);
    print_arr(arr, 10);
    return 0;
}
