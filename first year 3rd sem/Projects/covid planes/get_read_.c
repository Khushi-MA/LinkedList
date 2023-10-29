#include "header.h"

NODE read_nodes(NODE head,int n)
{
    NODE newnode;
    int i;

    printf("\n(head information)");
    head=read_struct(head);

    for(i=0;i<(n-1);i++)
    {
        newnode=read_struct(newnode);
        head=insert_end(head,newnode);
    }

    return (head);
}


NODE read_struct(NODE temp)
{
    temp=getnode();

    printf("\nenter plane details\t");

    printf("\nenter plane id\t");
    scanf("%d",&temp->id);

    printf("enter plane destination\t");
    scanf("%s",temp->dest);

    printf("enter number of seats\t");
    scanf("%d",&temp->seats);

    if(temp->id<1000 || temp->id>5000 || temp->seats<0 || temp->seats>1000)
    {
        printf("Invalid input");
        return;
    }

    return (temp);
}


NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct plane_info));
    temp->next= NULL;

     return (temp);
}

