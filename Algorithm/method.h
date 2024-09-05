#include <random>
#include <iostream>

using namespace std;

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
        cout << arr[i] << '\t';
    }
    cout << endl;
}