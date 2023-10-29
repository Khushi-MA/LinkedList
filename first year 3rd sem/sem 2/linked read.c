#include<stdio.h>
#include<stdlib.h>

struct planet
{
    char name[20];
    float diam;
    int moons;
    struct planet *next;
};

typedef struct planet *NODE;

NODE getnode()
{
    NODE temp;
    temp = (NODE) malloc(sizeof(struct planet));
    if (temp==NULL)
    {
       printf("\ninsufficient space");
       return NULL;
    }

    else
        temp->next=NULL;

     return temp;
}

NODE read(NODE temp)
{
    temp=getnode();
    printf("\nenter details:\n");
    printf("Name of the planet:\t");
    scanf("%s",temp->name);
    printf("diameter\t");
    scanf("%f",&temp->diam);
    printf("moons\t");
    scanf("%d",&temp->moons);
    return temp;
}

void display(NODE temp)
{
    printf("\nDetails;");
    printf("\nname\t\t%s",temp->name);
    printf("\ndiameter\t%f",temp->diam);
    printf("\nmoons\t\t%d",temp->moons);
}

NODE insert_end(NODE head, NODE newnode)
{
    NODE temp;
    temp = head;

    if(head==NULL)
    {
         head = newnode;
    }

    else
    {
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return(head);
}

int main()
{
     NODE head,newnode;
     head=getnode();
     head=read(head);
     display(head);
     int i;

     int n;
     printf("\nenter the number of nodes to insert at the end");
     scanf("%d",&n);

     for(i=1;i<n;i++)
     {
         newnode=getnode();
         newnode=read(newnode);
         head=insert_end(head,newnode);
     }

     display(head);


     printf("\n\n");
}
