/*
Ram is paying  the electricity bills online. help Ram to input
account number and electricity unit charge and calculate the
total electricity bill according to the given condition:
for first 50 units Rs. 0.50/unit
for next 100 units Rs. 0.75/unit
for next 100 units Rs. 1.20/unit
for unit above 250 Rs. 1.50/unit
An additional charge of 20% is added to the bill.
Apply problem solving framework

*/

#include<stdio.h>
int main()
{
    float unit,charge,bill,ac;
    printf("enter account number\n");
    scanf("%f",&ac);
    printf("electricity unit\n");
    scanf("%f",&unit);



    if (unit<=50)
        charge = unit*0.5;

    else if (unit>50 && unit<=150)
        charge = 25 + (unit-50)*0.75;

    else if (unit>150 && unit<=250)
       charge = 100 + (unit-150)*1.2;

    else
       charge = 220 + (unit-250)*1.5;


    bill = 1.2*charge;
    printf("account number = %f\n",ac);
    printf("total electricity bill = %f ",bill);

    return 0;


}

