#include "course_header.h"

int main()
{
    int ;
    char s[50],d[50];
    int n=100, i, j;
    struct node cityy[n];
    //storing all the destina
    cityy[1].name = "Pune";
    cityy[2].name = "Mumbai";
    cityy[3].name = "Shimla";
    cityy[4].name = "Maldives";
    cityy[5].name = "Delhi";
    cityy[6].name = "Dubai";
    cityy[7].name = "Varanasi";
    cityy[8].name = "Bengluru";
    cityy[9].name = "Manali";
    cityy[10].name = "Ladakh";
    printf("\nAvailable destinations to choose from:");
    for(i=1;i<11;i++)
    {
        printf("\n%d. %s",i, cityy[i].name);
    }

    int choice, source_city, dest_city, q, p, j, k;

    printf("\n\nWhat do you want to know?");
    printf("\n1. Hotels in a city\n2. \n3. \n4. \n5. \nEnter choice:   ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("\n\nEnter city:  ");
                scanf("%s",d);
                near_hotels(d);

        case 2: printf("Enter source:  ");
                scanf("%s",s);
                printf("Enter destination:  ");
                scanf("%s",d);
                for(j=1, flag=0 ; j<=10 ; j++)
                {
                    if(strcmp(s,cityy[j].name)==0)
                    {
                        source_city=j;
                        break;
                    }
                }
                for(k=1 ;k<=10 ; k++)
                {
                    if(strcmp(d,cityy[k].name)==0)
                         dest_city=k;
                }

        default: printf("choice unavailable :)");
    }
    printf("\n");
    return 0;
}

