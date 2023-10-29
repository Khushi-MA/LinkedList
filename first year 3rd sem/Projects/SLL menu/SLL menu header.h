/*Program to demonstrate basic SLL operations*/
#include<stdio.h>
#include<stdlib.h>
struct candidate
{
	char name[25];
	int rank;
    int age;
	//char address[100];
	struct candidate *next;
};


/* A user-defined data type called “NODE” */

typedef struct candidate *NODE;

NODE read();
NODE getnode();
int count(NODE );
NODE insert_front(NODE );
NODE insert_end(NODE );
NODE insert_pos(NODE , char[]);
void display(NODE );
int search(NODE , char[]);



