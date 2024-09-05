#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int *a = new int[20];
    for (int i = 0; i < 20; i++)
    {
        a[i] = i;
    }

    for (int i = 0; i < 20; i++)
    {
        cout << a[i] << "\t";
    }

    cout << endl;
    cout << a << endl;
    delete[] a;
    cout << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << a[i] << "\t";
    }

    return 0;
}
