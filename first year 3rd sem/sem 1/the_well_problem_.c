/*program to calculate the following question
a man fell in D..m deep well.
He climbs n..m up and slips down m..m in one day.
how many days would it take from him to come out?*/

#include<stdio.h>
int main()
{
    float D,c,s,t;
    printf("the depth of well \n climbs \n slips \n");
    scanf("%f%f%f",&D,&c,&s);
    t=D/(c-s);
    printf("days taken=%f",t);
    return 0;
}
