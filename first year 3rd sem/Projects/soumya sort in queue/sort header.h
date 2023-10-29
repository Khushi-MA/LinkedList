#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define qsize 1000

struct mainq
{
    char name[100],gender;
    int age;
};
typedef struct mainq DATA;

struct queue
{
    DATA data[qsize];
    int front,rear;
};
typedef struct queue QUEUE ;

void createq(QUEUE*);
void readmainqueue(QUEUE*, int);
void enqueue(QUEUE* , DATA);
DATA dequeue(QUEUE*);
void sortmainqueue(QUEUE*, QUEUE*, QUEUE*, QUEUE*, QUEUE *);
void display(QUEUE);
int emptyq(QUEUE);
