#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 5

struct queue
{
    int data[SIZE], front, rear;
};

typedef struct queue QQ;

void deleteq(QQ*);
void insertq(QQ*, int);
int isfull(QQ);
int isempty(QQ);
void createq(QQ*);

int isfull(QQ A)
{
    if((A.rear+1)%SIZE==A.front)
        return 1;

    else
        return 0;
}

int isempty(QQ A)
{
    if((A.rear)==-1)
        return 1;

    else
        return 0;
}

void insertq(QQ *A, int value)
{
    if(isfull(*A))
    {
        printf("\nQueue is full");
    }

    else
    {
        if(A->front==-1 && A->rear==-1)
        A->front=A->rear=0;

        else
         A->rear=(A->rear+1)%(SIZE);

        A->data[A->rear]=value;
    }
    return;
}

void deleteq(QQ *A)
{
    int value;
    if(isempty(*A))
    {
        printf("\nQueue is empty");
    }
    else
    {
        value=A->data[A->front];

        if(A->front==A->rear)
        {
            A->front=-1;
            A->rear=-1;
        }

        else
            A->front=(A->front+1)%SIZE;

        printf("\ndeleted element is %d",value);
    }
    return;
}

void createq(QQ *A)
{
    A->front=A->rear=-1;
    return;
}

int peek(QQ A)
{
    return (A.data[A.front]);
}

void display(QQ A)
{
    int i;
    for(i=0;i<=A.rear;i++)
        printf("\n%d",A.data[i]);

    return ;
}

int main()
{
    QQ q;
    createq(&q);
    int ch,value;
    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Peek\n4.Display\n5.Exit\nenter choice:  ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nenter data:  ");
                    scanf("%d",&value);
                    insertq(&q,value);
                    break;

            case 2: deleteq(&q);
                    break;

            case 3:
                    value=peek(q);
                    printf("\nfront value is %d",value);
                    break;

            case 4: display(q);
                    break;

            case 5: exit(0);
        }
    }
}

