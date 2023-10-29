#include "header.h"

void display_one(NODE temp)
{
    printf("\n%d\t%s\t%d\t",temp->id,temp->dest,temp->seats);
}


void display_all(NODE temp)
{
    printf("\nplaneID\tdestination\tseats\t");
    while (temp!=NULL)
    {
        printf("\n%d\t %s\t\t%d\t",temp->id,temp->dest,temp->seats);
        temp=temp->next;
    }

    return;
}

void run2_display(NODE head, char Cname[30])
{
    NODE temp=head;

    while(temp!=NULL)
    {
        if (strcmp(Cname,temp->dest)!=0)
        {
            display_one(temp);
        }
        temp=temp->next;
    }
    return;
}
