#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number:  ");
    scanf("%d",&n);
    printreverse(n);
    return 0;
}

void printreverse(int n)
{
    if(n==0)
    return;
    else
    {
        printf("%d  ",n);
        printreverse(n-1);
    }
    return ;
}