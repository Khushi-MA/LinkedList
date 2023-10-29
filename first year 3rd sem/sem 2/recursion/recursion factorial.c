#include<stdio.h>
int main()
{
    int n;
    printf("enter the number to find factorial   ");
    scanf("%d",&n);
    n=factorial(n);
    printf("\nfactorial is:  %d",n);
    return 0;
}

int factorial(int n)
{
    if(n==0)
        return 1;

    else
        return (n*factorial(n-1));
}

