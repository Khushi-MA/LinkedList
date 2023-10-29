
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

struct kalia
{
    int money;
    int hno;
    char name[30];
    struct kalia* next;
};

typedef struct kalia* NODE;

NODE getnode();
NODE read_list(NODE);
NODE read_nodes(NODE,int);
NODE insert_end(NODE,NODE );
void display_one(NODE);
void display_all(NODE);
int kalia_count(NODE);
