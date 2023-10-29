#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c;
    float s,t,area;
    printf("enter sides of triangle: ");
    scanf("%d%d%d",&a,&b,&c);
    s=(a+b+c)/3;
    t= s*(s-a)*(s-b)*(s-c);
    area = sqrt(t);
    printf("The area of triangle = %f\n",area);
    return 0;
}
