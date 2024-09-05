#include <stdio.h>
#include <stdlib.h>

typedef int Etype;

typedef struct Queue
{
    Etype *elements;
    int rear, front, len;
} Queue;

void init_queue(Queue *q, int len)
{
    q->elements = (Etype *)calloc(len, sizeof(Etype));
    q->rear = q->front = 0;
    q->len = len;
}

int isEmpty(Queue q)
{
    return q.front == q.rear;
}

int add(Queue *q, int data)
{
    if (q->rear == q->len)
        return -1;
    q->elements[q->rear++] = data;
    return 1;
}

int pop(Queue *q)
{
    if (isEmpty(*q))
        return -1;
    return q->elements[q->front++];
}

int main(int argc, char const *argv[])
{
    Queue q;
    init_queue(&q, 10);
    add(&q, 1);
    add(&q, 2);
    add(&q, 3);
    add(&q, 4);
    add(&q, 5);
    for (int i = q.front; i < q.rear; i++)
    {
        printf("%d\t", q.elements[i]);
    }
    printf("\n");
    int ret = pop(&q);
    printf("del:%d\n", ret);
    for (int i = q.front; i < q.rear; i++)
    {
        printf("%d\t", q.elements[i]);
    }
    printf("\n");
    return 0;
}
