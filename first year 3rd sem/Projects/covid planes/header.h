#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#include "plane_structure.c"


NODE read_nodes(NODE,int);
NODE read_struct(NODE);
NODE getnode();
NODE insert_end(NODE,NODE);
void display_one(NODE);
void display_all(NODE);
int runway(NODE,char[]);
void run2_display(NODE,char[]);
