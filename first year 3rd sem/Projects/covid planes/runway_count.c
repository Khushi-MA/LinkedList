#include "header.h"

int runway(NODE head, char Cname[30])
{
    int count=0;
    NODE temp=head;

    while(temp!=NULL)
    {
        if(strcmp(Cname,temp->dest)==0)
        {
            count++;
        }
        temp=temp->next;
    }
    return count;
}
