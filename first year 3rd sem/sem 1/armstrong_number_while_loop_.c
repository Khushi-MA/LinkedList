#include<stdio.h>
int main()
{
    int n,m,rem,sum;
    printf("enter the number");
    scanf("%d",&n);
    m=n;
    sum=0;

    while (n!=0)
    {
        rem = n%10;
        sum = sum + rem * rem * rem;
        n = n/10;

    }



    if (sum==m)
    {
        printf("it is an armstrong number");
    }



    else
    {
         printf("it is not an armstrong number");

    }

    return 0;
}
