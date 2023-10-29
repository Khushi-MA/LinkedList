#include "course3_header.h"

/*Shortest distance from one place to another (By road)*/


void read_road_dist(int roadway[11][11])
{
    int i,j;

    printf("Enter the distance\n");
    for(i=1;i<11;i++)
    {
        for(j=1;j<11;j++)
            scanf("%d",&roadway[i][j]);
    }
    return;
}

void print_2d_array(int a[11][11])
{
    int i, j;

    for(i=1;i<11;i++)
    {
        printf("\n");
        for(j=1;j<11;j++)
            printf("%d\t",a[i][j]);
    }
    return;
}

