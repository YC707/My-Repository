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

void Append(MinHeap *heap, T x)
{
    heap -> Element[++ heap -> Size] = x;
}
void AdjustDown(T heap[], int r, int n)
{
    int child = 2 * r;
    T temp = heap[r];
    while(child <= n)
    {
        if(child < n && heap[child] < heap[child+1])
            child ++;
        if(temp >= heap[child])
            break;
        heap[child/2] = heap[child];
        child *= 2;
    }
    heap[child/2] = temp;
}

void HeapSort(MinHeap *hp)
{
    int i;
    T temp;
    for(i = hp -> Size / 2; i > 0; i--)
        AdjustDown(hp -> Element, i, hp -> Size);
    for(i = hp -> Size; i > 1; i--)
    {
        temp = hp -> Element[i];
        hp -> Element[i] = hp -> Element[1];
        hp -> Element[1] = temp;
        AdjustDown(hp -> Element, 1, i - 1);
    }
}

void main()
{
    int a[] = {9, 1, 7, 2, 4, 6, 5, 8, 3, 0};
    MinHeap heap;
    CreatHeap(&heap, 10);
    for(int i = 0; i < 10; ++i)
        Append(&heap, a[i]);
    for(int i = 0; i < 10; ++i)
        printf("%d ", heap.Element[i+1]);
    HeapSort(&heap);
    printf("\n");
    for(int i = 0; i < 10; ++i)
        printf("%d ", heap.Element[i+1]);
}