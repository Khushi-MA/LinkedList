/*to calculate the interest gained
on a fixed deposit after given time (years)
money deposited m= 100000
interest gained per year i= 4%
*/


#include<stdio.h>
int main()
{
    int y,ti,T;
    printf("enter the time in years");
    scanf("%d",&y);
    ti=4000*y;
    T=100000+ti;
    printf("interest gained in y years=%d\n",ti);
    printf("total amount in bank after y years=%d",T);
    return 0;



}
