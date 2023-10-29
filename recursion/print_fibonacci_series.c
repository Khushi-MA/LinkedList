#include<stdio.h>
void fib(int);
void _fib(int, int, int);
int main()
{
    printf("Enter the number 'n':   ");
    int n;
    scanf("%d",&n);
    fib(n);
    return 0;
}

void fib(int n)
{
    _fib(n,-1,1);
    return;
}

void _fib(int n, int a, int b)
{
    if(n==0)
    return;
    else
    {
        printf("%d  ",(a+b));
        _fib(n-1,b,a+b);
    }
}