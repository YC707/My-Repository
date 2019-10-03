#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define MaxSize 50

typedef int T;
typedef int BOOL;

typedef struct queue
{
    int Rear;
    int Front;
    int MaxQueue;
    T Element[MaxSize];
}Queue;

void CreatQueue(Queue *q, int maxsize)
{
    q -> Rear = q -> Front = 0;
    q -> MaxQueue = maxsize;
}

BOOL IsEmpty(Queue q)
{
    return q.Rear == q.Front;
}

BOOL IsFull(Queue q)
{
    return (q.Rear + 1) % q.MaxQueue == q.Front;
}

BOOL Append(Queue *q, T x) 
{
    if(IsFull(*q))
        return FALSE;
    q -> Element[q -> Rear = (q -> Rear + 1) % q -> MaxQueue] = x;
    return TRUE;
}

BOOL Serve(Queue *q)
{
    if(IsEmpty(*q))
        return FALSE;
    q -> Front = (q -> Front + 1) % q -> MaxQueue;
    return TRUE;
}

BOOL QueueFront(Queue q, T *x)
{
    if(IsEmpty(q))
        return FALSE;
    *x = q.Element[(q.Front + 1) % q.MaxQueue];
    return TRUE;
}

void main()
{
    Queue q;
    CreatQueue(&q, 10);

    Append(&q, 1);
    Append(&q, 3);

    T x;


    QueueFront(q, &x);
    Serve(&q);
    printf("%d ", x);
}