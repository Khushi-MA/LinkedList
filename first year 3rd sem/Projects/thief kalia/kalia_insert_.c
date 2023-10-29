#include "kalia_header.h"

NODE insert_end(NODE head,NODE newnode)
{
    NODE temp;

    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
        return (head);
    }

    temp=head;
    do
    {
        temp=temp->next;
    }while(temp->next!=head);

    temp->next=newnode;
    newnode->next=NULL;

    return head;
}

