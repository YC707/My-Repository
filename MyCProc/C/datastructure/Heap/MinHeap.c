#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define MaxSize 50

typedef int T;
typedef int BOOL;

typedef struct minheap
{
    int Size;
    int MaxHeap;
    T Element[MaxSize];
}MinHeap;

void CreatHeap(MinHeap *heap, int maxsize)
{
    heap -> Size = 0;
    heap -> MaxHeap = maxsize;
}

BOOL IsEmpty(MinHeap heap)
{
    return heap.Size == 0;
}

BOOL IsFull(MinHeap heap)
{
    return heap.Size == heap.MaxHeap;
}

void AdjustDown(T heap[], int r, int n)
{
    int child = 2 * r;
    T temp = heap[r];
    while(child <= n)
    {
        if(child < n && heap[child] > heap[child+1])
            child++;
        if(heap[child] >= temp)    //根节点小于等于孩子结点
            break;
        heap[child/2] = heap[child];
        child *= 2;
    }
    heap[child/2] = temp;
}

void AdjustUp(T heap[], int n)
{
    int i = n;
    T temp = heap[i];
    while(i != 1 && temp < heap[i/2])
    {
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = temp;
}

BOOL Append(MinHeap *hp, T x)
{
    if(IsFull(*hp))
        return FALSE;
    hp -> Element[++ hp -> Size] = x;
    AdjustUp(hp -> Element, hp -> Size);
    return TRUE;
}

BOOL Serve(MinHeap *hp, T *x)
{
    if(IsEmpty(*hp))
        return FALSE;
    *x = hp -> Element[1];
    hp -> Element[1] = hp -> Element[hp ->Size --];
    AdjustDown(hp -> Element, 1, hp -> Size);
}

void main()
{
    MinHeap heap;
    CreatHeap(&heap, 2);
    Append(&heap, 2);
    printf("%d ",IsFull(heap));
    Append(&heap, 8);
    printf("%d ",IsFull(heap));
    Append(&heap, 4);
    
    T x;
    Serve(&heap, &x);
    printf("%d ", x);
    Serve(&heap, &x);
    printf("%d ", x);
}