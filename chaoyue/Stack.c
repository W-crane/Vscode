#include <stdio.h>
#include <stdlib.h>

typedef int Etype;

int main(int argc, char const *argv[])
{
    Etype stack[10] = {0};
    Etype list[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int top = -1;
    while (top != 9)
    {
        stack[++top] = list[top];
    }
    while (top != -1)
    {
        printf("%d\t", stack[top--]);
    }
    return 0;
}
