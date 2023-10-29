#include "DLL circular menu.h"

void displayall(NODE head)
{
    if(head==NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    NODE temp=head;
    do
    {
        printf("\n%d %s",temp->data.id,temp->data.name);
        temp=temp->next;
    }while(temp!=head);
    printf("\n\n");
    return;
}

void displaybyposition(NODE head, int pos)
{
    NODE temp=head;
    int i;
    for(i=1;i<=pos-1;i++,temp=temp->next);
    displayone(temp);
    return;
}

void displayone(NODE temp)
{
    printf("\nid number: %d\nname:%s\n",temp->data.id,temp->data.name);
    return;
}

void displayreverse(NODE head)
{
    if(head==NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    NODE temp=head->prev;
    do
    {
        printf("\n%d %s",temp->data.id,temp->data.name);
        temp=temp->prev;
    }while(temp!=head->prev);
    printf("\n\n");
    return;
}
