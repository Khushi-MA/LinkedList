#include<stdio.h>
int main()
{
    int n,sum;
    printf("Enter N:  ");
    scanf("%d",&n);
    sum=sumnatural(n);
    printf("Sum = %d",sum);
}

int sumnatural(int n)
{
    if(n==1)
    return 1;

    int y=sumnatural(n-1);
    return (n+y);
}