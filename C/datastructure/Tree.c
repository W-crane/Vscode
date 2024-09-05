#include <stdio.h>
#include <stdlib.h>

#define MAXNODE 100

typedef int Etype;

typedef struct Tree
{
    Etype data;
    struct Tree *lchild;
    struct Tree *rchild;
} Tree;

void init_node(Tree *t, Etype data)
{
    t->data = data;
    t->lchild = NULL;
    t->rchild = NULL;
}

void insert_bst(Tree *t, Etype data)
{
    if (data <= t->data)
    {
        if (t->lchild == NULL)
        {
            Tree *new_node = (Tree *)malloc(sizeof(Tree));
            init_node(new_node, data);
            t->lchild = new_node;
            return;
        }
        else
            insert_bst(t->lchild, data);
    }

    else
    {
        if (t->rchild == NULL)
        {
            Tree *new_node = (Tree *)malloc(sizeof(Tree));
            init_node(new_node, data);
            t->rchild = new_node;
            return;
        }
        else
            insert_bst(t->rchild, data);
    }
}

void mid_traversal(Tree *t)
{
    if (t == NULL)
        return;
    mid_traversal(t->lchild);
    printf("%d\t", t->data);
    mid_traversal(t->rchild);
}

void front_traversal(Tree *t)
{
    if (t == NULL)
        return;
    printf("%d\t", t->data);
    front_traversal(t->lchild);
    front_traversal(t->rchild);
}

void back_traversal(Tree *t)
{
    if (t == NULL)
        return;
    back_traversal(t->lchild);
    back_traversal(t->rchild);
    printf("%d\t", t->data);
}

void layer_traversal(Tree *t)
{
    Tree *queue[MAXNODE];
    int front = 0, rear = 0;

    queue[rear++] = t;
    while (front != rear)
    {
        if (queue[front]->lchild != NULL)
            queue[rear++] = queue[front]->lchild;
        if (queue[front]->rchild != NULL)
            queue[rear++] = queue[front]->rchild;
        printf("%d\t", queue[front++]->data);
    }
}

void mid_traversal_nonrecersive(Tree *t)
{
    if (t == NULL)
        return;
    Tree *move = t;
    Tree *stack[MAXNODE];
    int top = -1;
    while (top != -1 || move != NULL)
    {
        while (move != NULL)
        {
            stack[++top] = move;
            move = move->lchild;
        }
        if (top != -1)
        {
            printf("%d\t", stack[top]->data);
            move = stack[top--]->rchild;
        }
    }
}

void front_traversal_nonrecersive(Tree *t)
{
    if (t == NULL)
        return;
    Tree *move = t;
    Tree *stack[MAXNODE];
    int top = -1;
    while (top != -1 || move != NULL)
    {
        while (move != NULL)
        {
            stack[++top] = move;
            printf("%d\t", stack[top]->data);
            move = move->lchild;
        }
        if (top != -1)
        {
            move = stack[top--]->rchild;
        }
    }
}

int main(int argc, char const *argv[])
{
    Tree t;
    init_node(&t, 5);
    insert_bst(&t, 1);
    insert_bst(&t, 2);
    insert_bst(&t, 4);
    insert_bst(&t, 3);
    insert_bst(&t, 3);
    insert_bst(&t, 8);
    insert_bst(&t, 6);
    insert_bst(&t, 9);
    insert_bst(&t, 7);
    mid_traversal(&t);
    printf("\n");
    mid_traversal_nonrecersive(&t);
    printf("\n");
    front_traversal(&t);
    printf("\n");
    front_traversal_nonrecersive(&t);
    printf("\n");
    layer_traversal(&t);
    return 0;
}
