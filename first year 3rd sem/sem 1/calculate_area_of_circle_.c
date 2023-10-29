/*program to calculate the area of the circle*/
#include<stdio.h>
int main()
{
    float r,a;       /*known part of PSF*/
    printf("enter the radius\n");
    scanf("%f",&r);
    a=3.14*r*r;
    printf("area of the circle = %f",a);
    return 0;
}
