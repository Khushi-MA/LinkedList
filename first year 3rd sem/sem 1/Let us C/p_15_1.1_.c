#include<stdio.h>
int main()
{
    float sal,dear,rent,gross;
    printf("Enter basic salary of Ramesh: ");
    scanf("%f",&sal);
    dear = 0.4*sal;
    rent = 0.2*sal;
    gross = sal+dear+rent;

    printf("\nBasic salary of Ramesh = %f",sal);
    printf("\nDearness Allowance = %f",dear);
    printf("\nHouse Rent Allowance = %f",rent);
    printf("\nGross Pay of RAmesh = %f",gross);

    printf("%f",gross);
    return 0;

}
