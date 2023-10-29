#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

};
typedef struct NODE *NODE;


struct hotel h[100];
struct node city[100];
struct NODE m[100];

void near_hotels(char d[],struct hotel h[]);
nodee create(char namee[],float data,char addr[],int roka);
void insert(nodee root,char name[],float data,char addr[],int roka);
void inorder(nodee root);
void airways(int p,int q,struct NODE m[]);



int main()
{
    printf("                                       WELCOME\n");
    printf("                          Namaste :)                   HOLA!!!!");
    printf(" \n");
    printf("\n");
    printf("  Choose what you wish for :) \n");
    printf("\n");
    //printf("1: Travelling?\n");
    //printf("2: Best Hotels on our Page\n");
    //scanf("%d",n);
    nodee root=NULL;
     char s[50],d[50];
    float r[30],o[30];
    int p,q,n;
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
    printf("Enter source and destination\n");
    scanf("%s%s",s,d);
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
    printf("\n");
    printf("\n");
    printf("Nice Choice Of City\n");
    printf("What Next?\n");
    while(1)
    {
        printf("1: Best Hotels near %s\n",d);
        printf("2: High Rated Hotels on our page\n");
        printf("3: Checkout Flights Flying to %s",d);
        scanf("%d",&n);
        switch(n)
        {

            case 1:near_hotels(d,h);
                    printf("\n");
                   break;
            case 2:/*for(int j=1;j<=30;j++)
                    {
                            printf("%-10s\t%-12.01f\t%8s\t%10d\n",h[j].name,h[j].rating,h[j].add,h[j].price);
                    }*/
                    root=create(h[1].name,h[1].rating,h[1].add,h[1].price);             ///functional call for sorting rating less to max
                    for(int l=2;l<=30;l++)
                    {
                        insert(root,h[l].name,h[l].rating,h[l].add,h[l].price);
                    }
                    //printf("sorting done\n");
                    inorder(root);
                    break;
            case 3:airways(p,q,m);
                    break;
            default:exit(0);
                    break;
        }
    }


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

void airways(int p,int q,struct NODE m[])
{

    printf("\nCurrently Running Flights\n");
    FILE* fp1;
    fp1=fopen("flight.txt","r");
    for(int i=1;i<=10;i++)
    {
        fscanf(fp1,"%s %d %d",m[i].name,&m[i].price,&m[i].seats);
    }
    printf("Flight Name        Price         Seats_Avalable\n");
    for(int i=1;i<=10;i++)
    {
        printf("%-10s\t%-14d%8d\n",m[i].name,m[i].price,m[i].seats);
    }
    fclose(fp1);
    printf("\n");
    printf("Flight details cheapest to costliest\n");           ///.....................
    selection_sort(10,m);
    printf("\n");
    printf("Shortest distance between source and destination through airways\n");  ///....................
    //int a[10][10], i, j;
	/*printf("\nEnter the adjacency matrix:\n");
	for(i=1;i<=10;i++)
		for(j=1;j<=10;j++)
			scanf("%d", &a[i][j]);
	dijikstra(a,10,p);*/
}