#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct Side
{
    char name;
    Side *next = NULL;
} Side;

typedef struct Node
{
    int data;
    char name;
    Side *sides = NULL;
} Node;

typedef struct Net
{
    Node *nodes = (Node *)malloc(sizeof(Node) * 10);
    int node_num = 0;
    int capcity = 10;
} Net;

typedef struct Queue
{
    char *Elements;
    int length;
    int capacity;
} queue;

Queue q;

void init_queue(queue *q)
{
    q->capacity = 10;
    q->length = 0;
    q->Elements = (char *)malloc(10 * sizeof(char));
}

int add_char(queue *q, char name)
{
    if (q->length == q->capacity)
        return -1;
    q->Elements[q->length] = name;
    q->length++;
    return q->length;
}

char pop_char(queue *q)
{
    if (q->length == 0)
        return '\0';
    char poped = q->Elements[0];
    for (int i = 1; i < q->length; i++)
    {
        q->Elements[i - 1] = q->Elements[i];
    }
    q->length--;
    return poped;
}

int extend_queue(queue *q, int expand)
{
    int *temp;
    q->Elements = (char *)realloc(q->Elements, sizeof(char) * (expand + q->capacity));
    q->capacity += expand;
    return q->capacity;
}

void print_list(queue q)
{
    printf("Length:%d\n", q.length);
    printf("Capacity:%d\n", q.capacity);
    printf("Elements:");
    for (int i = 0; i < q.length; i++)
    {
        printf("%c  ", q.Elements[i]);
    }
    printf("\n");
    printf("\n");
}

int extend_nodes(Net *net, int length)
{
    net->nodes = (Node *)realloc(net->nodes, sizeof(Node) * (net->capcity + length));
    net->capcity += length;
    return net->capcity;
}

int add_node(Net *net, char name, int data)
{
    int i = 0;
    for (i = 0; i < net->node_num; i++)
    {
        if (net->nodes[i].name == name)
            return -1;
    }
    Node new_node;
    new_node.data = data;
    new_node.name = name;
    net->nodes[i] = new_node;
    net->node_num++;
    return 1;
}

int add_side(Net *net, char name_1, char name_2)
{
    int i = 0, j = 0;
    for (i = 0; i < net->node_num; i++)
    {
        if (net->nodes[i].name == name_1)
            break;
    }
    for (j = 0; j < net->node_num; j++)
    {
        if (net->nodes[j].name == name_2)
            break;
    }
    if (i == net->node_num || j == net->node_num)
        return -1;

    Side *s1, *s2;
    s1 = (Side *)malloc(sizeof(Side));
    s2 = (Side *)malloc(sizeof(Side));
    s1->name = name_2;
    s1->next = NULL;
    s2->name = name_1;
    s2->next = NULL;

    Side *move = net->nodes[i].sides;
    if (move == NULL)
    {
        net->nodes[i].sides = s1;
    }
    else
    {
        while (move->next != NULL)
        {
            if (move->name == name_2)
                return -2;
            move = move->next;
        }
        if (move->name == name_2)
            return -2;
        move->next = s1;
    }

    move = net->nodes[j].sides;
    if (move == NULL)
    {
        net->nodes[j].sides = s2;
        return 1;
    }

    while (move->next != NULL)
    {
        move = move->next;
    }
    move->next = s2;
    return 1;
}

void print_net(Net net)
{
    int i;
    Side *move;
    for (i = 0; i < net.node_num; i++)
    {
        cout << net.nodes[i].name << "(" << net.nodes[i].data << ")";
        move = net.nodes[i].sides;
        while (move != NULL)
        {
            cout << "-->" << move->name;
            move = move->next;
        }
        cout << endl;
    }
}

int find_node(Net net, char head, int loc)
{
    int i;
    char side;
    for (i = 0; i < net.node_num; i++)
    {
        if (net.nodes[i].name == head)
            break;
    }
    if (i == net.node_num)
        return -1;
    Side *move = net.nodes[i].sides;
    for (i = 1; i < loc; i++)
    {
        if (move == NULL)
        {
            return -1;
        }
        move = move->next;
    }
    if (move == NULL)
        return -1;
    side = move->name;
    for (i = 0; i < net.node_num; i++)
    {
        if (net.nodes[i].name == side)
            return i;
    }
}

int delete_node(Net *net, char name)
{
    int i, loc;
    for (i = 0; i < net->node_num; i++)
    {
        if (net->nodes[i].name == name)
            break;
    }
    if (i == net->node_num)
        return -1;
    loc = i;
    Side *move = net->nodes[i].sides, *next;

    while (move != NULL)
    {
        next = move->next;
        free(move);
        move = next;
    }

    for (i = loc; i < net->node_num - 1; i++)
    {
        net->nodes[i] = net->nodes[i + 1];
    }
    net->node_num--;

    for (i = 0; i < net->node_num; i++)
    {
        move = net->nodes[i].sides;
        if (move->name == name)
        {
            next = move;
            (net->nodes + i)->sides = move->next;
            free(next);
            continue;
        }
        while (move->next != NULL)
        {
            // cout << i << endl;
            if (move->next->name == name)
            {
                next = move->next;
                move->next = move->next->next;
                free(next);
                break;
            }
            move = move->next;
        }
    }
}

int change_data(Net *net, char name, int data)
{
    int i, old_data;
    for (i = 0; i < net->node_num; i++)
    {
        if (net->nodes[i].name == name)
            break;
    }
    if (i == net->node_num)
        return -1;
    old_data = net->nodes[i].data;
    net->nodes[i].data = data;

    return old_data;
}

int delete_side(Net *net, char name_1, char name_2)
{
    int i, loc_1 = -1, loc_2 = -1, exist = 0;
    Side *move, *next;
    for (i = 0; i < net->node_num; i++)
    {
        if (net->nodes[i].name == name_1)
            loc_1 = i;
        else if (net->nodes[i].name == name_2)
            loc_2 = i;
        if (loc_1 != -1 && loc_2 != -1)
            break;
    }
    if (i == net->node_num)
        return -1;

    move = net->nodes[loc_1].sides;
    if (move->name == name_2)
    {
        exist = 1;
        next = move;
        (net->nodes + loc_1)->sides = move->next;
        free(next);
    }
    else
    {
        while (move->next != NULL)
        {
            if (move->next->name == name_2)
            {
                exist = 1;
                next = move->next;
                move->next = move->next->next;
                free(next);
                break;
            }
            move = move->next;
        }
    }
    if (exist == 0)
        return -2;

    move = net->nodes[loc_2].sides;
    if (move->name == name_1)
    {
        exist = 1;
        next = move;
        (net->nodes + loc_2)->sides = move->next;
        free(next);
    }
    else
    {
        while (move->next != NULL)
        {
            if (move->next->name == name_1)
            {
                exist = 1;
                next = move->next;
                move->next = move->next->next;
                free(next);
                break;
            }
            move = move->next;
        }
    }
    return 0;
}

int check_traversal(int *is_traversal, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (is_traversal[i] == 0)
            return i;
    }
    return -1;
}

void width_traversal(Net net, int *is_traversal)
{
    int i;
    char head = pop_char(&q);
    if (head == '\0')
        return;
    cout << head << '\t';
    for (i = 0; i < net.node_num; i++)
    {
        if (net.nodes[i].name == head)
            break;
    }
    is_traversal[i] = 1;
    i = 1;
    int loc = find_node(net, head, i);
    while (loc != -1)
    {
        i++;
        if (is_traversal[loc] == 1)
        {
            loc = find_node(net, head, i);
            continue;
        }
        is_traversal[loc] = 1;
        add_char(&q, net.nodes[loc].name);
        loc = find_node(net, head, i);
    }
    width_traversal(net, is_traversal);
    return;
}

void do_width_traversal(Net net)
{
    int loc;
    init_queue(&q);

    int *is_traversal = (int *)malloc(sizeof(int) * net.node_num);
    for (int i = 0; i < net.node_num; i++)
    {
        is_traversal[i] = 0;
    }
    cout << "请输入开始遍历的节点名称:";
    char name;
    cin.get(name);
    add_char(&q, name);
    width_traversal(net, is_traversal);

    while ((loc = check_traversal(is_traversal, net.node_num)) != -1)
    {
        cout << endl;
        add_char(&q, net.nodes[loc].name);
        width_traversal(net, is_traversal);
    }
}

int main(int argc, char const *argv[])
{
    Net net;
    add_node(&net, 'a', 1);
    add_node(&net, 'b', 2);
    add_node(&net, 'c', 3);
    add_node(&net, 'd', 4);
    add_node(&net, 'e', 5);
    add_node(&net, 'e', 5);
    add_node(&net, 'f', 5);
    add_node(&net, 'g', 5);
    add_side(&net, 'h', 'b');
    add_side(&net, 'a', 'c');
    add_side(&net, 'a', 'b');
    add_side(&net, 'b', 'c');
    add_side(&net, 'd', 'c');
    add_side(&net, 'd', 'e');
    add_side(&net, 'g', 'h');
    add_side(&net, 'e', 'g');
    add_side(&net, 'a', 'f');
    print_net(net);

    delete_side(&net, 'd', 'c');
    change_data(&net, 'a', 10);
    cout << endl;
    print_net(net);

    do_width_traversal(net);
    return 0;
}


