#include "header.h"

NODE delete_front(NODE head)
{
     int i;
     NODE temp,target;
     temp=target=head;

     do
        {
            temp=temp->next;
        }while(temp->next!=head);

     head=head->next;
     temp->next=head;
     free(target);

     return head;
}


NODE delete_end(NODE head)
{
    int i;
    NODE temp,target,prev;
    temp=target=head;
    prev=NULL;
    display_one(target);

    do
    {
        printf("\n\ntarget traversing\n");
        prev=target;
        target=target->next;
        display_one(target);
    }while(target->next!=head);

    printf("\n\ntarget after loop\n");
    display_one(target);

    prev->next=head;
    free(target);

    return head;
}


NODE delete_pos(NODE head, int pos)
{
    int i,total;
    total=count_node(head);

     if(head==NULL)
     {
         printf("\nentered first loop");
         printf("\n\nempty list");
         return NULL;
     }

     else if(head->next==head)
     {
         printf("\nthe head will be deleted...");
         free(head);
         return NULL;
     }

     else if(pos==1)
     {
         head=delete_front(head);
     }

     else if(pos==total)
     {
         head=delete_end(head);
     }

     else
     {
         printf("\nlet's see");
     }

    return head;
}


NODE delete_area(NODE head, char idkarea[30])
{
    int i=1;
    NODE temp;
    temp=head;
    do
    {
        if(strcmp(idkarea,temp->area)==0)
        {
            printf("\nwe got to delete\n");
        }
        temp=temp->next;
    }while(temp!=head);
    return head;
}

NODE delete_house(NODE head,int Uhouse)
{
    int i=1;
    NODE temp;

    do
    {
        if(Uhouse==temp->hno)
        {
            printf("'i' is %d",i);
            printf("\nnpde being deleted:\n");
            display_one(temp);
            delete_pos(head,i);
        }
        i++;
        temp=temp->next;
    }while(temp!=head);
    return head;
}


NODE delete_switch(NODE head)
{
    int i,choice,Uhouse,pos;
    char idkarea[30];

    printf("\n\nhow do you want to delete?");
    printf("\n1.delete according to area (search and delete multiple)\n2.delete according to house number\n3.delete according to node position");
    printf("\nenter choice:\t");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:{printf("\n\nenter the area\n");
                scanf("%s",idkarea);
                head=delete_area(head,idkarea);
                break;}

        case 2:{printf("\nenter house number");
                scanf("%d",&Uhouse);
                delete_house(head,Uhouse);
                display_all(head);
                break;}

        case 3:{printf("\nenter the position of the node");
                scanf("%d",&pos);
                delete_pos(head,pos);
                display_all(head);
                break;}

    }

}


