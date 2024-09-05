#include <stdio.h>
#include <stdlib.h>

typedef int Etype;

typedef struct LList
{
    Etype data;
    struct LList *next;
} LList;

void init_llist(LList *l)
{
    l->data = -1;
    l->next = NULL;
}

void add_head(LList *l, Etype data)
{
    LList *new_node = (LList *)malloc(sizeof(LList));
    new_node->data = data;
    new_node->next = l->next;
    l->next = new_node;
}

void add_back(LList *l, Etype data)
{
    LList *new_node = (LList *)malloc(sizeof(LList));
    new_node->data = data;
    new_node->next = NULL;
    LList *move = l;
    while (move->next != NULL)
        move = move->next;
    move->next = new_node;
}

void add_by_loc(LList *l, Etype data, int loc)
{
    if (loc < 1)
        return;

    int i = 1;
    LList *move = l;
    while (i < loc)
    {
        if (move == NULL)
            return;
        i++;
        move = move->next;
    }
    LList *new_node = (LList *)malloc(sizeof(LList));
    new_node->data = data;
    new_node->next = move->next;
    move->next = new_node;
}

int del_head(LList *l)
{
    if (l->next == NULL)
        return -1;
    LList *del_node = l->next;
    int res = del_node->data;
    l->next = del_node->next;
    free(del_node);
    return res;
}

int del_back(LList *l)
{
    if (l->next == NULL)
        return -1;
    LList *move = l;
    while (move->next->next != NULL)
    {
        move = move->next;
    }
    LList *del_node = move->next;
    int res = del_node->data;
    move->next = NULL;
    free(del_node);
    return res;
}

int change_by_loc(LList *l, Etype data, int loc)
{
    if (loc < 1)
        return -1;
    int i = 0;
    LList *move = l;
    while (i < loc)
    {
        if (move == NULL)
            return -1;
        i++;
        move = move->next;
    }
    move->data = data;
    return 1;
}

int get_index(LList *l, int loc)
{
    if (loc < 1)
        return -1;
    int i = 0;
    LList *move = l;
    while (i < loc)
    {
        if (move == NULL)
            return -1;
        i++;
        move = move->next;
    }

    return move->data;
}

int is_Empty(LList *l)
{
    return (l->next == NULL);
}

void print_list(LList *l)
{
    if (l->next == NULL)
    {
        printf("empty!");
        return;
    }
    LList *move = l->next;
    while (move != NULL)
    {
        printf("%d\t", move->data);
        move = move->next;
    }
    printf("\n");
    return;
}

int main(int argc, char const *argv[])
{
    LList *l;
    init_llist(l);
    add_back(l, 1);
    add_back(l, 2);
    add_back(l, 3);
    add_head(l, 6);
    add_head(l, 10);
    add_head(l, 9);
    add_by_loc(l, 20, 3);
    print_list(l);
    // del_back(l);
    del_head(l);
    print_list(l);
    change_by_loc(l, 50, 4);
    print_list(l);
    printf("第2个元素为:%d\t", get_index(l, 2));
    return 0;
}
