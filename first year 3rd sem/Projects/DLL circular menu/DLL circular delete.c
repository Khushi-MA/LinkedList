#include "DLL circular menu.h"

NODE deletebegin(NODE head)
{
    NODE temp=head;
    (head->prev)->next=head->next;
    (head->next)->prev=head->prev;
    head=head->next;

    printf("\nnode being deleted is\n");
    displayone(temp);
    free(temp);
    return head;
}

NODE deleteend(NODE head)
{
   NODE temp;
    temp=head->prev;
    head->prev=temp->prev;
    (temp->prev)->next=head;

    printf("\nnode being deleted is\n");
    displayone(temp);
    free(temp);
    return head;
}

NODE deletebyposition(NODE head, int pos)
{
    NODE temp;
    if(pos==1)
    {
        head=deletebegin(head);
        return head;
    }
    int i;
    for(temp=head,i=1;i<=pos-1;i++,temp=temp->next);
    (temp->prev)->next=temp->next;
    (temp->next)->prev=temp->prev;
    printf("\nnode being deleted is\n");
    displayone(temp);
    free(temp);
    return head;
}

NODE deletebyname(NODE head, char fname[100])
{
    NODE temp=head;
    do
    {
        if(strcmp(temp->data.name,fname)==0)
        {
            if(temp==head)
            {
                printf("\nnode being deleted is\n");
                displayone(head);
                free(head);
                return NULL;
            }

            (temp->prev)->next=temp->next;
            (temp->next)->prev=temp->prev;
            printf("\nnode being deleted is\n");
            displayone(temp);
            free(temp);
            return head;
         }
        temp=temp->next;
    }while(temp!=head);
    printf("\nName doesn't exist\n");
    return head;
}
