#include<stdio.h>

int compute(float basic)
{
    float HRA, DA, gross;
    HRA = basic*20/100;
    DA = basic*40/100;
    gross = basic+HRA+DA;
    return gross;


}

int main()
{
    float basic,g;
    printf("enter basic salary\n");
    scanf("%f",&basic);
    g=compute(basic);
    printf("gross salary= %f",g);


}

