#include<stdio.h>
#include<stdlib.h>
struct candidate
{

int data;
struct candidate *next;
};


/* A user-defined data type called  NODE  */

typedef struct candidate *NODE;

NODE getnode();
NODE read();
void display(NODE head,FILE**f2); 
NODE insert_end(NODE head);

// Function to allocate memory dynamically using malloc() function
NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct candidate));
    if(temp==NULL)
        return NULL;
    else
        temp->next=NULL;

    return temp;

}
//function to read details of the candidate
NODE read()
{
    NODE temp;
    temp=getnode();
    printf("\nENTER DETAILS\n");
    scanf("%d",&temp->data);
    //fprintf(f1,"%d\n",temp->data);

    return temp;
}
// to display(traverse) all elements of the list
void display(NODE head,FILE**f2)
{
     NODE cur;
     cur=head;
     if(head==NULL)
           printf("EMPTY LIST");
     else
    {
        while(cur!=NULL)
        {
             fprintf(*f2,"%d\n",cur->data);
             cur=cur->next;
        }
    }
}

// function to insert a node at the end of the list
NODE insert_end(NODE head)
{
  NODE newnode,cur=head;
  newnode=read();
  if(head==NULL)
      head=newnode;
  else{
      while(cur->next!=NULL)
          cur=cur->next;
      cur->next=newnode;
      newnode->next = NULL;

  }
    return head;
}

//function to search a node based on the name of the candidate
/*int search(NODE head, char sname[20])
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

}*/
int main()
{
 NODE head=NULL;
 int ch;

 //FILE*f1=fopen("prati.txt","w");
 FILE*f2=fopen("laxmi.txt","w");
 while(1)
 {
   printf("\n1.Insert_end \n2.Display \n3.search \n 4. Exit\n");
   scanf("%d",&ch);
   switch(ch){

            case 1: head =insert_end(head);
                    break;

            case 2:display(head,&f2);
                    break;

            default : exit(0);
            }
 }
}
