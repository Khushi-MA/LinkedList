#include<stdio.h>
int fun(int, int*);
int main()
{
    int x=15,f;
    printf("enter number 'x':  ");
    scanf("%d",&x);
    printf("enter number 'f':  ");
    scanf("%d",&f);
    f=fun(5,&x);
    printf("x = %d\nf = %d",x,f);
    return 0;
}

int fun(int n, int *p)
{
    int t,f;
    if(n<=1)
    {
        *p=1;
        return 1;
    }

    t=fun(n-1,p);
    *p=t;
    return f;
}