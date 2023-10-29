#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define stacksize 5

struct stack
{
    int S[stacksize];
    int top;
};

int stacktop(struct stack );
void push(struct stack* , int );
int empty (struct stack );
int full(struct stack );
void display(struct stack);


int main()
{
    struct stack stk;
    int choice, data;
    stk.top= -1;

    do
    {
        printf("\n1.Push\n2.Pop\n3.Stacktop\n4.DIsplay\n5.Exit");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: if(full(stk))
                        printf("\nStack overflow");

                    else
                    {
                        printf("\nenter data to push  ");
                        scanf("%d",&data);
                        push(&stk,data);
                    }break;

            case 2: if(empty(stk))
                    printf("\nStack underflow");

                    else
                    {
                        data = pop(&stk);
                        printf("\nPopped data: %d ",data);
                    }
                    break;

            case 3: if(empty(stk))
                    printf("\nstack empty");

                    else
                    printf("\nStack top: %d",stacktop(stk));

                    break;

            case 4: display(stk);
                    break;

            case 5: break;
        }
    }while(choice!=6);
}

int stacktop(struct stack stk)
{
    return (stk.S[stk.top]);
}

int full(struct stack stk)
{
    if(stk.top==(stacksize-1))
    return 1;

    else
        return 0;
}

int empty (struct stack stk)
{
    if(stk.top==-1)
        return 1;

    else
        return 0;
}

void push(struct stack *ps, int data)
{
    ps->top=ps->top+1;
    ps->S[ps->top]=data;
    return;
}

int pop (struct stack *ps)
{
    int data=ps->S[ps->top];
    ps->top=ps->top-1;
    return(data);
}


void display(struct stack stk)
{
    int i;
    for(i=0;i<stacksize;i=i+1)
    {
        printf("\n%d    %d",stk.S[i],stk.top);
    }
    return;
}
