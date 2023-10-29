#include "SLL menu header.h"

// to display(traverse) all elements of the list
void display(NODE head)
{
     NODE cur;
     cur=head;
     if(head==NULL)
           printf("EMPTY LIST");
     else
    {
        while(cur!=NULL)
        {
             printf("%s\t%d\t%d\n",cur->name,cur->rank,cur->age);
             cur=cur->next;
        }
    }
}

//function to search a node based on the name of the candidate
int search(NODE head, char sname[20])
{
  NODE temp = head;;
  if(head  == NULL)
    return 0;
  while(temp != NULL)
  {
      if(strcmp(temp->name,sname)==0 )
         {
             printf("%s\t %d \t %d\n",temp->name,temp->rank, temp->age);
             return 1;

         }
         temp=temp->next;
  }
  return 0;
}
