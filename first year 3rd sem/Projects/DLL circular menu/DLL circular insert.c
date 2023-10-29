#include "DLL circular menu.h"

NODE insertbegin(NODE head, NODE newnode)
{
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    head=insertend(head,newnode);
    head=head->prev;
    return head;
}

NODE insertend(NODE head,NODE newnode)
{
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    newnode->prev=head->prev;
    (head->prev)->next=newnode;
    newnode->next=head;
    head->prev=newnode;
    /*
    not this

    newnode->prev=head->prev;
    (head->prev)->next=newnode;
    head->prev=newnode;
    newnode->next=head;
    */
    return head;
}

NODE insertbyposition(NODE head, NODE newnode, int pos)
{
    NODE temp;
    if(pos==1)
    {
        head=insertbegin(head,newnode);
        return head;
    }
    int i;
    for(temp=head,i=1;i<pos-1;i++,temp=temp->next);
    newnode->next=temp->next;
    (temp->next)->prev=newnode;
    newnode->prev=temp;
    temp->next=newnode;
    return head;
}
