#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct //date
{
    int d, m, y;
}DATE;

typedef struct //song
{
    char name[100], singer[100];
    DATE date;
}SONG;

struct node
{
    SONG data;
    struct node *next, *prev;
};

typedef struct node*  NODE;

void readsong(SONG*);
NODE getnode();
NODE addatthebegin(NODE , SONG );
void displayall(NODE );
void displayonedown(NODE );
void displayoneline(NODE);
void displayallreverse(NODE );
NODE deleteatthebegin(NODE );
NODE deletesong(NODE,char[]);
NODE deleteattheend(NODE );
NODE addattheend(NODE,SONG);
int countsinger (NODE ,char []);
int countsongs(NODE );
NODE insertposition (NODE , SONG , int );
