/*the length and breadth of rectangle and radius of a circle
is input. calculate the area and perimeter of both the shapes*/



#include<stdio.h>
int main()
{
    int l,b,r,ar,pr;
    float ac,pc;
    printf("enter length, breadth, radius");
    scanf("%d%d%d",&l,&b,&r);
    pr=2*l+2*b;
    ar=l*b;
    pc=2*3.14*r;
    ac=3.14*r*r;
    printf("perimeter of rectangle=%d\n",pr);
    printf("area of rectangle=%d\n",ar);
    printf("perimeter of circle=%f\n",pc);
    printf("area of circle=%f\n",ac);
    return 0;

}
