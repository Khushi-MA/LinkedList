/*A metal rod is taken. Both ends of the rod
are maintained with different temperatures.
The area of cross section, its length,
thermal conductivity of the metal,
temperatures T1 and T2 are input.
device a program to find the rate of heat flow.*/

#include<stdio.h>
#include<math.h>
int main()
{
    float K,A,L,T1,T2,q;
    printf("enter area of cross section");
    scanf("%f",&A);
    printf("enter length of rod");
    scanf("%f",&L);
    printf("enter thermal conductivity of the metal");
    scanf("%f",&K);
    printf("let temperature T1 > T2\n");
    printf("enter temperature T1");
    scanf("%f",&T1);
    printf("enter temperature T2");
    scanf("%f",&T2);

    q=K*A*(T1-T2)*pow(L,-1);
    printf("the rate of heat flow,q = %f",q);

    return 0;
}
