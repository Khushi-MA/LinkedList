#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct soldier_info
{
    char name[30];
    char gender[10];
    int age;
    struct soldier_info* next;
};


typedef struct soldier_info* NODE;


NODE read_nodes(NODE, int );
NODE getnode();
NODE read_list(NODE);
NODE insert_end(NODE, NODE);
void display_all(NODE);
void display_one(NODE);
NODE insertbeforemale(NODE ,NODE );


