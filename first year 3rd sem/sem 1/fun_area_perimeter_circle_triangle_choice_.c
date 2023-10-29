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
    int option;

    printf("Choose an option\n1. area of circle\n2. circumference of circle\n");
    printf("3.area of triangle");
    scanf("%d",&option);

    switch(option)
    {
        case 1:
            {
                printf("enter the radius\n");
                scanf("%f",&radius);


                a = area_circle(radius);
                printf("area of circle=%f\n\n",a);

            }
            break;


        case 2:
            {
                 a = circum_circle(radius);
                 printf("circumference of circle=%f\n\n",a);
            }
            break;


        case 3:
            {
                printf("enter base and height\n");
                scanf("%f%f",&base,&height);

                a = area_triangle(base,height);
                printf("area of triangle=%f\n\n",a);
            }
            break;


        default:
            {
                printf("went wrong");

            }


    }

    return 0;









}


