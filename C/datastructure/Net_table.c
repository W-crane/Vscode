#include <stdio.h>
#include <stdlib.h>

#define MAXVERTEX 100
#define INF 10000

typedef struct Edge
{
    int distination;
    int weight;
    struct Edge *next;
} Edge;

typedef struct Vertex
{
    int id;
    struct Edge *edge;
} Vertex;

typedef struct Net_table
{
    struct Vertex *vertexs;
    int numVertex;
} TNet;

TNet *create_tnet(int numVertex)
{
    TNet *n = (TNet *)malloc(sizeof(TNet));
    n->numVertex = numVertex;
    n->vertexs = (Vertex *)malloc(sizeof(Vertex) * numVertex);
    for (int i = 0; i < numVertex; i++)
    {
        n->vertexs[i].id = i + 1;
        n->vertexs[i].edge = NULL;
    }
    return n;
}

int insert_edge(TNet *n, int from, int to, int weight, int mode)
{
    // mode 代表是否为有向图
    if (from > n->numVertex || to > n->numVertex)
        return -1;
    Edge *move = n->vertexs[from - 1].edge;
    Edge *new_edge = (Edge *)malloc(sizeof(Edge));
    new_edge->distination = to;
    new_edge->weight = weight;
    new_edge->next = NULL;
    if (move == NULL)
        n->vertexs[from - 1].edge = new_edge;
    else
    {
        while (move->next != NULL)
        {
            if (move->distination == to)
            {
                free(new_edge);
                return -1;
            }
            move = move->next;
        }
        move->next = new_edge;
    }
    if (mode != 1)
        insert_edge(n, to, from, weight, 1);
    return 1;
}

void dfs_util(TNet *n, Vertex v, int visited[])
{
    visited[v.id - 1] = 1;
    printf("%d\t", v.id);

    Edge *edge = v.edge;
    while (edge != NULL)
    {
        if (!visited[edge->distination - 1])
            dfs_util(n, n->vertexs[edge->distination - 1], visited);
        edge = edge->next;
    }
}

void DFS(TNet *n, int id)
{
    int *visited = (int *)calloc(n->numVertex, sizeof(int));
    dfs_util(n, n->vertexs[id - 1], visited);

    for (int i = 0; i < n->numVertex; i++)
    {
        if (!visited[i])
            dfs_util(n, n->vertexs[i], visited);
    }
}

void DFS_nonrecersive(TNet *n, int id)
{
    int *stack = (int *)calloc(n->numVertex, sizeof(int));
    int *visited = (int *)calloc(n->numVertex, sizeof(int));
    int top = -1, curId;
    stack[++top] = id;
    visited[id - 1] = 1;

    while (top >= 0)
    {
        curId = stack[top--];
        printf("%d\t", curId);

        Edge *edge = n->vertexs[curId - 1].edge;
        while (edge != NULL)
        {
            if (!visited[edge->distination - 1])
            {
                stack[++top] = edge->distination;
                visited[edge->distination - 1] = 1;
            }
            edge = edge->next;
        }
    }
}

void BFS(TNet *n, int id)
{
    int *visited = (int *)calloc(n->numVertex, sizeof(int));
    int *queue = (int *)calloc(n->numVertex, sizeof(int));
    int front = 0, rear = 0, curId;

    queue[rear++] = id;
    visited[id - 1] = 1;

    while (front != rear)
    {
        curId = queue[front++];
        printf("%d\t", curId);
        Edge *edge = n->vertexs[curId - 1].edge;
        while (edge != NULL)
        {
            if (!visited[edge->distination - 1])
            {
                queue[rear++] = edge->distination;
                visited[edge->distination - 1] = 1;
            }
            edge = edge->next;
        }
    }
}

int *dijstra(TNet *n, int startId)
{
    int *visited = (int *)calloc(n->numVertex, sizeof(int));
    int *dis = (int *)malloc(n->numVertex * sizeof(int));
    for (int i = 0; i < n->numVertex; i++)
    {
        dis[i] = INF;
    }
    dis[startId - 1] = 0;
    for (int i = 0; i < n->numVertex; i++)
    {
        int min = INF, minid;
        for (int j = 0; j < n->numVertex; j++)
        {
            if (dis[j] < min && !visited[j])
            {
                min = dis[j];
                minid = j + 1;
            }
        }
        visited[minid - 1] = 1;
        Edge *edge = n->vertexs[minid - 1].edge;
        while (edge != NULL)
        {
            if (min + edge->weight < dis[edge->distination - 1])
                dis[edge->distination - 1] = min + edge->weight;
            edge = edge->next;
        }
    }

    for (int i = 0; i < n->numVertex; i++)
    {
        printf("%d\t", dis[i]);
    }

    return dis;
}

int main(int argc, char const *argv[])
{
    TNet *n = create_tnet(8);

    insert_edge(n, 1, 2, 2, 0);
    insert_edge(n, 1, 3, 3, 0);
    insert_edge(n, 1, 4, 4, 0);
    insert_edge(n, 2, 5, 6, 0);
    insert_edge(n, 3, 5, 3, 0);
    insert_edge(n, 4, 5, 1, 0);
    insert_edge(n, 5, 6, 1, 0);
    insert_edge(n, 5, 7, 4, 0);
    insert_edge(n, 6, 8, 2, 0);
    insert_edge(n, 7, 8, 2, 0);
    dijstra(n, 1);
    // insert_edge(n, 1, 2, 1, 0);
    // insert_edge(n, 2, 3, 1, 0);
    // insert_edge(n, 2, 4, 1, 0);
    // // insert_edge(n, 1, 4, 1, 0);
    // insert_edge(n, 1, 5, 1, 0);
    // insert_edge(n, 3, 6, 1, 0);
    // DFS(n, 2);
    // printf("\n");
    // DFS_nonrecersive(n, 2);
    // printf("\n");
    // BFS(n, 2);
    // printf("\n");
    return 0;
}
