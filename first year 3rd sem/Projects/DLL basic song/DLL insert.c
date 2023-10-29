#include "DLL menu.h"

NODE addatthebegin(NODE head, SONG s)
{
    NODE p;
    p=getnode();
    p->prev=p->next=NULL;
    p->data=s;

    if(head!=NULL)
    {
        p->prev=NULL;
        head->prev=p;
        p->next=head;
    }

    head=p;
    return head;
}

NODE addattheend(NODE head, SONG s)
{
    NODE p;
    p=getnode();
    p->prev=p->next=NULL;
    p->data=s;
    if(head==NULL)
    {
        head=p;
        head->next=head->prev=NULL;
        return head;
    }
    NODE temp;
    for(temp=head;temp->next!=NULL;temp=temp->next);
    temp->next=p;
    p->prev=temp;
    return head;
}

NODE insertposition (NODE head, SONG s, int pos)
{
    NODE p,temp;
    p=getnode();
    p->prev=p->next=NULL;
    p->data=s;
    int i;
    for(temp=head,i=1;i<pos-1;temp=temp->next);
    p->next=temp->next;
    (temp->next)->prev=p;
    temp->next=p;
    p->prev=temp;
    return head;
}

