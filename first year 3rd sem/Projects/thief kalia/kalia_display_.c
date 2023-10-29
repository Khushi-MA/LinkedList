#include "kalia_header.h"

void display_one(NODE temp)
{
    printf("\n%d\t%d\t%s\t",temp->money,temp->hno,temp->name);
    return;
}

void display_all(NODE head)
{
    NODE temp=head;
    printf("\nmoney\tH.No\tname\t");

    do
    {
        printf("\n%d\t%d\t%s\t",temp->money,temp->hno,temp->name);
        temp=temp->next;
    }while(temp!=NULL);

    return;
}

