#include <stdio.h>
#include <stdlib.h>

void init_arr(int *arr, int mode)
{
    if (mode == 0)
    {
        for (int i = 0; i < 10; i++)
        {
            arr[i] = i + 1;
        }
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            arr[i] = rand() % 100 + 1;
        }
    }
}

void print_arr(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}