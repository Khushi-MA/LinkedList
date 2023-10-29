#include "war_header.h"

NODE insert_end(NODE head, NODE newnode)
{
     NODE temp=head;

     if(head==NULL)
     {
         printf("\n\nif head==NULL in insert end fun\n\n");
         head=newnode;
         head->next=NULL;
         return (head);
     }

     else
     {
         while(temp->next!=NULL)
         {
             temp=temp->next;
         }
         temp->next=newnode;
         newnode->next=NULL;
     }

     return(head);
}
