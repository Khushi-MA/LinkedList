#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct daily_exe
{
    char name[20];
    int rep;
    struct daily_exe* next;
};


typedef struct daily_exe* NODE;


NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct daily_exe));

    temp->next=NULL;

    return temp;
}

NODE read(NODE temp)
{
    temp=getnode();
    printf("\nenter the exercise name\n");
    scanf("%s",temp->name);
    printf("\nenter the number of reps\n");


}


int main()
{
    int i;
}
