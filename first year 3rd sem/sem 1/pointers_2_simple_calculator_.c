#include<stdio.h>



void calculate(int n1, int n2, int *add, int *sub, int *mul,int *div)
{
    int subt;
    *add=n1+n2;

    subt=n1-n2;
    if(subt>=0)
        *sub=subt;
    else
    *sub=-subt;

    *mul=(n1*n2);

    *div=n1/n2;

}


int main()
{
    int n1, n2, add, sub, mul, div, mod;
    scanf("%d%d",&n1,&n2);
    calculate(n1,n2,&add,&sub,&mul,&div);
    printf("Sum = %d\nDifference = %d\nProduct = %d\nQuotient = %d",add,sub,mul,div);

}
