#include "header.h"

void display_one(NODE temp) //only one
{
    printf("\nDetails:");
    printf("\nname\t\t%s",temp->name);
    printf("\nhouse number\t\t%d",temp->hno);
    printf("\narea\t\t%s",temp->area);
    printf("\nmobile number\t\t%lf",temp->mobile);
    return;
}

void display_all(NODE temp)
{
    NODE head;
    head=temp;
    if(temp==NULL)
    {
        printf("\nempty list");
        return;
    }

    do
    {
        printf("\nname\t\t%s",temp->name);
        printf("\nhouse number\t%d",temp->hno);
        printf("\narea\t\t%s",temp->area);
        printf("\nmobile number\t%lf",temp->mobile);
        temp=temp->next;
    }while(temp != head);

    return;
}
