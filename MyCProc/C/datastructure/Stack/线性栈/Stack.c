#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define MaxSize 50

typedef int T;
typedef int BOOL;

typedef struct stack
{
    int Top;
    int MaxStack;
    T Element[MaxSize];
}Stack;

void CreatStack(Stack *s, int maxsize)
{
    s -> Top = -1;
    s -> MaxStack = maxsize;
}

BOOL IsEmpty(Stack s)
{
    return s.Top < 0;
}

BOOL IsFull(Stack s)
{
    return s.Top >= s.MaxStack - 1;
}

BOOL Push(Stack *s, T x)
{
    if(IsFull(*s))
        return FALSE;
    s -> Element[++ (s -> Top)] = x;
    return TRUE;
}

BOOL Pop(Stack *s)
{
    if(IsEmpty(*s))
        return FALSE;
    s -> Top --;
    return TRUE;
}

BOOL StackTop(Stack s, T *x)
{
    if(IsEmpty(s))
        return FALSE;
    *x = s.Element[s.Top];
    return TRUE;
}

void main()
{
    Stack s;
    CreatStack(&s, 10);

    Push(&s, 2);
    Push(&s, 8);

    T x;
    StackTop(s, &x);
    Pop(&s);
    printf("%d ",x);
}