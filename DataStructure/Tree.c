#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
    int data;
    struct Tree *lchild, *rchild;
} Tree;

typedef struct List
{
    int data, layer;
    struct List *next;
    struct Tree *lchild, *rchild;
} List;

void init_list(List *l)
{
    l->data = -1;
    l->layer = -1;
    l->next = NULL;
}

void insert_to_list(List *l, int data, int layer, Tree *lchild, Tree *rchild)
{
    List *move = l;
    List *new_node = (List *)malloc(sizeof(List));
    new_node->next = NULL;
    new_node->data = data;
    new_node->layer = layer;
    new_node->lchild = lchild;
    new_node->rchild = rchild;
    while (move->next != NULL)
        move = move->next;
    move->next = new_node;
}

void init_tree(Tree *t, int data)
{
    t->data = data;
    t->lchild = NULL;
    t->rchild = NULL;
}

List *layer_travesel_tree(Tree *t)
{
    List *l = (List *)malloc(sizeof(List)), *move;
    init_list(l);
    insert_to_list(l, t->data, 1, t->lchild, t->rchild);
    move = l->next;
    while (move != NULL)
    {
        if (move->lchild != NULL)
            insert_to_list(l, move->lchild->data, move->layer + 1, move->lchild->lchild, move->lchild->rchild);
        if (move->rchild != NULL)
            insert_to_list(l, move->rchild->data, move->layer + 1, move->rchild->lchild, move->rchild->rchild);
        move = move->next;
    }
    return l;
}

int *find_layers_max(List *l)
{
    int layer = 1, max = l->next->data;
    List *move = l->next;
    int *max_nums;
    while (move->next != NULL)
        move = move->next;
    max_nums = (int *)malloc(sizeof(int) * (move->layer + 1));
    max_nums[0] = move->layer;
    move = l->next;
    while (move->next != NULL)
    {
        if (move->data > max)
            max = move->data;
        if (move->next->layer != move->layer)
        {
            max_nums[layer++] = max;
            max = move->next->data;
        }
        move = move->next;
    }
    if (move->data > max)
        max = move->data;
    max_nums[layer] = max;
    return max_nums;
}

Tree *del_node(Tree *t, int data)
{
}

void print_list(List *l)
{
    if (l == NULL || l->next == NULL)
    {
        printf("Error!!");
        return;
    }
    List *move = l->next;
    while (move->next != NULL)
    {
        printf("%d:%d-->", move->layer, move->data);
        move = move->next;
    }
    printf("%d:%d\n", move->layer, move->data);
}

void insert_tree(Tree *t, int data)
{
    if (data < t->data)
    {
        if (t->lchild != NULL)
            insert_tree(t->lchild, data);
        else
        {
            Tree *new_node = (Tree *)malloc(sizeof(Tree));
            new_node->data = data;
            new_node->lchild = NULL;
            new_node->rchild = NULL;
            t->lchild = new_node;
        }
    }
    else
    {
        if (t->rchild != NULL)
            insert_tree(t->rchild, data);
        else
        {
            Tree *new_node = (Tree *)malloc(sizeof(Tree));
            new_node->data = data;
            new_node->lchild = NULL;
            new_node->rchild = NULL;
            t->rchild = new_node;
        }
    }
}

void deleteFunc(Tree *t)
{
    if (t != NULL)
    {
        deleteFunc(t->lchild);
        deleteFunc(t->rchild);
        t->rchild = NULL;
        t->lchild = NULL;
        free(t);
        t = NULL;
    }
}

void preOrderTraversing(Tree *t, int x)
{
    static Tree *parent = NULL;
    if (t != NULL)
    {
        if (t->data == x)
        {
            deleteFunc(t->lchild);
            t->lchild = NULL;
        }
        else if (t->data < x)
        {
            deleteFunc(t->lchild);
            if (parent != NULL)
                parent->lchild = t->rchild;
            if (t->rchild != NULL)
            {
                *t = *(t->rchild);
                preOrderTraversing(t, x);
            }
            else
                deleteFunc(parent->lchild);
        }
        else if (t->data > x)
        {
            parent = t;
            preOrderTraversing(t->lchild, x);
        }
    }
}

void mid_travesal(Tree *t)
{
    if (t == NULL)
        return;
    mid_travesal(t->lchild);
    printf("%d\t", t->data);
    mid_travesal(t->rchild);
}



int main(int argc, char const *argv[])
{
    Tree *t = (Tree *)malloc(sizeof(Tree));
    List *l;
    int *max_nums;
    init_tree(t, 5);
    insert_tree(t, 3);
    insert_tree(t, 2);
    insert_tree(t, 1);
    insert_tree(t, 7);
    insert_tree(t, 4);
    insert_tree(t, 6);
    insert_tree(t, 8);
    insert_tree(t, 10);
    insert_tree(t, 9);
    preOrderTraversing(t, 1);
    mid_travesal(t);
    return 0;
}
