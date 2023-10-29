/*a cashier has currency notes of Rs 10, 50, 100.
If the amount to be withdrawn is input in,
find the total no of notes of each denomination
*/


#include<stdio.h>
int main()
{

    int x,y,z,c,a,t;
    printf("enter the currency");
    scanf("%d",&a);
    x=a/100;
    a=a-100*x;
    y=a/50;
    a=a-50*y;
    z=a/10;
    a=a-10*z;
    c=a;

    printf("Rs 100 notes=%d\n",x);
    printf("Rs 50 notes=%d\n",y);
    printf("Rs 10 notes=%d\n",z);
    printf("total number of currency notes=%d",c);
    return 0;

}
