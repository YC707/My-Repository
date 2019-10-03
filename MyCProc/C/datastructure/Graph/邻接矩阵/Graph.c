#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int T;
typedef int BOOL;

typedef struct graph
{
    T NoEdge;
    int Vertices;
    T **A;
}Graph;

void CreatGraph(Graph *g, int n, T noedge)
{
    int i, j;
    g -> NoEdge = noedge;
    g -> Vertices = n;
    g -> A = (T**)malloc(n * sizeof(T*));
    for(i = 0; i < n; ++i)
    {
        g -> A[i] = (T*)malloc(n * sizeof(T));
        for(j = 0; j < n; ++j)
            g -> A[i][j] = noedge;
        g -> A[i][i] = 0;
    }
}

BOOL Add(Graph *g, int u, int v, T w)
{
    int n = g -> Vertices;
    if(u<0 || v<0 || u>n-1 || v > n-1 || u==v || g -> A[u][v] != g -> NoEdge)
        return FALSE;
    g -> A[u][v] = w;
    return TRUE;
}

BOOL Deletc(Graph *g, int u, int v)
{
    int n = g -> Vertices;
    if(u<0 || v<0 || u>n-1 || v>n-1 || u==v || g -> A[u][v] == g -> NoEdge)
        return FALSE;
    g -> A[u][v] = g -> NoEdge;
    return TRUE;
}

BOOL Exist(Graph g, int u, int v)
{
    int n = g.Vertices;
    if(u<0 || v<0 || u>n-1 || v>n-1 || u==v || g.A[u][v] == g.NoEdge)
        return FALSE;
    return TRUE;
}
void main()
{
    Graph g;
    CreatGraph(&g, 4, 10);
    Add(&g, 1, 0, 4);
    Add(&g, 1, 2, 5);
    Add(&g, 2, 3, 3);
    Add(&g, 3, 0, 1);
    Add(&g, 3, 1, 1);
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
            printf("%3d",g.A[i][j]);
        printf("\n");
    }
}