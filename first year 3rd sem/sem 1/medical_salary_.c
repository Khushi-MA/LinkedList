/*

HRA = 20% of basic
DA = 110% of basic
conveyance = Rs.500

*/
#include<stdio.h>
int main()
{
    int sales;
    float basic_salary,incentive,bonus,incentive_amount,salary,HRA,DA,conveyance;


    printf("enter basic salary\n");
    scanf("%f",&basic_salary);

    printf("enter total sales\n");
    scanf("%d",&sales);

    printf("enter enter incentive of sales in percent \n");
    scanf("%f",&incentive);

    printf("enter bonus to be given\n");
    scanf("%f",&bonus);

    HRA=basic_salary*0.2;

    DA=basic_salary*1.1;

    incentive_amount=(incentive/100)*sales;

    conveyance==500;


    if (sales>10000)
        salary = basic_salary + HRA + DA + conveyance + bonus;

    else
        salary = basic_salary + HRA + DA ;


    printf("total salary = %f",salary);

    return 0;







}
