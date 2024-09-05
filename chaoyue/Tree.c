#include <stdio.h>
#include <stdlib.h>

#define MAXNODE 100

typedef struct Tree
{
    int data;
    struct Tree *lchild;
    struct Tree *rchild;
} Tree;

void init_node(Tree *t, int data)
{
    t->data = data;
    t->lchild = NULL;
    t->rchild = NULL;
}

void insert_bst(Tree *t, int data)
{
    if (t == NULL)
        return;
    if (data <= t->data)
    {
        if (t->lchild == NULL)
        {
            Tree *new_node = (Tree *)malloc(sizeof(Tree));
            init_node(new_node, data);
            t->lchild = new_node;
            return;
        }
        insert_bst(t->lchild, data);
        return;
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
        insert_bst(t->rchild, data);
        return;
    }
}

void front_traversal(Tree *t)
{
    if (t == NULL)
        return;
    printf("%d\t", t->data);
    front_traversal(t->lchild);
    front_traversal(t->rchild);
}

void mid_traversal(Tree *t)
{
    if (t == NULL)
        return;
    mid_traversal(t->lchild);
    printf("%d\t", t->data);
    mid_traversal(t->rchild);
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
    if (t == NULL)
        return;
    Tree *queue[MAXNODE];
    Tree *move;
    int front = 0, rear = 0;
    queue[rear++] = t;
    while (front != rear)
    {
        move = queue[front++];
        if (move->lchild != NULL)
            queue[rear++] = move->lchild;
        if (move->rchild != NULL)
            queue[rear++] = move->rchild;
        printf("%d\t", move->data);
    }
}

void front_traversal_nonrecersive(Tree *t)
{
    if (t == NULL)
        return;
    Tree *stack[MAXNODE];
    Tree *move = t;
    int top = -1;
    while (top != -1 || move != NULL)
    {
        while (move != NULL)
        {
            printf("%d\t", move->data);
            stack[++top] = move;
            move = move->lchild;
        }
        if (top != -1)
        {
            move = stack[top--]->rchild;
        }
    }
}

void mid_traversal_nonrecersive(Tree *t)
{
    if (t == NULL)
        return;
    Tree *stack[MAXNODE];
    Tree *move = t;
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
            move = stack[top--];
            printf("%d\t", move->data);
            move = move->rchild;
        }
    }
}

int main(int argc, char const *argv[])
{
    Tree *t = (Tree *)malloc(sizeof(Tree));
    init_node(t, 46);
    insert_bst(t, 69);
    insert_bst(t, 11);
    insert_bst(t, 48);
    insert_bst(t, 78);
    insert_bst(t, 26);
    layer_traversal(t);
    printf("\n");
    front_traversal(t);
    printf("\n");
    front_traversal_nonrecersive(t);
    printf("\n");
    mid_traversal(t);
    printf("\n");
    mid_traversal_nonrecersive(t);

    return 0;
}
