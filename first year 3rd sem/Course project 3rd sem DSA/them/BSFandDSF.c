#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int queue[30], stack[30], visited[30]=0, arr[20][20], top=-1, rear=-1;

int main()
{
    int i, j, n, choice, source;
    printf("\nenter the number of nodes:  ");
    scanf("%d",&n);
    printf("\nEnter adjacency matrix\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&arr[i][j]);
    
    printf("1. BFS\n2. DFS\n");
    printf("\nenter function:  ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1: printf("\nEnter source:  ");
                scanf("%d", &source);
                BFS(s,n);
                break;

        case 2: printf("\nEnter source:  ");
                scanf("%d", &source);
                DFS(s,n);
                break;
        
        default: printf("choice doesn't exist!!!");
                break;
    }
    return 0;
}

void BFS(int s, int n)
{
    int i;
    enqueue(s);
    visited[s]=1;
    p=dequeue();
    if(p!=0)
    printf("%d  ",p);
    while(p!=0)
    {
        for(i=1;i<=n;i++)
        {
            if(visites[i]==0 && arr[p][i]!=0)
            {
                visited[i]=1;
                enqueue[i];
            }
            p=dequeue[i];
            if(p!=0)
            printf("%d  ",p);
        }
        
    }
}

void enqueue(int s)
{
    if(top==-1)
        top++;
    
    rear++;
    queue[rear]=s;
}

int dequeue()
{
    int i=queue[front];
    if(rear==0)


}