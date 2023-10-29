#include<stdio.h>
int main()
{
    int number,reminder,quotient,i;
    printf("number = ");
    scanf("%d",&number);
    i=1;
    printf("divisors:\n");

    while (i<=number)
    {
        reminder = number%i;

        if (reminder==0)
            {
                quotient = number/i;
                printf("%d\n",quotient);
            }

        i++;
    }

}
