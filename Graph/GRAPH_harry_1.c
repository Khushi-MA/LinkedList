#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>

// circular queue

struct queue
{
    int size;
    int front;
    int rear;
    int * arr;
};

void initqueue(struct queue *);
int isfull(struct queue);
int isempty(struct queue);
void enqueue(struct queue *, int );
int dequeue(struct queue *);
void displayqueue(struct queue);

void DFS_deapthfirsttraversal(int);
void BFS_breadthfirsttraversal(int);


// Global decalration of graph so 
// it can be found in all the functions

//int visited[7];
int arr[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
int visited[7] = {0,0,0,0,0,0,0};


void DFS_deapthfirsttraversal(int i)
{
    int j;
    printf("%d  ", i);
    visited[i] = 1;
    for(j=0;j<7;j++)
    {
        if(arr[i][j] == 1 && !visited[j])
            DFS_deapthfirsttraversal(j);
    }
    return;
}

void BFS_breadthfirsttraversal(int i)
{
    int visited2[7] = {0,0,0,0,0,0,0};
    struct queue Q;
    initqueue(&Q);
    int node; 
    int j=0;       //  start of the search is i

    printf("%d  ",i);
    visited2[i]=1;
    enqueue (&Q,i);   // enqueue i for exploration
    while(!isempty(Q))
    {
        int node = dequeue(&Q); 
        for(j=0 ; j < 8 ; j++) 
        {
            if(arr[node][j] == 1 && visited2[j] == 0)
            {
                printf("%d  ",j);
                visited2[j]=1;
                enqueue(&Q,j);
            }
        }
    }
}

int main()
{
    
    // Current graph:

        //   0-----1
        //   |`\_  |
        //   |   \ |   
        //   3----`2
        //         |
        //   5-----4
        //         |
        //         6
    

    int n;
    // printf("\nEnter the source of the traversal:  ");
    // scanf("%d",&n);
    printf("\nBFS:\n");
    BFS_breadthfirsttraversal(0);
    printf("\nDFS\n");
    DFS_deapthfirsttraversal(0);

    /*

    struct queue Q;
    initqueue(&Q);
    int node; 
    int i = 0, j=0;       //  start of the search is i

    printf("%d  ",i);
    visited[i]=1;
    enqueue (&Q,i);   // enqueue i for exploration
    while(!isempty(Q))
    {
        int node = dequeue(&Q); 
        for(j=0 ; j < 8 ; j++) 
        {
            if(arr[node][j] == 1 && visited[j] == 0)
            {
                printf("%d  ",j);
                visited[j]=1;
                enqueue(&Q,j);
            }
        }
    }
    */

    return 0;
}


void initqueue(struct queue * Q)
{
    Q->size = 10;
    Q->front = Q->rear = -1;
    Q->arr = (int *) malloc (Q->size * sizeof(int));
}


int isfull(struct queue Q)
{
    if((Q.rear+1) % Q.size == Q.front)
    return 1;

    else return 0;
}

int isempty(struct queue Q)
{
    if(Q.front == Q.rear)
    return 1;

    else return 0;
}

void enqueue(struct queue * Q, int value)
{
    if(isfull(*Q))
    {
        printf("\nSTACK OVERFLOW");
        return;
    }
    else
    {
        Q->rear = (Q->rear + 1)%Q->size;  // Q->rear++;
        Q->arr[Q->rear] = value;
    }
}

int dequeue(struct queue * Q)
{
    int a=-1;  // can't dequeue
    if(isempty(*Q))
    {
        printf("\nSTACK UNDERFLOW!!!");
        return a;
    }

    else 
    {
        Q->front = (Q->front+1)%Q->size;
        a = Q->arr[Q->front];
    }
    return a;

}

void displayqueue(struct queue Q)
{
    if(isempty(Q))
    {
        printf("\nSTACK UNDERFLOW!!!");
        return;
    }

    int i;
    for(i=Q.front+1 ; i!=Q.rear+1 ; i = (i+1) % Q.size)
        printf("%d  ",Q.arr[i]);
    
    return;
}