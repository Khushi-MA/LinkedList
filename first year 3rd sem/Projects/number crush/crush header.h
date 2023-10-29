#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define stacksize 1000

typedef struct stack
{
    int num[stacksize],top;
}STK;


int isempty(STK);
int isfull(STK);
void initstack(STK*);
void push(STK*,int);
int pop(STK*);
void display(STK ,int );
int peek(STK );
