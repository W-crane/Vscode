#include <stdio.h>
#include <stdlib.h>

typedef int Etype;

int main(int argc, char const *argv[])
{
    Etype queue[10] = {0};
    Etype list[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int front = 0, rear = 0;
    while (rear < 10)
    {
        queue[rear] = list[rear];
        rear++;
    }
    while (front != rear)
    {
        printf("%d\t", queue[front++]);
    }

    return 0;
}