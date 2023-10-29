#include "kalia_header.h"

int kalia_count(NODE head)
{
    NODE temp=head;

    int count1=0, count2=0;

    do
    {
        count1=count1+temp->money;
        temp=temp->next->next;
    }while(temp!=NULL);

    temp=head->next;

    do
    {
        count2=count2+temp->money;
        temp=temp->next->next;
    }while(temp!=NULL);

    if(count1>count2)
    {
        return count1;
    }

    else
    {
        return count2;

    }
}
