#include<stdlib.h>
#include <stdio.h>
#include <string.h>

struct hotel {
    char name[50];
    float ratings;
    char addr[20];
    int price;
};

struct node
{
    char* name;
};

void near_hotels(char d[]);

int main()
{
    int n=100;
    char s[50],d[50];
    int p,q;
    struct node cityy[n];
    //int i=1;
    cityy[1].name="Pune";
    cityy[2].name="Mumbai";
    cityy[3].name="Shimla";
    cityy[4].name="Maldives";
    cityy[5].name="Delhi";
    cityy[6].name="Dubai";
    cityy[7].name="Varanasi";
    cityy[8].name="Bengluru";
    cityy[9].name="Manali";
    cityy[10].name="Ladakh";
    printf("Enter source and destination\n");
    scanf("%s%s",s,d);
    for(int j=1;j<=10;j++)
    {
        if(strcmp(s,cityy[j].name)==0)
             p=j;
    }
    for(int k=1;k<=10;k++)
    {
        if(strcmp(d,cityy[k].name)==0)
             q=k;
    }
    printf("\n");
    near_hotels(d);
}

void near_hotels(char d[])
{
    FILE*fp1;
    struct hotel p1[100];
    fp1=fopen("hotel.txt","r");
    for(int i=1;i<=30;i++)
    {
        fscanf(fp1,"%s %f %s %d",p1[i].name,&p1[i].ratings,p1[i].addr,&p1[i].price);
    }
    printf("Nearby Hotel details\n");
    for(int i=1;i<=30;i++)
    {
        if(strcmp(p1[i].addr,d)==0)
             printf("%-10s\t%-12.1f\t%8s\t%10d\n",p1[i].name,p1[i].ratings,p1[i].addr,p1[i].price);
    }
    fclose(fp1);
}