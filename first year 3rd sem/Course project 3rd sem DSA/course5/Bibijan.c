#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 100

struct hotel                            ///structure for storing hotel detail
{
    char name[100];
    float rating;
    char add[100];
    int price;
};

struct city                              ///structure to store city
{
    char* name;
};

struct nodee                              ///tree for hotel
{
    struct nodee *l;
    struct nodee *r;
    float rat;
    char name[100];
    char add[100];
    int price;
};
typedef struct nodee *nodee;


struct NODE   ///airway structure
{
    char name[30];
    int price;
    int seats;
    char des[30];
};
typedef struct NODE *NODE;

struct roam                             ///structure to roam
{
    char place[30];
    int km;
    char loc[30];
};

typedef struct StackNode
{
    char data[MAX_LEN];
    struct StackNode* next;
} StackNode;

struct hotel h[100];  ///structured array to store hotel detail
struct hotel z[100];
struct city city[100];    ///structured to store city detail
struct NODE m[100];        ///structure to store flight details
struct roam roam[100];


void near_hotels(char d[],struct hotel h[]);
nodee create(char namee[],float data,char addr[],int roka);
void insert(nodee root,char name[],float data,char addr[],int roka);
void inorder(nodee root);
void airways(int p,int q,struct NODE m[],char d[]);
void hotel_rating(char d[],struct hotel z[]);
void places_roam(char d[],struct roam roam[]);
StackNode* push(StackNode* top, char* data);
StackNode* pop(StackNode* top) ;
void history(StackNode* top);
void dijikstra(int a[10][10], int n, int s,int q);


int main()
{
    printf("                                       WELCOME\n");
    printf("                          Namaste :)                   HOLA!!!!");
    printf(" \n");
    printf("\n");
    printf("  Choose what you wish for :) \n");
    printf("\n");
    nodee root=NULL;
     char s[50],d[50];
    float r[30],o[30];
    int p,q,n,a[10][10];
    //struct hotel h[100];
    //struct node city[100];
    city[1].name="Pune";
    city[2].name="Mumbai";
    city[3].name="Shimla";
    city[4].name="Maldives";
    city[5].name="Delhi";
    city[6].name="Dubai";
    city[7].name="Varanasi";
    city[8].name="Bengluru";
    city[9].name="Manali";
    city[10].name="Ladakh";
    printf("Choose cities!!\n");
    printf("Where do you wanna start your journey from?\n");
    scanf("%s",s);
    printf("what's your destination?\n");
    scanf("%s",d);
    for(int j=1;j<=10;j++)
    {
        if(strcmp(s,city[j].name)==0)
             p=j;
    }
    for(int k=1;k<=10;k++)
    {
        if(strcmp(d,city[k].name)==0)
             q=k;
    }
    FILE* file;
    file=fopen("search_history.txt","a");
    fprintf(file,"%s %s\n",city[p].name,city[q].name);
    fclose(file);
    StackNode* top = NULL;
    char buffer[MAX_LEN];
    file = fopen("search_history.txt", "r");
    if (file == NULL)
    {
        printf("Error: Could not open file\n");
        return 1;
    }
    while (fgets(buffer, MAX_LEN, file) != NULL)
    {
        int len = strlen(buffer);
        if (buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0';
        }
        top = push(top, buffer);
    }
    fclose(file);
    printf("\n");
    printf("\n");
    printf("Nice Choice Of City\n");
    //printf("What Next?\n");
    while(1)
    {
        printf("\n");
        printf("What Next?\n");
        printf("1: Best Hotels near %s\n",d);
        printf("2: High Rated Hotels on our page\n");
        printf("3: Distance Through Airway\n");
        printf("4: Checkout Flights Flying to %s\n",d);
        printf("5: Attraction near/around %s\n",d);
        printf("6: Look what you Searched for\n");
        printf("7:would you like to switch source and destination\n");
        scanf("%d",&n);
        switch(n)
        {

            case 1:near_hotels(d,h);
                    printf("\n");
                   break;
            case 2: hotel_rating(d,z);
                    root=create(z[1].name,z[1].rating,z[1].add,z[1].price);             ///functional call for sorting rating less to max
                    for(int l=2;l<=30;l++)
                    {
                        insert(root,z[l].name,z[l].rating,z[l].add,z[l].price);
                    }
                    inorder(root);
                    printf("\n");
                    break;
            case 3:dijikstra(a,10,p,q);
                   break;
            case 4:airways(p,q,m,d);
                    break;
            case 5:places_roam(d,roam);
                   break;
            case 6:history(top);                 ///
                   break;
             case 7:printf("Choose cities!!\n");
    printf("Where do you wanna start your journey from?\n");
    scanf("%s",s);
    printf("what's your destination?\n");
    scanf("%s",d);
    break;
            default:exit(0);
                    break;
        }
    }


}


void near_hotels(char d[],struct hotel h[])             ///search nearby hotels
{
    FILE* fp1;
    fp1=fopen("hotel.txt","r");
    for(int i=1;i<=30;i++)
    {
        fscanf(fp1,"%s %f %s %d",h[i].name,&h[i].rating,h[i].add,&h[i].price);
    }
    printf("\n");
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

void insert(nodee root,char name[],float data,char addr[],int roka)             ///insert hotels in tree order of rating
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

void inorder(nodee root)                           ///displaying hotels according to highest rating
{
    int i=1;
    if(root!=NULL)
    {
        inorder(root->r);
        printf("%-10s\t%-12.01f\t%8s\t%10d\n",root->name,root->rat,root->add,root->price);
        inorder(root->l);
    }
}

void selection_sort(int n,struct NODE a[],char d[])          ///sorting airway accordinf to price
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
    printf("Flight Name\tPrice\tSeats_Avalable\n");
    for(int i=1;i<=n;i++)
    {if(strcmp(a[i].des,d)==0)
        printf("%-10s\t%-14d\t%8d\n",a[i].name,a[i].price,a[i].seats);
    }
}

void airways(int p,int q,struct NODE m[],char d[])                              ///flights to your destination
{

    printf("\nCurrently Running Flights to in our service \n");
    FILE* fp1;
    fp1=fopen("flight.txt","r");
    for(int i=1;i<=10;i++)
    {
        fscanf(fp1,"%s %d %d %s",m[i].name,&m[i].price,&m[i].seats,m[i].des);
    }
    printf("Flight Name          Price         Seats_Available   destination\n");
    for(int i=1;i<=10;i++)
    {
        printf("%-10s\t    %-14d%8d                  %s\n",m[i].name,m[i].price,m[i].seats,m[i].des);
    }
    fclose(fp1);
    printf("\n");
    printf("Flight details cheapest to costliest to %s\n",d);           ///.....................
    selection_sort(10,m,d);
    printf("\n");
    //printf("Shortest distance between source and destination through airways\n");  ///....................
}

void hotel_rating(char d[],struct hotel z[])
{
    FILE* fp1;
    fp1=fopen("hotel.txt","r");
    for(int i=1;i<=30;i++)
    {
        fscanf(fp1,"%s %f %s %d",z[i].name,&z[i].rating,z[i].add,&z[i].price);
    }
    fclose(fp1);
}

void places_roam(char d[],struct roam roam[])             ///search plces nearby
{
    int i=1;
    FILE* fp1;
    fp1=fopen("roam.txt","r");
    for(int i=1;i<=200;i++)
    {
        fscanf(fp1,"%s %d %s",roam[i].place,&roam[i].km,roam[i].loc);
        i++;
    }
    printf("\n");
    //printf("Hotels in %s\n",d);
    printf("Places to roam                Distance(in kms)  Location\n ");
    for(int i=1;i<=100;i++)
    {
        if(strcmp(roam[i].loc,d)==0)
        {
            printf("%-29s\t%-12.01d\t%8s\n",roam[i].place,roam[i].km,roam[i].loc);
        }
    }
    fclose(fp1);
}



StackNode* push(StackNode* top, char* data)
{
    StackNode* new_node = malloc(sizeof(StackNode));
    strcpy(new_node->data, data);
    new_node->next = top;
    return new_node;
}


StackNode* pop(StackNode* top)
{
    if (top == NULL) {
        return NULL;
    }
    StackNode* temp = top;
    top = top->next;
    free(temp);
    return top;
}


void history(StackNode* top)
{
    printf("\nSearch history:\n");
    while (top != NULL)
    {
        printf("%s\n", top->data);
        top = top->next;
    }
}


void dijikstra(int a[10][10], int n, int s,int q)
{
    int i,j;
    FILE* fp1;
    fp1=fopen("distance_air.txt","r");
	for(i=0;i<10;i++)
    {
		for(j=0;j<10;j++)
        {
			fscanf(fp1,"%d",&a[i][j]);
        }
    }
	int cost[10][10], distance[10], path[10];
	int visited[10], count, min, u;
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
	while(count < n-1){
		min=999;
		for(i=0;i < n;i++)
			if(distance[i] < min&&!visited[i])
			{
				min=distance[i];
				u=i;
			}
		visited[u]=1;
		for(i=0;i < n;i++)
			if(!visited[i])
				if(min+cost[u][i] < distance[i])
				{
					distance[i]=min+cost[u][i];
					path[i]=u;
				}
			count++;
	}

	for(i=0;i<n;i++)
    {

		if(i!=s && i==q)
		{
			printf("\nDistance between %s and %s = %d  \t", city[s],city[i] ,distance[i]);
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
    printf("\n");
}
