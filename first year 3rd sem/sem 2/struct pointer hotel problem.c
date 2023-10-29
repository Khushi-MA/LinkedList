/* Marriot internatioal is a group of hotels, with N hotels across the globe.
to maintain information they hired an engineer
create structure with five appropriate elements
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define size 100

/// structure for hotel information

typedef struct hotel_info
{
    char name[20];                     /// name of the hotel
    char ID[10];                       /// hotel ID
    char country[10];                  /// country where it is
    int yoe;                           /// year of establishment
    double profit;                 /// profit per year
}HOTEL;

void read_info(HOTEL *P, int N)
{
    int i;
    printf("\nenter hotel details\n");
    for(i=0;i<N;i++,P+1)
    {
        printf("enter hotel name\t");
        scanf("%s",P->name);
        printf("enter restaurant ID\t");
        scanf("%s",P->ID);
        printf("enter profit");
        scanf("%lf",&P->profit);
    }
}

void display_info(HOTEL *P, int N)
{
    int i;
    printf("\ndisplay information");
    for(i=0;i<N;i++,P+1)
    {
        printf("hotel %d",i+1);
        printf("\nhotel name %s",P->name);
        printf("\nprofit  %lf",P->profit);
    }
    return (P);
}

HOTEL  highest_profit(HOTEL *P, int N)
{
    int i,max=P->profit;

    for(i=0;i<N;i++)
    {
        if(P->profit < (P+1)->profit)
        {
            max = (P+1)->profit;
        }
    }
}


int main()
{
    int N;
    HOTEL p[size],*high_p;
    printf("\nenter the number of hotels  ");
    scanf("%d",&N);

    read_info(&p,N);
    display_info(&p,N);
    high_p = highest_profit(&p,N);





}
