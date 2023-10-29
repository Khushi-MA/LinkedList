#include<stdio.h>
int main()
{
    float pH;
    printf("enter pH of the sample");
    scanf("%f",&pH);

    if (pH>7)
    {
        if (pH<12)
        {
            printf("alkaline");
        }

        else
        {
            printf("very alkaline");
        }
    }

    else
    {
        if (pH==7)
        {
            printf("neutral");
        }

        else if (pH<2)
        {
            printf("very acidic");
        }

        else
        {
            printf("acidic");
        }
    }

    return 0;
}
