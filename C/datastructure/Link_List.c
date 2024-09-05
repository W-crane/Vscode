#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Etype;

typedef struct LList
{
    Etype data;
    struct LList *next;
} LList;

void init(LList *list)
{
    list->next = NULL;
}

void add_head(LList *l, int data)
{
    LList *new_node = (LList *)malloc(sizeof(LList));
    new_node->data = data;
    new_node->next = l->next;
    l->next = new_node;
}

void add_back(LList *l, int data)
{
    LList *new_node = (LList *)malloc(sizeof(LList));
    new_node->data = data;
    new_node->next = NULL;
    while (l->next != NULL)
        l = l->next;
    l->next = new_node;
}

Etype pop(LList *l)
{
    int res;
    if (l->next == NULL)
        return -1;
    while (l->next->next != NULL)
        l = l->next;
    res = l->next->data;
    l->next = NULL;
    return res;
}

Etype pop_head(LList *l)
{
    if (l->next == NULL)
        return -1;
    int res = l->next->data;
    l->next = l->next->next;
    return res;
}

int del_first_num(LList *l, int data)
{
    if (l->next == NULL)
        return -1;
    while (l->next != NULL && l->next->data != data)
    {
        l = l->next;
    }
    if (l->next == NULL)
        return -1;
    l->next = l->next->next;
    return 1;
}

int isEmpty(LList l)
{
    return l.next == NULL;
}

int index(LList *l, int loc)
{
    // loc：索引，起始为0
    while (l->next != NULL && loc >= 0)
    {
        l = l->next;
        loc--;
    }
    if (l->next == NULL && loc >= 0)
        return -1;
    return l->data;
}

void print_list(LList *l)
{
    l = l->next;
    while (l != NULL)
    {
        printf("%d\t", l->data);
        l = l->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    LList l;
    init(&l);
    add_head(&l, 1);
    add_head(&l, 2);
    add_head(&l, 3);
    add_head(&l, 4);
    add_head(&l, 5);
    add_head(&l, 10);
    add_back(&l, 5);
    add_back(&l, 5);
    printf("%d\n", pop(&l));
    printf("%d\n", pop_head(&l));
    print_list(&l);
    del_first_num(&l, 2);
    print_list(&l);
    del_first_num(&l, 6);
    print_list(&l);
    printf("%d\n", index(&l, 5));
    return 0;
}
