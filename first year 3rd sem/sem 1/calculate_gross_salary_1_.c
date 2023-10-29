


#include<stdio.h>
int main()
{
    float basic_salary,HRA,GS,DA;
    printf("enter the salary");
    scanf("%d",&basic_salary);
    HRA=0.2*basic_salary;
    DA=0.4*basic_salary;
    GS=basic_salary+HRA+DA;
    printf("gross salary=%d",GS);
    return 0;
}
