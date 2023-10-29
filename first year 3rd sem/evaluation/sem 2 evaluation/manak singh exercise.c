/*
manak singh exercise


*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct daily_exe
{
    char name[20];
    int rep;
    struct daily_exe* next;
};


typedef struct daily_exe* NODE;

NODE getnode();
NODE read(NODE);
NODE read_list(NODE);
NODE insert_end(NODE,NODE);
void display_all(NODE);


NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct daily_exe));

    if(temp==NULL)
    {
        printf("\ninsufficient information\n");
        return;
    }

    temp=temp->next;
    temp->next=NULL;

    return temp;
}

NODE read(NODE temp)
{
    temp=getnode();
    printf("\nenter details:\n");
    printf("Name of exercise:\t");
    scanf("%s",temp->name);
    printf("number of reps\t");
    scanf("%d",&temp->rep);
    return (temp);
}



NODE read_list(NODE head)
{
    int i;
    NODE newnode;

    printf("\nhead information");
     head=read(head);

     for(i=0;i<4;i++)
     {
         newnode=read(newnode);
         head=insert_end(head,newnode);
     }
     return head;

}

NODE insert_end(NODE head, NODE newnode)
{
    NODE temp;
    temp = head;

    do
    {
        temp=temp->next;
    }while(temp->next != NULL);

    temp->next=newnode;
    newnode->next=NULL;

    return(head);
}


void display_all(NODE head)
{
    NODE temp=head;
    int i;

    for(i=0;i<5;i++)
    {
        printf("\n%s\t%d\t",temp->name,temp->rep);
        temp=temp->next;
    }
    return;
}


int main()
{
    int i;
    NODE head;

    head=read_list(head);

    display_all(head);
}


