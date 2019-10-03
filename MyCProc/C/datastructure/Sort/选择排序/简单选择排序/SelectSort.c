#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define MaxSize 50

typedef int T;
typedef int BOOL;

typedef struct list
{
    int Size;
    int MaxList;
    T Element[MaxSize];
}List;

void CreatList(List *list, int maxsize)
{
    list -> Size = 0;
    list -> MaxList = maxsize;
}

BOOL IsEmpty(List list)
{
    return list.Size == 0;
}

BOOL IsFull(List list)
{
    return list.Size == list.MaxList;
}

BOOL Insert(List *list, int pos, T x)
{
    if(IsFull(*list))
        return FALSE;
    if(pos < 0 || pos > list -> Size)
        return FALSE;
    for(int i = list -> Size - 1; i >= pos; --i)
        list -> Element[i+1] = list -> Element[i];
    list -> Element[pos] = x;
    list -> Size ++;
    return TRUE;
}

BOOL Remove(List *list, int pos, T *x)
{
    if(IsEmpty(*list))
        return FALSE;
    if(pos < 0 || pos > list -> Size -1)
        return FALSE;
    *x = list -> Element[pos];
    for(int i = pos; i < list -> Size -1; ++i)
        list -> Element[i] = list -> Element[i+1];
    list -> Size --;
    return FALSE;
}

void SelectSort(List *list)
{
    int i, j, min;
    T temp;
    for(i = 0; i< list -> Size; ++i)
    {
        min = i;
        for(j = i + 1; j < list -> Size; ++j)
            if(list -> Element[j] < list -> Element[min])
                min = j;
        temp = list -> Element[i];
        list -> Element[i] = list -> Element[min];
        list -> Element[min] = temp;
    }
}

void main()
{
    int a[] = {9, 1, 7, 2, 4, 6, 5, 8, 3, 0};
    List list;
    CreatList(&list, 10);
    for(int i = 0; i < 10; ++i)
        Insert(&list, i, a[i]);
    
    for(int i = 0; i < 10; ++i)
        printf("%d ", list.Element[i]);
    printf("\n");
    SelectSort(&list);
    for(int i = 0; i < 10; ++i)
        printf("%d ", list.Element[i]);
}