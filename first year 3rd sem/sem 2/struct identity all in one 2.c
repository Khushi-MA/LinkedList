#include<stdio.h>
#include<math.h>
#include<string.h>
#define size 20


typedef struct
{
    char fname[10],mname[10],lname[10];
}NAME;


typedef struct
{
    int dd,mm,yy;
}DOB;


typedef struct
{
    NAME nam;
    int age;
    char pan[10];
    DOB b;
    long int phno;
}PERSON;


void read_id (PERSON p[size], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nenter the details:\n");
        printf("enter name of the person; first middle and last\t");
        scanf("%s%s%s",p[i].nam.fname,p[i].nam.mname,p[i].nam.lname);
        printf("enter age of the person\t");
        scanf("%d",&p[i].age);
        printf("enter pan number\t");
        scanf("%s",p[i].pan);
        printf("enter date of birth of the person date month and year\n");
        scanf("%d%d%d",&p[i].b.dd,&p[i].b.mm,&p[i].b.yy);
        printf("enter phone number of the person\n");
        scanf("%ld",&p[i].phno);
    }
}

void display_id (PERSON p[size], int n)
{
    int i;
    printf("\ns.no.\tname\t\tage\tpan.number\tdob\tphone\t");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t%s %s %s\t%d\t%s\t\t%d/%d/%d\t%ld\t",1+i,p[i].nam.fname,p[i].nam.mname,p[i].nam.lname,p[i].age,p[i].pan,p[i].b.dd,p[i].b.mm,p[i].b.yy,p[i].phno);
    }
}

void display_one_id (int i,PERSON p[size])
{
    printf("\n%d\t%s %s %s\t%d\t%s\t\t%d/%d/%d\t%ld\t",1+i,p[i].nam.fname,p[i].nam.mname,p[i].nam.lname,p[i].age,p[i].pan,p[i].b.dd,p[i].b.mm,p[i].b.yy,p[i].phno);
}




void search_year(PERSON p[size],int n,int year)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(p[i].b.yy==year)
        {
            printf("\ns.no.\tname\t\tage\tpan.number\tdob\tphone\t");
            display_one_id(i,p);
        }
        else
        {
            printf("\nno one is there");
        }
    }
}
/*
void struct_search (DOB udate,PERSON p[size],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(p[i].b==udate)
        {
            printf("\nyou can search structure");
        }
    }
}
*/


int main()
{

    PERSON p[size];
    DOB udate;
    int n,year;
    printf("\nenter the number of people you want to add\n");
    scanf("%d",&n);
    read_id(p,n);
    display_id(p,n);
    printf("\nsearch a person(people) who is(are) born in the same year\t");
    scanf("%d",&year);
    search_year(p,n,year);
    printf("\nenter year structure");
    //  scanf("%d%d%d",&udate.dd,&udate.mm,&udate.yy);      did not suceed!!!
    //  struct_search(udate,p,n);
}

