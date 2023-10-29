#include<stdio.h>

int main()
{
    int num, f;

    printf("enter the number\n");
    scanf("%d",&num);
    f=fact(num);
    printf("factorial is %d",f);
    return 0;
}

int fact(int a)
{
    int i, factorial;
    for(i=1,factorial=1;i<=a;i++)
    {
        factorial=factorial*i;
    }
    return factorial;

}
