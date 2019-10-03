#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define MaxSize 50

typedef int T;
typedef int BOOL;

typedef struct btnode
{
    T Element;
    struct btnode *Rchild;
    struct btnode *Lchild;
}BTNode;

typedef struct btree
{
    BTNode *Root;
}BTree;
typedef BTNode* K;
typedef struct queue
{
    int Rear;
    int Front;
    int MaxQueue;
    K Element[MaxSize];
}Queue;

void CreatBT(BTree *Bt)
{
    Bt -> Root = NULL;
}

void CreatQueue(Queue *q, int maxsize)
{
    q -> Rear = q -> Front = 0;
    q -> MaxQueue = maxsize;
}

BOOL IsEmpty(Queue q)
{
    return q.Front == q.Rear;
}

BOOL IsFull(Queue q)
{
    return (q.Rear + 1) % q.MaxQueue == q.Front;
}


void MakeBT(BTree *Bt, T x, BTree *Lt, BTree *Rt)
{
    BTNode *p = (BTNode*)malloc(sizeof(BTNode));
    p -> Element = x;
    p -> Lchild = Lt -> Root;
    p -> Rchild = Rt -> Root;
    Rt -> Root = Lt -> Root = NULL;
    Bt -> Root = p;
}

void Append(Queue *q, K x)
{
    if(IsFull(*q))
        return;
    q -> Element[q -> Rear = (q -> Rear + 1) % q -> MaxQueue] = x;
}

void Serve(Queue *q)
{
    if(IsEmpty(*q))
        return;
    q -> Front = (q -> Front + 1) % q -> MaxQueue;
}

void QueueFront(Queue q, K *x)
{
    if(IsFull(q))
        return;
    *x = q.Element[(q.Front + 1) % q.MaxQueue];
}
void Visit(BTNode *p)
{
    printf("%d ", p -> Element);
}

void PreOrder(BTNode *t)
{
    if(t)
    {
        Visit(t);
        PreOrder(t -> Lchild);
        PreOrder(t -> Rchild);
    }
}

void PostOrder(BTNode *t)
{
    if(t)
    {
        PostOrder(t -> Lchild);
        PostOrder(t -> Rchild);
        Visit(t);
    }
}

void InOrder(BTNode *t)
{
    if(t)
    {
        InOrder(t -> Lchild);
        Visit(t);
        InOrder(t -> Rchild);
    }
}

void LevelOrder(BTNode *t)
{
    Queue q;
    CreatQueue(&q, 10);
    BTNode *p;
    if(t)
    {
        Append(&q, t);
        while(!IsEmpty(q))
        {
            QueueFront(q, &p);
            Visit(p);
            Serve(&q);
            if(p -> Lchild)
                Append(&q, p -> Lchild);
            if(p -> Rchild)
                Append(&q, p -> Rchild);
        }
    }
}
void main()
{
    BTree a, l, r, t;
    CreatBT(&a);
    CreatBT(&l);
    CreatBT(&r);
    CreatBT(&t);

    MakeBT(&l, 8, &a, &a);
    MakeBT(&r, 9, &a, &a);
    MakeBT(&l, 4, &l, &r);
    MakeBT(&t, 10, &a, &a);
    MakeBT(&r, 5, &t, &a);
    MakeBT(&t, 2, &l, &r);
    MakeBT(&l, 6, &a, &a);
    MakeBT(&r, 7, &a, &a);
    MakeBT(&r, 3, &l, &r);
    MakeBT(&t, 1, &t, &r);

    PreOrder(t.Root);
    printf("\n");
    InOrder(t.Root);
    printf("\n");
    PostOrder(t.Root);
    printf("\n");
    LevelOrder(t.Root);

}