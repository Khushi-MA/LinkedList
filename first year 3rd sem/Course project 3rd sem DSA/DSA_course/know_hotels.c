#include "course_header.h"

void near_hotels(char d[])
{
    FILE*fp1;
    struct hotel p1[100];
    fp1=fopen("hotel.txt","r");
    for(int i=1;i<=30;i++)
    {
        fscanf(fp1,"%s %f %s %d",p1[i].name,&p1[i].ratings,p1[i].addr,&p1[i].price);
    }
    printf("\nIn-city Hotel/lodge details\n");
    for(int i=1;i<=30;i++)
    {
        if(strcmp(p1[i].addr,d)==0)
             printf("%-10s\t%-12.1f\t%8s\t%10d\n",p1[i].name,p1[i].ratings,p1[i].addr,p1[i].price);
    }
    fclose(fp1);
}
