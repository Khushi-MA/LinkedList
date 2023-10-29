


#include<stdio.h>
int main()
{
    float unit,charge;
    printf("enter units consumed");
    scanf("%f",&unit);

    if (unit<=200)
        charge=(2.5*unit);

    else if (unit>200 && unit<=400)
        charge=100+6.5*(unit-200);

    else if (unit>400 && unit<=600)
        charge=250+0.8*(unit-400);

    else if (unit>600)
        charge=400+1*(unit-600);

    printf("amount to be paid = %f",charge);

    return 0;


}


