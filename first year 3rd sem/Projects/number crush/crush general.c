#include "crush header.h"

int isempty(STK S)
{
    if(S.top==-1)
        return 1;

    else
        return 0;
}

int isfull(STK S)
{
    if(S.top==(stacksize-1))
        return 1;

    else
        return 0;
}

void initstack(STK* S)
{
    S->top=-1;
    return;
}

void push(STK *S, int data)
{
    if(isfull(*S))
        printf("Stack overflow");

    else
    {
        S->top=S->top+1;
        S->num[S->top]=data;
    }
    return;
}

int pop(STK *S)
{
    int data=0;
    if(isempty(*S))
        printf("Stack underflow");

    else
    {
        data=S->num[S->top];
        S->top=S->top-1;
    }
    return data;
}

void display(STK S,int N)
{
    int i,data;

    for(i=N-1;i>-1;i--)
    {
        printf("\n%d",S.num[i]);
        pop(&S);
    }
    return;
}

int peek(STK S)
{
    return S.num[S.top];
}
