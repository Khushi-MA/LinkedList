#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#define nV 11  // defining the number of vertices (currently)
#define INF 9999  // INF as in INFINITY

struct hotel {
    char name[50];
    float ratings;
    char addr[20];
    int price;
};

struct node
{
    char* name;
};

void near_hotels(char d[]);
void read_city_names(struct hotel hot_details[11]);
void distance_source_dest(int, int);
void read_road_dist(int roadway[11][11]);
void print_2d_array(int a[11][11]);

struct node cityy[14];
struct hotel hot_details[100];
int roadway[11][11];
int FWroad[11][11];


/*
int road[50][50] = {{247,	0,	433	,449	,532	,0	,0	,0	,0	,0},
{680	,433	,0	,837	,970	,1208	,1043	,0	,0	,0},
{297	,449	,837	,0	,450	,690	,5,29	,0	,0	,0},
{0	,532	,970	,450	,0,	,239	,261	,55,3	,308	,687},
0	0	1208	690	239	0	640	335	239	618
0	0	1043	529	261	640	0	730	538	916
0	0	0	0	553	335	730	0	572	951
0	0	0	0	308	239	538	572	0	396
0	0	0	0	687	618	916	951	396	0
}


*/








