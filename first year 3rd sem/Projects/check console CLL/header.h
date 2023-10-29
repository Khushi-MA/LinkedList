#include<stdio.h>
#include<math.h>
#include<string.h>
#include "curr_structure.c"

NODE read_all();
NODE read(NODE);
NODE getnode();
void display_one(NODE);
void display_all(NODE);
int count_node(NODE);
void insert_switch(NODE);
NODE insert_end(NODE, NODE);
NODE insert_pos(NODE, int, NODE );
NODE delete_pos(NODE, int);
NODE delete_front(NODE);
NODE delete_end(NODE);
NODE delete_area(NODE, char[]);
NODE delete_house(NODE,int);
NODE delete_switch(NODE);



