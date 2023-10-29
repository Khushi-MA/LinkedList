#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 1000

struct processinfo
{
    int pro,time;
};

typedef struct processinfo DATA;

struct queue
{
    DATA data[SIZE];
    int front,rear;
};

typedef struct queue QUEUE;

void createq(QUEUE*);
void enqueue(QUEUE*, DATA );
DATA dequeue(QUEUE*);
int isempty(QUEUE);
void readycheck(QUEUE*, QUEUE*);
void displayq(QUEUE);

int main()
{
    int N;
    printf("\nenter the number of processes   ");
    scanf("%d",&N);
    int i,T,M;
    DATA D;
    QUEUE Q,ready;
    createq(&Q);
    createq(&ready);
    for(i=0;i<N;i++)
    {
        scanf("%d %d",&D.pro,&D.time);
        enqueue(&Q,D);
    }

    printf("\nenter quantum number  ");
    scanf("%d",&T);
    printf("enter number of cycles  ");
    scanf("%d",&M);
    condition(&Q,T,M);
    readycheck(&Q,&ready);
    printf("\nReady Queue\n");
    displayq(ready);
    return;
}

void createq(QUEUE *A)
{
    A->front=A->rear=-1;
    return;
}

void enqueue(QUEUE *A, DATA D)
{
        if(A->front==-1 && A->rear==-1)
        A->front=A->rear=0;

        else
         A->rear=(A->rear+1)%(SIZE);

        A->data[A->rear]=D;

    return;
}

void condition(QUEUE *A, int T, int M)
{
    int i,j;
    for(j=0;j<M;j++)
    {
        for(i=0;i<=A->rear;i++)
        {
            A->data[i].time=A->data[i].time-T;
        }
    }
    return;
}

void readycheck(QUEUE *A, QUEUE *R)
{
    int i;
    DATA D;
    while(A->rear!=-1)
    {
        D=dequeue(A);
        if(D.time<=0)
            enqueue(R,D);
            //printf("%d %d\n",D.pro,D.time);
    }
    return;
}

DATA dequeue(QUEUE *A)
{
    DATA value;
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
    }
    return value;
}

int isempty(QUEUE A)
{
    if(A.rear==-1 && A.front==-1)
        return 1;

    else
        return 0;
}

void displayq(QUEUE A)
{
    int i;
    if(isempty(A))
        printf("Queue is empty\n");
    for(i=0;i<=A.rear;i++)
    {
        printf("%d  0\n",A.data[i].pro);

    }
    return;
}
