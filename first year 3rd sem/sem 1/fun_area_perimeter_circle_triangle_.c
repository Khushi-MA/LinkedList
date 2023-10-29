#include<stdio.h>
#include<math.h>
#define Pi 3.142

float a_c(float r_s)
{
    float area,R;
    area = Pi*R*R;
    return area;
}

float a_t(float r_s)
{
    float area;
    area = 1.72/4*r_s*r_s;
    return area;


}

float c_c(float r_s)
{
    float circumference;
    circumference = Pi*r_s*2;
}


int main()
{
    float a,c,r_n;
    printf("enter the side or radius\n\n");
    scanf("%f",&r_n);




}
