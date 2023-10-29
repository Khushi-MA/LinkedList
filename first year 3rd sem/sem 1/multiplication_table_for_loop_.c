#include<stdio.h>
int main()
{
    int n,i,m,t;
    printf("enter the number whose tables are required\n");
    scanf("%d",&n);
    printf("enter the number till the tables are required\n");
    scanf("%d",&t);

    for ( i=1 ; i<=t ; i++ )
    {

        printf(" %d x %d = %d \n ",n,i,n*i);

    }

    return 0;


}
