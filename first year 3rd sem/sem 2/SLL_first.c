/*Program to demonstrate basic SLL operations*/
#include<stdio.h>
#include<stdlib.h>
struct candidate
{
	char name[25];
	int rank;
  int age;
	//char address[100];
	struct candidate *next;
};


/* A user-defined data type called �NODE� */

typedef struct candidate *NODE;
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
    scanf("%s%d%d",temp->name,&temp->rank,&temp->age);
    return temp;
}
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
// function to count the number of nodes in the list
int count(NODE head)
{   NODE temp=head;
     if (head == NULL)
        return 0;
    int c=0;
    while(temp !=NULL)
    {
        c++;
        temp = temp->next;

    }
    return c;
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
int main(){
 NODE head=NULL;
 int ch,c;
 char NAME[30];
 while(1)
 {
   printf("\n1.Insert front \n2.Insert_end \n3.Display \n4.insert position\n 5.count\n 6.search \n 7. Exit\n");
   scanf("%d",&ch);
   switch(ch){
            case 1: head=insert_front(head);
                    break;
            case 2: head =insert_end(head);
                    break;

            case 3:display(head);
                    break;
            case 4 : printf("Enter the name after which you want to insert\n");
                     scanf("%s",NAME);
                     head=insert_pos(head,NAME);
                     break;
            case 5:
                    c=count(head);
                     printf("The no. of nodes  = %d",c);
                     break;
            case 6: printf("ENter name to search \n");
            scanf("%s",NAME);
                     c= search(head , NAME);
                     if(c==1)
                        printf("Search is successful \n");
                      else
                         printf("Search Not successfull\n");
                     break;
            default : exit(0);
            }
 }
}
/*int main()
{
   NODE head;
   head = read();
   display(head);


}*/


