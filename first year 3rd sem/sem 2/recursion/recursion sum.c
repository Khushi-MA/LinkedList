#include<stdio.h>
int main()
{
    int n;
    printf("enter n to find sum from 1 to n:  ");
    scanf("%d",&n);
    n=sum(n);
    printf("\nsum = %d",n);
    return 0;
}

int sum(int n)
{
    if (n==1)
        return 1;

    else
        return n+sum(n-1);s
}
