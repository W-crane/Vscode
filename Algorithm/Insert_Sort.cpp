#include <iostream>
#include "method.h"

using namespace std;

void insert_sort(int *arr)
{
    int temp, i, j;
    for (i = 1; i < 10; i++)
    {
        temp = arr[i];
        for (j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
                continue;
            else
                break;
        }
        for (int k = i; k > j; k--)
        {
            arr[k] = arr[k - 1];
        }
        arr[j] = temp;
    }
}

void binary_insert_sort(int *arr)
{
    int temp, i, left, right, mid;
    for (i = 1; i < 10; i++)
    {
        left = 0;
        right = i;
        temp = arr[i];
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (arr[mid] == arr[i])
                break;
            if (arr[mid] > arr[i])
                right = mid - 1;
            else
                left = mid + 1;
        }

        for (int k = i; k > mid; k--)
        {
            arr[k] = arr[k - 1];
        }
        arr[mid] = temp;
    }
}

void insert_sort_by_step(int *arr, int step)
{
    int temp, i, j, l;
    for (l = 0; l < 10 / step; l++)
    {
        for (i = step + l; i < 10; i += step)
        {
            temp = arr[i];
            for (j = i % step; j < i; j += step)
            {
                if (arr[i] > arr[j])
                    continue;
                else
                    break;
            }
            for (int k = i; k > j; k -= step)
            {
                arr[k] = arr[k - step];
            }
            arr[j] = temp;
        }
    }
}

void shell_sort(int *arr)
{
    int step = 10;
    while (step >= 1)
    {
        insert_sort_by_step(arr, step);
        step /= 2;
    }
}

int main(int argc, char const *argv[])
{
    int arr[10];
    init_arr(arr, 1);
    print_arr(arr, 10);
    shell_sort(arr);
    print_arr(arr, 10);
    
    return 0;
}
