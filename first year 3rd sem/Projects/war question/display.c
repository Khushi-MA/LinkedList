#include "war_header.h"

void display_all(NODE head)
{
    NODE temp=head;
    printf("\nname\tgender\tage\t");
    while(temp!=NULL)
    {
        printf("\n%s\t%s\t%d\t",temp->name,temp->gender,temp->age);
        temp=temp->next;
    }
    return;
}


void display_one(NODE temp)
{
    printf("\nname\tgender\tage\t");
    printf("\n%s\t%s\t%d\t",temp->name,temp->gender,temp->age);
    return;
}
