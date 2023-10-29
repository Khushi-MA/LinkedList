#include "kalia_header.h"

NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct kalia));

    temp->next=temp;
    return (temp);
}


NODE read_list(NODE temp)
{
    temp=getnode();

    printf("\nenter the amount in the house\t");
    scanf("%d",&temp->money);
    printf("enter the house number\t");
    scanf("%d",&temp->hno);
    printf("enter the house owner's name");
    scanf("%s",temp->name);

    return temp;
}


NODE read_nodes(NODE head,int n)
{
    NODE newnode;
    int i;
    printf("\n\nnumber of houses\n)");
    head=read_list(head);

    for(i=0;i<n-1;i++)
    {
        newnode=read_list(newnode);
        head=insert_end(head,newnode);
    }
    return (head);
}
