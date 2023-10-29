#include "DLL circular menu.h"

NODE readnode(NODE temp)
{
    temp=getnode();
    printf("\nenter id number\t");
    scanf("%d",&temp->data.id);
    printf("enter name:\t");
    scanf("%s",temp->data.name);
    return temp;
}

NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    temp->next=temp->prev=temp;
    return temp;
}

int listempty(NODE head)
{
    if(head==NULL)
        return 1;

    else
        return 0;
}

