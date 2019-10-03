#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int T;
typedef int BOOL;

typedef struct enode
{
    int AdjVex;
    T W;
    struct enode* NextArc;
}ENode;

typedef struct graph
{
    int Vertices;
    ENode **A;
}Graph;

void CreatGraph(Graph *g, int n)
{
    int i;
    g -> Vertices = n;
    g -> A = (ENode**)malloc(n*sizeof(ENode*));
    for(i = 0; i < n; ++i)
        g -> A[i] = NULL;
}

ENode* NewENode(int vex, T weight, ENode *nextarc)
{
    
}

