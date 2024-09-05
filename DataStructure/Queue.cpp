#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int *Elements;
    int length;
    int capacity;
} queue;

void init_queue(queue *q)
{
    q->capacity = 10;
    q->length = 0;
    q->Elements = (int *)malloc(10 * sizeof(int));
}

void print_list(queue q)
{
    printf("Length:%d\n", q.length);
    printf("Capacity:%d\n", q.capacity);
    printf("Elements:");
    for (int i = 0; i < q.length; i++)
    {
        printf("%d  ", q.Elements[i]);
    }
    printf("\n");
    printf("\n");
}

int add_num(queue *q, int num)
{
    if (q->length == q->capacity)
        return -1;
    q->Elements[q->length] = num;
    q->length++;
    return q->length;
}

int pop_num(queue *q)
{
    if (q->length == 0)
        return -1;
    int poped = q->Elements[0];
    for (int i = 1; i < q->length; i++)
    {
        q->Elements[i - 1] = q->Elements[i];
    }
    q->length--;
    return poped;
}


int extend(queue *q, int expand)
{
    int *temp;
    q->Elements = (int *)realloc(q->Elements, sizeof(int) * (expand + q->capacity));
    q->capacity += expand;
    return q->capacity;
}

int main(int argc, char *argv[])
{
    queue q;
    init_queue(&q);
    print_list(q);
    add_num(&q, 1);
    add_num(&q, 2);
    add_num(&q, 3);
    add_num(&q, 4);
    add_num(&q, 5);
    print_list(q);
    extend(&q, 10);
    print_list(q);
    while (q.length != 0)
    {
        printf("the poped num is %d\n", pop_num(&q));
        print_list(q);
    }
    printf("the poped num is %d\n", pop_num(&q));
    print_list(q);
    return 0;
}
