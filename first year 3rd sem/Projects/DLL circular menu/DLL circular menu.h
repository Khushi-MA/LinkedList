/*
code by KHUSHI M APPANNAVAR
This is a menu code for Doubly Circular Linked List.
This code is of a structure for person's ID number (integer) and name (string)
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct person
{
    int id;
    char name[100];
}PERSON;

struct node
{
    PERSON data;
    struct node *next,*prev;
};
typedef struct node * NODE;

NODE getnode();
int listempty(NODE );
NODE readnode(NODE );
NODE insertbegin(NODE , NODE );
NODE insertend(NODE ,NODE );
NODE insertbyposition(NODE , NODE , int );
int countnodes(NODE );
void displayall(NODE);
void displayreverse(NODE);
void displayone(NODE );
void displaybyposition(NODE , int );
NODE deletebegin(NODE );
NODE deleteend(NODE );
NODE deletebyposition(NODE , int );
NODE deletebyname(NODE , char[]);
