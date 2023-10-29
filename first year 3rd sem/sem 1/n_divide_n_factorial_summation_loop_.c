#include<stdio.h>
int main()
{
    int i,n;
    float product, sum;
    printf("print the number\n");
    scanf("%d",&n);

    for (sum=0, i=1, product=1 ; i<=n ; i++)
    {
        product = product * i;
        sum = sum + i/product;
        printf("sum at every step = %f\n",sum);

    }

    printf("\nsum of given series = %f\n",sum);



    return 0;

}





