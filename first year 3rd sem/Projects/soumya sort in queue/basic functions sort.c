#include "sort header.h"

void enqueue(QUEUE *A, DATA data)
{
    A->rear=A->rear+1;
    A->data[A->rear]=data;
    return;
}

void createq(QUEUE *A)
{
    A->rear=-1;
    A->front=0;
    return;
}

DATA dequeue(QUEUE *A)
{
    DATA value=A->data[A->front];
    int i;
    for(i=0;i!=A->rear;i++)
    {
        A->data[i]=A->data[i+1];
    }
    // free(A->data[A->rear]);
    A->rear=A->rear-1;
    return value;
}

int emptyq (QUEUE A)
{
    if(A.rear==-1)
        return 1;

    else
        return 0;
}

void displayq(QUEUE A)
{
    if(emptyq(A))
    {
        printf("\nQueue is empty.");
        return;
    }
    int i;
    printf("\nName\tAge");
    if(A.data[A.front].age>=60)
    printf("\tGender");
    for(i=0;i<=A.rear;i++)
    {
        printf("\n%s\t%d",A.data[i].name,A.data[i].age);       // you can dequeue and display

        if(A.data[A.front].age>=60)
            printf("\t%c",toupper(A.data[i].gender));
    }
    return;
}
