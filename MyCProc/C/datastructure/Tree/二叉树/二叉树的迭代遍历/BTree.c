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
    struct btnode *Lchild;
    struct btnode *Rchild;
}BTNode;

typedef struct btree
{
    BTNode *Root;
}BTree;

typedef BTNode* K;

typedef struct stack
{
    int Top;
    int MaxStack;
    K Element[MaxSize];
}Stack;

void CreatBT(BTree *Bt)
{
    Bt -> Root = NULL;
}

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

void MakeBT(BTree *Bt, T x, BTree *Lt, BTree *Rt)
{
    BTNode *p = (BTNode*)malloc(sizeof(BTNode));
    p -> Element = x;
    p -> Lchild = Lt -> Root;
    p -> Rchild = Rt -> Root;
    Lt -> Root = Rt -> Root = NULL;
    Bt -> Root = p;
}

void Push(Stack *s, K x)
{
    if(IsFull(*s))
        return;
    s -> Element[++ (s -> Top)] = x;
}

void Pop(Stack *s)
{
    if(IsEmpty(*s))
        return;
    s -> Top --;
}

void StackTop(Stack s, K *x)
{
    if(IsEmpty(s))
        return;
    *x = s.Element[s.Top];
}

void Visit(K k)
{
    printf("%d ", k -> Element);
}

void PreOrder(BTNode *t)
{
    Stack s;
    CreatStack(&s, 10);
    BTNode *p;
    if(t)
    {
        Push(&s, t);
        while(!IsEmpty(s))
        {
            StackTop(s, &p);
            Pop(&s);
            Visit(p);
            if(p -> Rchild)
                Push(&s, p -> Rchild);
            if(p -> Lchild)
                Push(&s, p -> Lchild);
        }
    }
}

void InOrder(BTNode *t)
{
    Stack s;
    CreatStack(&s, 10);
    BTNode *p;
    if(t)
    {
        p = t;
        while(!IsEmpty(s) || p)
        {
            while(p)
            {
                Push(&s, p);
                p = p -> Lchild;
            }
            if(!IsEmpty(s))
            {
                StackTop(s, &p);
                Visit(p);
                Pop(&s);
                p = p -> Rchild;
            }
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

}