#include<stdio.h>

typedef struct date
{
    int d,m,y;
}DATE;

int main()
{
    DATE D;
    printf("\nenter date\n date\t");
    scanf("%d",&D.d);
    printf("month\t");
    scanf("%d",&D.m);
    printf("year\t");
    scanf("%d",&D.y);

    if (D.m==2)
    {
        if((D.y%4)==0)
        {
            if (D.d>=1 && D.d<=29)
                printf("\n\nvalid\n\n");

            else
                printf("\n\ninvalid\n\n");
        }

        else
        {
            if(D.d>=1 && D.d<=28)
            {
                 printf("\n\nvalid\n\n");
            }

            else
                printf("\n\ninvalid\n\n");
        }
    }

    else if(D.m==4 ||D.m==6 ||D.m==9 ||D.m==11)
    {
        if (D.d>=1 && D.d<=30)
        printf("\n\nvalid\n\n");

        else
        printf("\n\ninvalid\n\n");
    }

    else if(D.m==1 ||D.m==3 ||D.m==5 ||D.m==7 ||D.m==8 ||D.m==10 ||D.m==12)
    {
        if (D.d>=1 && D.d<=31)
        printf("\n\nvalid\n\n");

        else
        printf("\n\ninvalid\n\n");
    }

    else
    printf("\n\ninvalid\n\n");


}


