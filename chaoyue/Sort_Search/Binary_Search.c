#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int binary_search(int *arr, int length, int num);
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d\n", binary_search(arr, 10, 1));
    return 0;
}

int binary_search(int *arr, int length, int num)
{
    int left = 0, right = length - 1, mid = (left + right) / 2;
    while (left <= right)
    {
        if (arr[mid] == num)
            return mid;
        else if (arr[mid] > num)
            right = mid - 1;
        else
            left = mid + 1;
        mid = (left + right) / 2;
    }
    return -1;
}
