#include<stdio.h>
int main()
{
    int n,i;
    printf("enter the number\n");
    scanf("%d",&n);

    for (i=2 ; i<=(n-1) ; i++)
    {
        if (n%i == 0)
        {
            printf("its not a prime number\n");
            break;
        }


    }

    if (i==n)
    printf("it is a prime number\n");


    return 0;


}
