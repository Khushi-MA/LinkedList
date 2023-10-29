#include "war_header.h"

NODE insertbeforemale(NODE head,NODE female)
{
    NODE temp=head,prev=NULL;
    int pos=0;

    if(head->age==female->age)
    {
        female->next=head;
        head=female;
        return 1;
    }

    else
    {
        while(temp!=NULL && temp->age!=female->age )
        {
            prev=temp;
            temp=temp->next;
            pos++;
        }

        if(temp==NULL)
        {
            printf("\nfemale soldier age doesn't match\n");
            return 0;
        }

        prev->next=female;
        female->next=temp;
    }

    return (pos+1);
}
