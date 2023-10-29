#include "course3_header.h"

// near_hotels function reads the hotel information from existing file of hotel.txt
// hotel.txt holds the information of hotels like- their name, city they are in, their ratings and 24 hour pricing
void near_hotels(char d[])
{
    FILE*fp1;
    fp1=fopen("hotel.txt","r");
    printf("\nIn-city Hotel/lodge details\n");
    printf("\n**********in near_hotels\n%s %s\n", cityy[2].name, cityy[3].name);
    printf("Hotel\t\tRating\t\tPrice(24hr)\n");
    for(int i=1;i<=30;i++)
    {
        fscanf(fp1,"%s %f %s %d", hot_details[i].name, &hot_details[i].ratings, hot_details[i].addr, &hot_details[i].price);

        if(strcmp(hot_details[i].addr,d)==0)
             printf("%-10s\t%-12.1f\t%10d\n", hot_details[i].name, hot_details[i].ratings, hot_details[i].price);
    }
    fclose(fp1);
    return;
}

void read_city_names(struct hotel hot_details[11])
{
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
    cityy[11].name = "Amritsar";
    cityy[12].name = "Agra";
    cityy[13].name = "Jaipur";
    cityy[14].name = "Udaipur";

    return;
}

