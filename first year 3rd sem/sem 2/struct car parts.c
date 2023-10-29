/*
an automobile company
engine parts AA0 to FF9.
year of manufacture
material
quantity
*/
#include<stdio.h>
#include<string.h>
#define size 100
typedef struct automobile_part
{
    char no[3];
    int year;
    char matr[10];
    int qt;
}PART;

void read_info (PART p, int n)
{
    int i;
    printf("enter the information");
    for(i=0;i<n;i++)
    {
        printf("\nenter the part no ");
        scanf("%s",p.no);
    }
}

int main()
{
    PART p[size];
    int n;

    printf("\nenter the number of parts ");
    scanf("%d",&n);

    read_info(p,n);

}


