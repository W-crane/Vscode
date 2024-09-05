#include <stdio.h>
#include <stdlib.h>

typedef int Etype;
typedef struct Stack
{
    Etype *elements;
    int capacity;
    int top;
} Stack;

void init(Stack *s, int capacity)
{
    s->elements = (Etype *)malloc(sizeof(Stack) * capacity);
    s->capacity = capacity;
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int add(Stack *s, int data)
{
    if (s->top == s->capacity - 1)
        return -1;
    s->elements[++s->top] = data;
    return s->top;
}

int pop(Stack *s)
{
    if (isEmpty(s))
        return -1;
    s->top--;
    return s->elements[s->top + 1];
}

int main(int argc, char const *argv[])
{
    Stack s;
    init(&s, 10);
    add(&s, 1);
    add(&s, 2);
    add(&s, 3);
    add(&s, 4);
    add(&s, 5);
    for (int i = 0; i <= s.top; i++)
    {
        printf("%d\t", s.elements[i]);
    }
    printf("\n");
    printf("%d\n", pop(&s));
    for (int i = 0; i <= s.top; i++)
    {
        printf("%d\t", s.elements[i]);
    }

    return 0;
}
