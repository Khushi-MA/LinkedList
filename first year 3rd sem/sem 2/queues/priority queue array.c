/*
This code is of priority queue using array
It inserts according to priority, and has normal dequeue
data required and priority number form one structure
front, end and array of above mentioned (required data) structure forms one queue structure
1 being important or front in line and 6 being least important
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define qsize 5
#define maxpriority 6

typedef struct data
{
    int num,priority;
}DATA;

struct queue
{
    DATA data[qsize];
    int front, rear;
};

typedef struct queue QUEUE;

void createqueue(QUEUE*);
DATA peek(QUEUE );
void priorityinsert(QUEUE* , DATA );
DATA removeq (QUEUE*);
int empty (QUEUE );
int full(QUEUE );
void display(QUEUE);
int countq (QUEUE);

int main()
{
    QUEUE Q;
    int choice;
    DATA value;
    createqueue(&Q);

    do
    {
        printf("\n1.Insert by priority\n2.Remove\n3.Peek\n4.Display\n5.Count data\n6.Exit\nCHOICE:  ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: if(full(Q))
                        printf("\nQueue is full\n");

                    else
                    {
                        printf("\nenter data (number) to insert  ");
                        scanf("%d",&value.num);
                        printf("enter its priority   ");
                        scanf("%d",&value.priority);
                        priorityinsert(&Q,value);
                    }
                    break;

            case 2: if(empty(Q))
                    printf("\nQueue is empty\n");

                    else
                    {
                        value = removeq(&Q);
                        printf("\nRemoved data:\nnumber: %d\npriority: %d\n",value.num,value.priority);
                    }
                    break;

            case 3: if(empty(Q))
                    printf("\nQueue is empty\n\n");

                    else{
                        value = peek(Q);
                        printf("\Peek data:\nnumber: %d\npriority: %d\n",value.num,value.priority);
                    }

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

DATA peek(QUEUE A)
{
    return (A.data[A.front]);
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

void priorityinsert(QUEUE *A, DATA value)
{
    int pos,i;
    if(value.priority>maxpriority)
        value.priority=maxpriority;

    if(value.priority<0)
        value.priority=0;

    pos=A->rear;
    A->rear=A->rear+1;
    for(i>=0;A->data[pos].priority>value.priority;)
    {
        A->data[pos+1]=A->data[pos];
        pos--;
    }
    A->data[pos+1]=value;
    return;
}

DATA removeq(QUEUE *A)
{
    int i;
    DATA data=A->data[A->front];
    for(i=0;i!=A->rear;i++)
    {
        A->data[i]=A->data[i+1];
    }
//    free(A->data[A->rear]);
    A->rear=A->rear-1;
    return data;
}

void display(QUEUE A)
{
    int i=0;
    printf("number\tpriority\n");
    for(;i!=A.rear+1;i++)
    {
        printf("%d\t%d\n",A.data[i].num,A.data[i].priority);
    }
    return;
}
