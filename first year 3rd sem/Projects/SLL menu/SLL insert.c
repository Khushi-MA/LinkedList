#include "SLL menu header.h"

// function to insert a node in the beginning of the list
NODE insert_front(NODE head)
{
  NODE temp;
  temp=read();

  if(head==NULL)
    head = temp;
  else
  {

    temp->next=head;
    head=temp;
  }
  return head;

}
// function to insert a node at the end of the list
NODE insert_end(NODE head)
{
NODE temp,cur=head;
temp=read();
if(head==NULL)
    head=temp;
else{
     while(cur->next!=NULL)
        cur=cur->next;
    cur->next=temp;
    temp->next = NULL;

}
  return head;

}
/// function to insert a node at a specified position of the list(based on the name)
NODE insert_pos(NODE head, char NAME[30])
{
 NODE cur=head, temp, prev=NULL;
 temp=read();
 if(head==NULL)
   head = temp;
 else
 {
   do{
       if(strcmp(cur->name,NAME)==0)
       {
          temp->next= cur->next;
          cur->next = temp;
           return head;
       }
         cur=cur->next;
     }while(cur!=NULL);
 }
   return head;
}
