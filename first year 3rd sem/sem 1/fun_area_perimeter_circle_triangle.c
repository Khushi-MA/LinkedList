#include<stdio.h>
#define Pi 3.142


float area_circle(float radius)
{
    float area;
    area = Pi*radius*radius;
    return area;
}


float circum_circle(float radius)
{
    float circumference;
    circumference = 2*Pi*radius;
    return circumference;
}


float area_triangle(float b, float h)
{
    float area;
    area = b*h*0.5;
    return area;
}


int main()
{
    float radius, a;
    float base, height;

    printf("enter the radius\n");
    scanf("%f",&radius);

    a = area_circle(radius);
    printf("area of circle=%f\n\n",a);

    a = circum_circle(radius);
    printf("circumference of circle=%f\n\n",a);

    printf("enter base and height\n");
    scanf("%f%f",&base,&height);

    a = area_triangle(base,height);
    printf("area of triangle=%f\n\n",a);


}


