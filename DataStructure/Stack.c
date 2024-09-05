#include <stdio.h>
#include <stdlib.h>

typedef struct SStack
{
    int data;
    struct SStack *next;
} SStack;

void init_stack(SStack *s)
{
    s->next = NULL;
    s->data = -1;
}

void insert_node(SStack *s, int data)
{
    SStack *new_node = (SStack *)malloc(sizeof(SStack));
    SStack *move = s;
    new_node->data = data;
    if (move->next == NULL)
    {
        s->next = new_node;
        new_node->next = s;
        return;
    }
    while (move->next != s)
        move = move->next;
    new_node->next = s;
    move->next = new_node;
    return;
}

int print_stack(SStack *s)
{
    if (s->next == NULL)
        return -1;
    SStack *move = s->next;
    while (move->next != s)
    {
        printf("%d-->", move->data);
        move = move->next;
    }
    printf("%d", move->data);
    return 0;
}

void merge_two_list(SStack *s1, SStack *s2)
{
    SStack *move1 = s1, *move2 = s2;
    while (move1->next != s1 && move2->next != s2)
    {
        move1 = move1->next;
        move2 = move2->next;
    }
    while (move1->next != s1)
        move1 = move1->next;
    while (move2->next != s2)
        move2 = move2->next;
    move1->next = s2->next;
    move2->next = s1;
    free(s2);
}
void move_nodes(SStack *s, int steps)
{
    SStack *move = s;
    int i = 0;
    if (s->next == NULL)
        return;
    while (move->next != s)
        move = move->next;
    move->next = move->next->next;
    for (i = 0; i < steps; i++)
        move = move->next;
    s->next = move->next;
    move->next = s;
}

int main(int argc, char const *argv[])
{
    SStack s1, s2;
    init_stack(&s1);
    insert_node(&s1, 1);
    insert_node(&s1, 2);
    insert_node(&s1, 3);
    insert_node(&s1, 4);
    insert_node(&s1, 5);
    insert_node(&s1, 6);
    insert_node(&s1, 7);
    insert_node(&s1, 8);
    init_stack(&s2);
    insert_node(&s2, 1);
    insert_node(&s2, 2);
    insert_node(&s2, 3);
    insert_node(&s2, 4);
    insert_node(&s2, 5);
    insert_node(&s2, 6);
    insert_node(&s2, 7);
    insert_node(&s2, 8);
    merge_two_list(&s1, &s2);
    print_stack(&s1);

    return 0;
}
