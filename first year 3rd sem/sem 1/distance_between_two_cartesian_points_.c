/*this program is to calculate distance between
two points (a,b) and (c,d) in a cartesian plane */


#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c,d,s,S;
    printf("enter the cartesian points (a,b)and(c,d)");
    scanf("%f%f%f%f",&a,&b,&c,&d);
    s=(a-c)*(a-c)+(b-d)*(b-d);
    S=sqrt(s);
    printf("distance=%f\n",S);
    return 0;

}
