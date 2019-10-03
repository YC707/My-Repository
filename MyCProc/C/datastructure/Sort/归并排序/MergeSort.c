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
    int i;
    for(i = list -> Size - 1; i >= pos; --i)
        list -> Element[i+1] = list -> Element[i];
    list -> Element[i+1] = x;
    list -> Size ++;
    return TRUE;
}

BOOL Remove(List *list, int pos, T *x)
{
    if(IsEmpty(*list))
        return FALSE;
    if(pos < 0 || pos > list -> Size - 1)
        return FALSE;
    *x = list -> Element[pos];
    int i;
    for(i = pos; i < list -> Size - 1; ++i)
        list -> Element[i] = list -> Element[i+1];
    list -> Size --;
    return TRUE;
}
