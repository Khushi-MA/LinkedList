
#include<stdio.h>

typedef struct date
{
    int d,m,y;
}DATE;

void read_date (DATE *D)
{
    printf("\nenter date\n date\t");
    scanf("%d",&D->d);
    printf("month\t");
    scanf("%d",&D->m);
    printf("year\t");
    scanf("%d",&D->y);
}

int check_date (DATE *D)
{
    if(D->m>=1 && D->m<=12)
    {
        if (D->m==2)
        {
            if((D->y%4)==0)
            {
                if (D->d>=1 && D->d<=29)
                return 1;
            }

            else if(D->d>=1 && D->d<=28)
               return 1;

            else
                return 0;
        }

        else if(D->m==4 ||D->m==6 ||D->m==9 ||D->m==11)
        {
            if (D->d>=1 && D->d<=30)
            return 1;
        }

        else if (D->d>=1 && D->d<=31)
            return 1;

        else
            return 0;
    }

    else
    return 0;
}

int main()
{
    DATE D;
    int y;
    read_date(&D);
    y=check_date(&D);
    if(y==1)
        printf("\n\nvalid\n\n");
    else
        printf("\n\ninvalid\n\n");

}




