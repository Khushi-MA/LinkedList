#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define qsize 5

struct stack
{
    int num[qsize];
    int front, rear;
};

typedef struct stack QUEUE;

void createqueue(QUEUE*);
int peek(QUEUE );
void insert(QUEUE* , int );
int removeq (QUEUE*);
int empty (QUEUE );
int full(QUEUE );
void display(QUEUE);
int countq (QUEUE);

int main()
{
    QUEUE Q;
    int choice, data;
    createqueue(&Q);

    do
    {
        printf("\n1.Insert\n2.Remove\n3.Peek\n4.Display\n5.Count data\n6.Exit\nCHOICE:  ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: if(full(Q))
                        printf("\nQueue is full\n");

                    else
                    {
                        printf("\nenter data to insert  ");
                        scanf("%d",&data);
                        insert(&Q,data);
                    }
                    break;

            case 2: if(empty(Q))
                    printf("\nQueue is empty\n");

                    else
                    {
                        data = removeq(&Q);
                        printf("\nRemoved data: %d \n",data);
                    }
                    break;

            case 3: if(empty(Q))
                    printf("\nQueue is empty\n\n");

                    else
                    printf("\Peek data: %d",peek(Q));

                    break;

            case 4: display(Q);
                    break;

            case 5: printf("\nNo. of data in the queue is %d\n",1+Q.rear);
                    break;

            case 6: break;
        }
    }while(choice!=6);
    return 0;
}

void createqueue(QUEUE *A)
{
    A->front=0;
    A->rear=-1;
    return;
}

int peek(QUEUE A)
{
    return (A.num[A.front]);
}

int full(QUEUE A)
{
    if(A.rear==(qsize-1))
    return 1;

    else
        return 0;
}

int empty (QUEUE A)
{
    if(A.rear==-1)
        return 1;

    else
        return 0;
}

void insert(QUEUE *A, int data)
{
    A->rear=A->rear+1;
    A->num[A->rear]=data;
    return;
}

int removeq(QUEUE *A)
{
    int data=A->num[A->front],i;
    for(i=0;i!=A->rear;i++)
    {
        A->num[i]=A->num[i+1];
    }
    free(A->num[A->rear]);
    A->rear=A->rear-1;
    return data;
}

void display(QUEUE A)
{
    for(;A.front!=A.rear+1;A.front++)
    {
        printf("\n%d",A.num[A.front]);
    }
    printf("\n");
    return;
}



