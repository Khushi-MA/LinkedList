#include<stdio.h>
#include<math.h>
int fgcd(int, int);
int main()
{
    int a,b,value;
    printf("Enter numbers: ");
    scanf("%d %d",&a,&b);
    value=fgcd(a,b);
    printf("GCD of %d and %d is %d",a,b,value);
    return 0;
}

int fgcd(int a, int b)
{
    if(a==0)
    return b;
    fgcd(b%a,a);
}