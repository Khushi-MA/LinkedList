#include "header.h"

void insert_switch(NODE head)
{
    int i;
    printf("\nenter how the insertion should happen");
    printf("\n1.enter according to position");
}


NODE insert_end(NODE head, NODE newnode)
{
    NODE temp;
    temp = head;

    if(head==NULL)
    {
         newnode->next=head;
         head = newnode;
    }

    else
    {
        do
        {
            temp=temp->next;
        }while(temp->next != head);
        temp->next=newnode;
        newnode->next=head;
    }
    return(head);
}

/*

NODE insert_pos(NODE head, int pos, NODE newnode)
{
    NODE temp,prev = NULL;
    int i,n;

    n=count_node(head);

    if(head==NULL)
    {
        head = newnode;
        return head;
    }

    if(pos==n+1)
    {
        head = insert_end(head,newnode);
        return head;
    }

    for(i=0;i<pos;i++)
    {
        prev = temp;
        temp=temp->next;
    }
    prev->next=newnode;
    newnode->next = temp;
    }

    return head;

}
*/
