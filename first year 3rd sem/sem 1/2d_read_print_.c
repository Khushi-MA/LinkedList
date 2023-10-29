#include<stdio.h>
#define r 3
#define c 3

void read_ele(int a[r][c])
{
    int i,j;

    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
        scanf("%d",&a[i][j]);

    return ;
}

void print_ele(int a[r][c])
{
    int i,j;
    printf("\nthe elements of matrix are:");
    for(i=0;i<r;i++)
    {
        printf("\n");              //new line after row
        for(j=0;j<c;j++)
        printf("%d\t",a[i][j]);
    }
   printf("\n");
}

void sum_2d(int a[r][c])
{
    int i,j,sum;
    for(i=0, sum=0;i<r;i++)
        for(j=0;j<c;j++)
        sum=sum+a[i][j];
}


int main()
{
    int a[r][c];

    read_ele(a);
    print_ele(a);
    sum_2d(a);

}


