/*Program to demonstrate basic SLL operations*/
#include "SLL menu header.h"
int main(){
 NODE head=NULL;
 int ch,c;
 char NAME[30];
 while(1)
 {
   printf("\n1.Insert front \n2.Insert end \n3.Display \n4.insert position \n5.count \n6.search \n7.Exit \n");
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




