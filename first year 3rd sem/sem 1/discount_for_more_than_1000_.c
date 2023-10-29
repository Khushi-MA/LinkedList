/*While purchasing certain items, a discount of 10% is offered
if the quantity purchased is more than 1000.
If quantity and price per item are input through the keyboard,
write a program to calculate the total expenses.
*/


#include<stdio.h>
int main()
{
    int q;
    float a,A,T;
    printf("enter the quantity of goods purchased");
    scanf("%d",&q);
    printf("enter price per item");
    scanf("%f",&a);
    A=a*q;
    if(A>=1000)
    {
        A=A*0.9;
        printf("you got 10 percent discount, total bill=%f",A);
    }
    printf("total bill=%f",A);

    return 0;
}
