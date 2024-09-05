#include <stdio.h>
#include <stdlib.h>

#define INF 100000

typedef struct MNet
{
    int numVertex;
    int **matrix;
} MNet;

MNet *create_mnet(int numVertex)
{
    MNet *m = (MNet *)malloc(sizeof(MNet));
    m->numVertex = numVertex;

    m->matrix = (int **)malloc(sizeof(int *) * numVertex);
    for (int i = 0; i < numVertex; i++)
    {
        m->matrix[i] = (int *)malloc(sizeof(int) * numVertex);
        for (int j = 0; j < numVertex; j++)
        {
            if (i == j)
                m->matrix[i][j] = 0;
            else
                m->matrix[i][j] = INF;
        }
    }
    return m;
}

void add_edge(MNet *m, int a, int b, int c, int mode)
{
    // mode表示是否为有向图
    m->matrix[a - 1][b - 1] = c;
    if (mode != 1)
    {
        m->matrix[b - 1][a - 1] = c;
    }
}

void dijstra(MNet *m, int startid)
{
    int *visited = (int *)malloc(m->numVertex * sizeof(int));
    int *dis = (int *)malloc(m->numVertex * sizeof(int));
    for (int i = 0; i < m->numVertex; i++)
    {
        visited[i] = 0;
        dis[i] = INF;
    }

    dis[startid - 1] = 0;
    for (int i = 0; i < m->numVertex; i++)
    {
        int min = INF, minid;
        for (int j = 0; j < m->numVertex; j++)
        {
            if (dis[j] < min && !visited[j])
            {
                min = dis[j];
                minid = j + 1;
            }
        }
        visited[minid - 1] = 1;
        for (int j = 0; j < m->numVertex; j++)
        {
            if (visited[j] == 0)
            {
                if (m->matrix[minid - 1][j] + min < dis[j])
                    dis[j] = m->matrix[minid - 1][j] + min;
            }
        }
    }
    for (int i = 0; i < m->numVertex; i++)
    {
        printf("%d\t", dis[i]);
    }
}

void dfs_util(MNet *n, int id, int *visited)
{
    visited[id - 1] = 1;
    printf("%d\t", id);

    for (int i = 1; i <= n->numVertex; i++)
    {
        if (n->matrix[id - 1][i - 1] != INF && !visited[i - 1])
            dfs_util(n, i, visited);
    }
}

void DFS(MNet *n, int start_id)
{
    int *visited = (int *)calloc(n->numVertex, sizeof(int));
    dfs_util(n, start_id, visited);
    for (int i = 1; i <= n->numVertex; i++)
    {
        if (!visited[i - 1])
            dfs_util(n, i, visited);
    }
}

void DFS_nonrecersive(MNet *m, int startId)
{
    int *visited = (int *)calloc(m->numVertex, sizeof(int));
    int *stack = (int *)calloc(m->numVertex, sizeof(int));
    int top = -1, curId;

    stack[++top] = startId;
    visited[startId - 1] = 1;

    while (top != -1)
    {
        curId = stack[top--];
        printf("%d\t", curId);

        for (int i = 1; i <= m->numVertex; i++)
        {
            if (m->matrix[curId - 1][i - 1] != INF && !visited[i - 1])
            {
                stack[++top] = i;
                visited[i - 1] = 1;
            }
        }
    }
}

void BFS(MNet *m, int startId)
{
    int *visited = (int *)calloc(m->numVertex, sizeof(int));
    int *queue = (int *)calloc(m->numVertex, sizeof(int));
    int front = 0, rear = 0, curId;

    queue[rear++] = startId;
    visited[startId - 1] = 1;
    while (front != rear)
    {
        curId = queue[front++];
        printf("%d\t", curId);

        for (int i = 1; i <= m->numVertex; i++)
        {
            if (m->matrix[curId - 1][i - 1] != INF && !visited[i - 1])
            {
                queue[rear++] = i;
                visited[i - 1] = 1;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    MNet *m = create_mnet(6);

    // 测试dijstra
    // add_edge(m, 1, 2, 2, 0);
    // add_edge(m, 1, 3, 3, 0);
    // add_edge(m, 1, 4, 4, 0);
    // add_edge(m, 2, 5, 6, 0);
    // add_edge(m, 3, 5, 3, 0);
    // add_edge(m, 4, 5, 1, 0);
    // add_edge(m, 5, 6, 1, 0);
    // add_edge(m, 5, 7, 4, 0);
    // add_edge(m, 6, 8, 2, 0);
    // add_edge(m, 7, 8, 2, 0);

    add_edge(m, 1, 2, 1, 0);
    add_edge(m, 2, 3, 1, 0);
    add_edge(m, 2, 4, 1, 0);
    add_edge(m, 1, 4, 1, 0);
    add_edge(m, 1, 5, 1, 0);
    add_edge(m, 3, 6, 1, 0);
    // dijstra(m, 1);
    DFS(m, 2);
    printf("\n");
    DFS_nonrecersive(m, 2);
    printf("\n");
    BFS(m, 2);
    return 0;
}
