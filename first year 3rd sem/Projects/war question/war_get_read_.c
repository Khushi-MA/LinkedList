#include "war_header.h"

NODE read_list(NODE temp)
{
    temp=getnode();

    printf("\nenter the name of the soldier\t");
    scanf("%s",temp->name);
    printf("enter gender of the soldier\t");
    scanf("%s",temp->gender);
    printf("enter the age of the soldier\t");
    scanf("%d",&temp->age);

    return temp;
}

NODE read_nodes(NODE head, int n)
{
    NODE newnode;
    int i;
    printf("\nenter the %d male soldiers information\n",n);
    printf("\n(head info)");

    head=read_list(head);

    for(i=0;i<n-1;i++)
    {
        newnode=read_list(newnode);
        head=insert_end(head,newnode);
    }

    return(head);
}

NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct soldier_info));

    temp->next!=NULL;

    return temp;
}


