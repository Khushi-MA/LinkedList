/*A computer manufacturing company has the following monthly compensation policy
to their sales person

min base salary:  15000.00
bonus for every computer computer sold:  1000.00
commission on total monthly sales:  2 percent

Since the prices of computer are changing,
the sales price of each computer is fixed at the
beginning of every month. Apply problem solving
framework to compute a sales-person's gross salary

Explanation:
base salary BS = 15000
bonus = B
total sales = TS
gross salary = GS
number of computers sold = N
Commission = Com
*/

#include<stdio.h>
#define price 40000.0 // symbolic constant or macro
int main()
{
    int BS,N;
    float B,GS,TS,Com;
    printf("enter base salary \n");
    scanf("%f",&BS);
    printf("enter number of computers sold");
    scanf("%d",&N);
    TS = N*price;
    Com = 2.0/100*TS;
    GS=BS+B+Com;
    printf("the goss salary = %f",GS);

    return 0;
}

