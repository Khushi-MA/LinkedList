/*program to calculate the sum of digits
when input a five digit number
solution:
n= number
s=sum
r=remainder
*/

#include<stdio.h>
int main()
{
    int n,s,r;
    printf("enter a 5 digit number");
    scanf("%d",&n);

    s=0;

    r=n%10;
    s=s+r;
    n=n/10;

    r=n%10;
    s=s+r;
    n=n/10;

    r=n%10;
    s=s+r;
    n=n/10;

    r=n%10;
    s=s+r;
    n=n/10;

    r=n%10;
    s=s+r;
    n=n/10;

    printf("sum of digits=%d",s);
    return 0;
}

