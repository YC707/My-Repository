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
    if(pos < 0 || pos > list -> Size - 1)
        return FALSE;
    *x = list -> Element[pos];
    for(int i = pos; i > list -> Size - 1; ++i)
        list -> Element[i] = list -> Element[i+1];
    list -> Size --;
    return TRUE;
}

void BubbleSort(List *list)
{
    int i, j;
    T temp;
    BOOL sorted = FALSE;
    for(i = 1; i < list -> Size && !sorted; ++i)
    {
        sorted = TRUE;
        for(j = 0; j < list -> Size - i; ++j)
            if(list -> Element[j+1] < list -> Element[j])
            {
                temp = list -> Element[j+1];
                list -> Element[j+1] = list -> Element[j];
                list -> Element[j] = temp;
                sorted = FALSE;
            }
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
    BubbleSort(&list);
    for(int i = 0; i < 10; ++i)
        printf("%d ", list.Element[i]);
}