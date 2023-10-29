#include<stdio.h>
int main()
{
    int n;
    printf("enter the number 'n':   ");
    scanf("%d",&n);
    printnatural(n);
}

void printnatural(int n)
{
    if(n==0)
    return;
    else
    {
        printf("%d\n",n);
        printnatural(n-1);
    }
}