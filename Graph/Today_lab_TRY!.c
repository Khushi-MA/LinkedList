#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int q[20],top=-1,front=-1,rear=-1,a[20][20],vis[20],stack[20];
int delete();
void add(int item);
void bfs(int s,int n);
void dfs(int s,int n);
void push(int item);
int pop();
void dfs_path(int,int,int);
int directedorundirected(int[][],int);


void main()
{
int n,i,s,ch,j,status=0,d,k;
char c,dummy;
printf("ENTER THE NUMBER VERTICES ");
scanf("%d",&n);
printf("ENTER ADJACENCY MATRIX ");
for(i=1;i<=n;i++)
{
   for(j=1;j<=n;j++)
   {
       scanf("%d",&a[i][j]);
   }
}


do
{
    for(i=1;i<=n;i++)
    vis[i]=0;
printf("\nMENU");
printf("\n1.BFS traversal");
printf("\n2.DFS traversal");
printf("\n3.Directed or undirected graph");
printf("\n4.path");
printf("\nEnter your choice : ");
scanf("%d",&ch);
printf("Enter the source vertex : ");
scanf("%d",&s);

switch(ch)
{
     case 1:bfs(s,n);
     break;
     case 2:dfs(s,n);
     break;
     case 3:status=directedorundirected(a,n);
     if(status==1)
        printf("Directed graph\n");
     else
        printf("UnDirected graph\n");
     break;
     case 4:printf("Enter the Destination : ");
     scanf("%d",&d);
     dfs_path(s,n,d);
     break;
     case 5:exit(0);
     break;
}
printf("\nDo u want to continue(Y/N) ? ");
scanf("%c",&dummy);
scanf("%c",&c);
}while((c=='y')||(c=='Y'));
}

//**************BFS(breadth-first search) code**************//
void bfs(int s,int n)
{
  int p,i;
  add(s);
  vis[s]=1;
  p=delete();
  if(p!=0)
    printf("%d ",p);
  while(p!=0)
  {
    for(i=1;i<=n;i++)
       if((a[p][i]!=0)&&(vis[i]==0))
       {
          add(i);
          vis[i]=1;
       }
       p=delete();
       if(p!=0)
          printf("%d ",p);
  }
  for(i=1;i<=n;i++)
  {
     if(vis[i]==0)
        bfs(i,n);
  }
}

void add(int item)
{
if(rear==19)
  printf("QUEUE FULL");
else
{
   if(rear==-1)
   {
       q[++rear]=item;
       front++;
   }
   else
       q[++rear]=item;
}
}

int delete()
{
int k;
if((front>rear)||(front==-1))
return(0);
else
{
k=q[front++];
return(k);
}
}


//***************DFS(depth-first search) code******************//
void dfs(int s,int n)
{
    int i,k;
    push(s);
    vis[s]=1;
    k=pop();
    if(k!=0)
    printf("%d ",k);
    while(k!=0)
    {
        for(i=1;i<=n;i++)
        if((a[k][i]!=0)&&(vis[i]==0))
        {
            push(i);
            vis[i]=1;
        }
        k=pop();
        if(k!=0)
        printf("%d ",k);
    }

    for(i=1;i<=n;i++)
        if(vis[i]==0)
            dfs(i,n);
}

void push(int item)
{
    if(top==19)
        printf("Stack overflow ");
    else
        stack[++top]=item;
}

int pop()
{
        int k;
        if(top==-1)
        return(0);

    else
    {
        k=stack[top--];
        return(k);
    }
}

int directedorundirected(int a[20][20],int n)
{
    int i,j;
    int trans[20][20];
    int status=0;
    for(i=1;i<=n;i++)
    {
       for(j=1;j<=n;j++)
           trans[j][i]=a[i][j];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(trans[i][j]!=a[i][j])
               return 1;
        }
    }
    return 0;
}

void dfs_path(int s,int n,int d)
{
    int i,k;
    push(s);
    vis[s]=1;
    k=pop();
    if(k!=0)
        //printf("%d ",k);
    while(k!=0)
    {
    for(i=1;i<=n;i++)
    if((a[k][i]!=0)&&(vis[i]==0))
    {
        push(i);
        vis[i]=1;
    }
    k=pop();
    if(k==d)
    printf("\npath exists ");
    }
    for(i=1;i<=n;i++)
        if(vis[i]==0)
            dfs(i,n);
}