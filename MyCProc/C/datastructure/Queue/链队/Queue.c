#include<stdio.h>
#include<malloc.h>
#define TRUE 1
#define FALSE 0

typedef int T;
typedef int BOOL;

typedef struct qnode
{
    T Element;
    struct qnode *Next;
}QNode;

typedef struct queue
{
    QNode *Rear;
    QNode *Front;
}Queue;

void CreatQueue(Queue *q)
{
    q -> Rear = q -> Front = NULL;
}

BOOL IsEmpty(Queue q)
{
    if(!q.Rear || !q.Front)
        return TRUE;
    return FALSE;
}

BOOL Append(Queue *q, T x)
{
    QNode *p = (QNode*)malloc(sizeof(QNode));
    p -> Element = x;
    p -> Next = NULL;
    if(!q -> Rear)
    {
        q -> Front = q -> Rear = p;
        return TRUE;
    }
    else
    {
        q -> Rear -> Next = p;
        q -> Rear = p;
        return TRUE;
    }
}

BOOL Serve(Queue *q)
{
    if(IsEmpty(*q))
        return FALSE;
    QNode *p;
    p = q -> Front;
    if(q -> Front == q -> Rear)
        q -> Front = q -> Rear = NULL;
    else
        q -> Front = q -> Front -> Next;
    free(p);
    return TRUE;
}

BOOL QueueFront(Queue q, T *x)
{
    if(IsEmpty(q))
        return FALSE;
    *x = q.Front -> Element;
    return TRUE;
}
void main()
{
    Queue q;
    CreatQueue(&q);

    Append(&q, 3);
    Append(&q, 5);

    T x;

    QueueFront(q, &x);
    Serve(&q);
    printf("%d ", x);
}
