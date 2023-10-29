/*when interest compounds q times per year at an annual rate of
r% for n years, the principal p compound to an amount as per
the following formula

a = p( 1 + r / q ) ^ nq

write a program to read 10 sets of p, r, n, q and calculating
the corresponding as.

number of years = n
principle amount = principle_amt
times = q
rate of interest = r
*/

#include<stdio.h>
#include<math.h>
int main()
{
    int i;
    float p, r, n, q, a, x, y;
    i=1;


    while (i<=10)
    {
        printf("set %d\n\n",i);

        printf("enter principle amount, p\n");
        scanf("%f",&p);

        printf("compounds q times a year\n");
        scanf("%f",&q);

        printf("enter number of years, n \n");
        scanf("%f",&n);

        printf("enter rate of interest, r \n");
        scanf("%f",&r);

        x = p*(1 + r/q);
        y = n*q;
        a = pow(x,y);

        printf("amount = %f\n\n",a);

        i++;
    }

    return 0;

}
