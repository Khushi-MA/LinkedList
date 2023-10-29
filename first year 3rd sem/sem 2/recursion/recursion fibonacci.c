#include<stdio.h>
int main()
{

    int n;
    printf("fibonacci:\nenter number:  ");
    scanf("%d",&n);
    n=fibonacci(n);
    printf("fibonacci:  %d",n);
    return 0;
}

int fibonacci(int n)
{
    if(n==0)
        return 0;

    else if (n==1)
        return 1;

    else
        return (fibonacci(n-1)+fibonacci(n-2));

}
