#include<stdio.h>
#include<math.h>

int b_d(int n)
{
    int r,i,b=0,r_1=0;
    while(n!=0)
    {
        r=n%10;
        b=b+r*pow(2,i);
        n=n/10;
        i++;
    }

    return b_d;
}

int main()
{
    int n,d;
    scanf("%d",n);
    d=b_d(n);
    printf("%d",d);
    return 0;

}

