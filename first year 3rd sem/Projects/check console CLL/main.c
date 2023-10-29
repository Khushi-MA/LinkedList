#include "header.h"

int main()
{
     NODE head,newnode;
     int i,n,total,choice;

     // program information
     printf("this program has the following information of the letters\nname of the person\nhouse number\narea\nphone number\n");

     printf("\nlist of choices to consider from\n1.read/enter the whole list");
     printf("\n2.count the nodes in the list\n3.display all nodes");
     printf("\n4.insert\n5.delete");
     printf("\n100.EXIT\n");

     do
     {
         int choice;
         printf("\nenter your choice to create/modify the circular linked list:");
         scanf("%d",&choice);

     switch(choice)
     {
     case 1:
        {
            head=read_all();
            break;
        }

     case 2:
        {
            total=count_node(head);
            printf("\n\ntotal nodes in the circle is %d",total);
            break;
        }

     case 3:
        {
           display_all(head);
           break;
        }

     case 4:
        {
            insert_switch(head);
            break;
        }

     case 5:
        {
            delete_switch(head);
            break;
        }

        case 100: printf("\nyou have exit the loop. THANKYOU!!!");

     default:
        {
            printf("\n\nchoice not found!!!(bro...read carefully.)");
            break;
        }
     }

     }while(choice!=100);


}



/*
int main()
{
     NODE head,newnode;
     int i,n,total,pos;

     printf("this program has the following information of the letters\nname of the person\nhouse number\narea\nphone number\n");

     printf("\nenter your choice to create/modify the circular linked list:");


            head=read_all();
            total=count_node(head);
            printf("\n\ntotal nodes in the circle is %d",total);

           display_all(head);

           printf("\nenter the position of node you want to delete:\t");
           scanf("%d",&pos);

           if(pos>=1 && pos<=n)
           head=delete_pos(head,pos);

           else
            printf("\nINVALID POSITION");

           display_all(head);
}
  for inserting

int main()
{
     NODE head,newnode;
     int i,n,total,pos;

     printf("this program has the following information of the letters\nname of the person\nhouse number\narea\nphone number\n");

     printf("\nenter your choice to create/modify the circular linked list:");


            head=read_all();
            total=count_node(head);
            printf("\n\ntotal nodes in the circle is %d",total);

           display_all(head);

           printf("\nenter the node details you want to insert");
           newnode=read(newnode);
           printf("\nenter the position where you want to insert another node:\t");
           scanf("%d",pos);

           if(pos>=1 && pos <=n+1)
           head=insert_pos(head,pos,newnode);

           else
            printf("\nINVALID POSITION");

           display_all(head);


}

*/

/// at the end(i.e.before head)\n6.insert in the beginning\n7.insert at specific position\n8.insert after specific name
/// 9.delete specific position\n10.delete multiple by reading area\n



