
/* A commercial bank accepts fixed deposits from the public. the rates of interest very depending
on the number of days for which the deposits are made. The following are the rates

number of days              rate of interest
30 to 60 days               6%
61 to 90 days               6.5%
91 to 180 days              7%
181 to one year             8%
more than one year          8.5%

For senior citizens additional 1% is offered for deposits more than 50000.
write a program to accept the amount deposited and the number of days for
which the deposit is made and calculate the amount to be given to the
customer
after the given number of days.

principle amount = pa
no. of days = d
amount given = T
rate of interest = RI

*/


#include<stdio.h>
int main()

{
    int age,days;
    float principle_amt,rate_interest,total_amt,simple_interest;

    printf("enter age\n");
    scanf("%d",&age);

    printf("enter principle amount\n");
    scanf("%f",&principle_amt);

    printf("enter number of days\n");
    scanf("%d",&days);

    if ( days>=30 && days<=60 )
        rate_interest = 0.06;

    else if ( days>=61 && days<=90 )
        rate_interest = 0.065;

    else if ( days>=91 && days<=180 )
        rate_interest = 0.07;

    else if ( days>=181 && days<=365 )
        rate_interest = 0.08;

    else
        rate_interest = 0.085;

    if ( age>=60 && principle_amt>=50000)
        rate_interest = rate_interest*0.1;

    simple_interest = principle_amt*days*rate_interest;

    total_amt = simple_interest*principle_amt;

    printf("the total amount = %f",total_amt);


    return 0;


}
