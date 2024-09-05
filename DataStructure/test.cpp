#include <iostream>

using namespace std;

void give_address(int *(&a), int *b)
{
    a = b;
}

int main(int argc, char const *argv[])
{
    int a = 10, b = 20;
    int *c = &a, *d = &b;
    int &r = a;
    int *(&p) = c;

    give_address(c, d);
    cout << c << endl
         << d << endl
         << *c << endl
         << *d;
         

    return 0;
}
