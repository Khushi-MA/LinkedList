#include<stdio.h>
#include<math.h>

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
    if (temp== NULL)
    {
       printf("\ninsufficient space");
       return NULL;
    }

    else
        temp->next=NULL;

     return temp;
}
function read_all
{
    NODE read_all(NODE head, NODE newnode)
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

void display_all(NODE temp)
{
    while(temp != NULL)
    {
        printf("\nname\t\t%s",temp->name);
        printf("\ndiameter\t%f",temp->diam);
        printf("\nmoons\t\t%d",temp->moons);
        temp=temp->next;
    }
}


/*
int main()
{
NODE head,newnode;
     head=getnode();
     head=read(head);
     display(head);
}
*/

int main()
{
     NODE head,newnode;

      printf("\nenter the number of nodes in the list");
     scanf("%d",&n);

     head=getnode();
     head=read(head);

     head=readlist(n);

     display_all(head);

     int i,n;



     for(i=0;i<n;i++)
     {
         newnode=getnode();
         newnode=read(newnode);
         head=insert_end(head,newnode);
     }

     display_all(head);

     printf("\n\n");
}


