#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct Tree
{
    int data;
    Tree *LChild, *RChild, *Parent;
} Tree;

typedef struct Queue
{
    Tree *t;
    Queue *next;
} Queue;

Queue q;

void init_queue(Queue *q)
{
    q->next = NULL;
}

int max(int a, int b)
{
    return a >= b ? a : b;
}

int abs(int a)
{
    return a >= 0 ? a : -a;
}

int add_back(Queue *q, Tree *t)
{
    // 初始化链栈节点
    Queue *node = (Queue *)malloc(sizeof(Queue));
    node->t = t;

    // 定义移动指针，找到栈尾以加入元素
    Queue *move = q;
    int i = 1;
    while (move->next != NULL)
    {
        i++;
        move = move->next;
    }

    move->next = node;
    node->next = NULL;

    return i;
}

int pop_front(Queue *q)
{
    if (q->next == NULL)
        return 0;

    Queue *first = q->next;
    q->next = first->next;
    free(first);
    return 1;
}

void print_queue(Queue *q)
{
    Queue *move = q;
    while (q->next != NULL)
    {
        cout << move->t << "\t";
        move = move->next;
    }
}

void init_tree(Tree *t, int data = 0)
{
    t->data = data;
    init_queue(&q);
    t->Parent = NULL;
    t->LChild = NULL;
    t->RChild = NULL;
    add_back(&q, t);
}

void mid_traversal(Tree t)
{
    if (t.LChild != NULL)
        mid_traversal(*t.LChild);
    cout << t.data << "\t";
    if (t.RChild != NULL)
        mid_traversal(*t.RChild);
}

void wide_traversal(Tree t)
{
    Queue q;
    init_queue(&q);
    add_back(&q, &t);
    Queue *move = &q;
    move = move->next;
    while (move != NULL)
    {
        if (move->t->LChild != NULL)
            add_back(&q, move->t->LChild);
        if (move->t->RChild != NULL)
            add_back(&q, move->t->RChild);
        cout << move->t->data << "\t";
        pop_front(&q);
        move = q.next;
    }
}

int *get_layers(Tree t)
{
    int *layers = (int *)malloc(sizeof(int) * 3);
    layers[0] = 0;
    layers[1] = 0;
    layers[2] = 0;
    if (t.LChild == NULL && t.RChild == NULL)
    {
        layers[0] = 1;
        layers[1] = 1;
        layers[2] = 1;
        return layers;
    }
    if (t.LChild != NULL)
        layers[1] = *get_layers(*t.LChild) + 1;
    if (t.RChild != NULL)
        layers[2] = *get_layers(*t.RChild) + 1;
    if (t.LChild == NULL)
        layers[1] = 1;
    if (t.RChild == NULL)
        layers[2] = 1;
    layers[0] = max(layers[1], layers[2]);
    return layers;
}

bool is_in_left(Tree *t, Tree *node)
{
    Queue q;
    init_queue(&q);
    if (t->LChild != NULL)
    {
        add_back(&q, t->LChild);
        Queue *move = q.next;
        while (move != NULL)
        {
            if (node == move->t)
                return true;
            if (move->t->LChild != NULL)
                add_back(&q, move->t->LChild);
            if (move->t->RChild != NULL)
                add_back(&q, move->t->RChild);

            pop_front(&q);
            move = q.next;
        }
    }

    return false;
}

Tree *find_root(Tree *t)
{
    while (t->Parent != NULL)
    {
        t = t->Parent;
    }
    return t;
}

Tree *turn_right(Tree *t)
{
    t->Parent->LChild = t->RChild;
    if (t->RChild != NULL)
        t->RChild->Parent = t->Parent;
    t->RChild = t->Parent;
    t->Parent = t->Parent->Parent;
    t->RChild->Parent = t;
    if (t->Parent != NULL)
    {
        if (t->Parent->LChild == t->RChild)
            t->Parent->LChild = t;
        else
            t->Parent->RChild = t;
    }
    return find_root(t);
}

Tree *turn_left(Tree *t)
{
    t->Parent->RChild = t->LChild;
    if (t->LChild != NULL)
        t->LChild->Parent = t->Parent;
    t->LChild = t->Parent;
    t->Parent = t->Parent->Parent;
    t->LChild->Parent = t;
    if (t->Parent != NULL)
    {
        if (t->Parent->RChild == t->LChild)
            t->Parent->RChild = t;
        else
            t->Parent->LChild = t;
    }
    return find_root(t);
}

void add_node_full(Tree *t, int data)
{
    Tree *node = (Tree *)malloc(sizeof(Tree));
    node->data = data;
    node->Parent = NULL;
    node->LChild = NULL;
    node->RChild = NULL;

    add_back(&q, node);

    if (q.next->t->LChild == NULL)
    {
        q.next->t->LChild = node;
        node->Parent = q.next->t;
        return;
    }
    if (q.next->t->RChild == NULL)
    {
        q.next->t->RChild = node;
        node->Parent = q.next->t;
        pop_front(&q);
    }
}

Tree *add_node_sort(Tree *t, int data)
{
    Tree *node = (Tree *)malloc(sizeof(Tree));
    node->data = data;
    node->Parent = NULL;
    node->LChild = NULL;
    node->RChild = NULL;

    if (data <= t->data)
    {
        if (t->LChild == NULL)
        {
            t->LChild = node;
            node->Parent = t;
            return node;
        }
        add_node_sort(t->LChild, data);
        // return node;
    }
    else
    {
        if (t->RChild == NULL)
        {
            t->RChild = node;
            node->Parent = t;
            return node;
        }
        add_node_sort(t->RChild, data);
    }

    // return node;
}

int add_balance_node(Tree *(&t), int data)
{
    Tree *node = add_node_sort(t, data);
    Tree *move = node;
    while (move != NULL)
    {
        if (abs(get_layers(*move)[1] - get_layers(*move)[2]) == 2)
            break;
        move = move->Parent;
    }
    if (move == NULL)
        return 0;
    if (get_layers(*move)[1] > get_layers(*move)[2])
    {
        if (is_in_left(move->LChild, node))
        {
            turn_right(move->LChild);
        }
        else
        {
            turn_left(move->LChild->RChild);
            turn_right(move->LChild);
        }
    }
    else
    {
        // 检查是否找到最小平衡树
        // cout << get_layers(*move)[1] << "\t" << get_layers(*move)[2] << "\t" << move->data;
        if (is_in_left(move->RChild, node))
        {
            turn_right(move->RChild->LChild);
            turn_left(move->RChild);
        }
        else
        {
            turn_left(move->RChild);
        }
    }
    t = find_root(move);
    return 1;
}

Tree *find_node(Tree *t, int data)
{
    while (t != NULL)
    {
        if (data == t->data)
            return t;
        if (data <= t->data)
            t = t->LChild;
        else
            t = t->RChild;
    }
    return NULL;
}

void print_track(Tree *t)
{

    if (t->Parent != NULL)
    {
        print_track(t->Parent);
        cout << " --> " << t->data;
    }
    else
        cout << t->data;
}

int str_to_int(char *str)
{
    int num = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        num = (str[i] - '0') + num * 10;
    }

    return num;
}

int main(int argc, char const *argv[])
{
    Tree *t = (Tree *)malloc(sizeof(Tree));
    Tree *move = t;
    init_tree(t, 1);
    add_balance_node(t, 2);
    add_balance_node(t, 3);
    add_balance_node(t, 4);
    add_balance_node(t, 5);
    add_balance_node(t, 6);
    add_balance_node(t, 7);
    add_balance_node(t, 8);
    add_balance_node(t, 9);
    add_balance_node(t, 10);
    add_balance_node(t, 11);
    add_balance_node(t, 12);
    add_balance_node(t, 13);
    add_balance_node(t, 13);
    add_balance_node(t, 15);

    mid_traversal(*t);
    cout << endl;
    wide_traversal(*t);

    cout << endl
         << "请输入要查找的节点所存储的数据:";

    char str[10];
    scanf("%s", str);

    int data = str_to_int(str);

    Tree *node = find_node(t, data);

    if (node != NULL)
    {
        cout << "所查节点存在,路径为:";
        print_track(node);
    }
    else
        cout << "所查节点不存在!" << endl;

    return 0;
}
