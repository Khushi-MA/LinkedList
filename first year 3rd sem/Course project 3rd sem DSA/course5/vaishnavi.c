
#include<stdlib.h>
#include <stdio.h>
#include <string.h>

struct hotel
{
    char name[100];
    float rating;
    char add[100];
    int price;
};

struct node
{
    char* name;
};

struct nodee
{
    struct nodee *l;
    struct nodee *r;
    float rat;
    char name[100];
    char add[100];
    int price;
};
typedef struct nodee *nodee;

struct NODE
{
    char name[30];
    int price;
    int seats;
    char des[30];

};
typedef struct NODE *NODE;

struct hotel h[100];
struct node city[100];
struct NODE m[100];


void near_hotels(char d[],struct hotel h[]);
nodee create(char namee[],float data,char addr[],int roka);
void insert(nodee root,char name[],float data,char addr[],int roka);
void inorder(nodee root);
void airways(int p,int q);
//void des_flights(int q);


int main()
{
    nodee root=NULL;
    //int n=100;
    char s[50],d[50];
    float r[30],o[30];
    int p,q;
    city[0].name="Pune";
    city[1].name="Mumbai";
    city[2].name="Shimla";
    city[3].name="Maldives";
    city[4].name="Delhi";
    city[5].name="Dubai";
    city[6].name="Varanasi";
    city[7].name="Bengluru";
    city[8].name="Manali";
    city[9].name="Ladakh";
    printf("Enter source and destination\n");
    scanf("%s%s",s,d);
    for(int j=0;j<10;j++)
    {
        if(strcmp(s,city[j].name)==0)
             p=j;
    }
    for(int k=0;k<10;k++)
    {
        if(strcmp(d,city[k].name)==0)
             q=k;
    }
    printf("\n");
    near_hotels(d,h);          ///functional call for displaying nearby hotels
    for(int l=1;l<=30;l++)
    {
        r[l]=h[l].rating;
    }
    printf("\n");
    printf("hotel ratings\n");
    root=create(h[1].name,h[1].rating,h[1].add,h[1].price);             ///functional call for sorting rating less to max
    for(int l=2;l<=30;l++)
    {
        insert(root,h[l].name,h[l].rating,h[l].add,h[l].price);
    }
    //printf("sorting done\n");
    inorder(root);
    airways(p,q);
    //des_flights(q);
}

void near_hotels(char d[],struct hotel h[])
{
    FILE* fp1;
    fp1=fopen("hotel.txt","r");
    for(int i=1;i<=30;i++)
    {
        fscanf(fp1,"%s %f %s %d",h[i].name,&h[i].rating,h[i].add,&h[i].price);
    }
    printf("Hotels in %s\n",d);
    for(int i=1;i<=30;i++)
    {
        if(strcmp(h[i].add,d)==0)
        {
            printf("%-10s\t%-12.01f\t%8s\t%10d\n",h[i].name,h[i].rating,h[i].add,h[i].price);
        }
    }
    fclose(fp1);
}

void insert(nodee root,char name[],float data,char addr[],int roka)
{
    nodee prev=NULL;
    while(root!=NULL)
    {
        prev=root;
        if(data<root->rat)
        {
            root=root->l;
        }
        else
        {
            root=root->r;
        }
    }
    nodee newnode=create(name,data,addr,roka);
    if(data<prev->rat)
    {
        prev->l=newnode;
    }
    else
    {
        prev->r=newnode;
    }
}

void inorder(nodee root)
{
    int i=1;
    if(root!=NULL)
    {
        inorder(root->r);
        printf("%-10s\t%-12.01f\t%8s\t%10d\n",root->name,root->rat,root->add,root->price);
        inorder(root->l);
    }
}

nodee create(char namee[],float data,char addr[],int roka)
{
    nodee newnode=(nodee)malloc(sizeof(struct nodee));
    newnode->rat=data;
    newnode->price=roka;
    strcpy(newnode->name,namee);
    strcpy(newnode->add,addr);
    newnode->r=NULL;
    newnode->l=NULL;
    return newnode;
}

void selection_sort(int n,struct NODE a[])
{
    int i,j;
    struct NODE temp;
    for(i=0;i<n-1;i++)
    {
        int min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j].price<a[min].price)
                min=j;
        }
        if(min!=i)
        {
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
    printf("Flight Name        Price         Seats_Avalable\n");
    for(int i=1;i<n;i++)
    {
        printf("%-10s\t%-14d%8d\n",a[i].name,a[i].price,a[i].seats);
    }
}

void flightdijikstra(int a[10][10], int n, int s,int q)
{
	int cost[10][10], distance[10], path[10];
	int visited[10], count, min, u, i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i][j]==0)
				cost[i][j]=999;
			else
				cost[i][j]=a[i][j];

	for(i=0;i<n;i++)
	{
		distance[i]=cost[s][i];
		path[i]=s;
		visited[i]=0;
	}
	distance[s]=0;
	visited[s]=1;
	count=1;
	while(count < n-1)
    {
		min=999;
		for(i=0;i < n;i++)
		{
		    if(distance[i] < min&&!visited[i])
			{
				min=distance[i];
				u=i;
			}
		}

		visited[u]=1;
		for(i=0;i < n;i++)
        {
            if(!visited[i])
            {
                if(min+cost[u][i] < distance[i])
				{
					distance[i]=min+cost[u][i];
					path[i]=u;
				}
            }
        }
        count++;
	}

	for(i=0;i<n;i++)
    {
        if(i!=s && i==q)
		{
			printf("\nDistance of %s from %s = %d  \t", city[i],city[s] ,distance[i]);
			printf("Path = %s", city[i]);
			j=i;
			do
			{
				j=path[j];
				printf("<-%s", city[j]);
			}
			while(j!=s);
		}
    }
	return;
}

void airways(int p,int q)
{

    printf("\nCurrently Running Flights\n");
    FILE* fp1;
    fp1=fopen("flight.txt","r");
    for(int i=0;i<10;i++)
    {
        fscanf(fp1,"%s %d %d",m[i].name,&m[i].price,&m[i].seats);
    }
    printf("Flight Name        Price         Seats_Avalable\n");
    for(int i=0;i<10;i++)
    {
        printf("%-10s\t%-14d%8d\n",m[i].name,m[i].price,m[i].seats);
    }
    fclose(fp1);
    printf("\n");
    printf("Flight details cheapest to costliest\n");           ///.....................
    selection_sort(10,m);
    printf("\n");
    printf("Shortest distance between source and destination through airways\n");  ///....................
    int a[10][10], i, j;
	printf("\nEnter the adjacency matrix:\n");
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			scanf("%d", &a[i][j]);
	flightdijikstra(a,10,p,q);
}

/**

Input function to read distance between connected places (By road)
void read_road_dist(int roadway[VERT][VERT]){
    int i,j;
    printf("Enter the distance\n");
    for(i=1;i<=VERT;i++)
    {
        for(j=1;j<=VERT;j++)
            scanf("%d",&roadway[i][j]);
    }
    return;
}

**/
