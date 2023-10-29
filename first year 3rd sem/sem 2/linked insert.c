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

void display(NODE temp) //only one
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

int count_node(NODE head)
{
    int i;
    NODE temp;
    temp=head;
    if(temp == NULL)
        return 0;

    for(i=0;temp!=NULL;i++,temp=temp->next);
    return i;
}

NODE insert_new_at_pos (NODE head, NODE newnode, int pos)
{
    int i,total;
    NODE temp=head;

    total=count_node(head);
    printf("\nnumber of elements in the list\t%d",total);

    if(pos>=0 && pos<=total+1)
    {
        if(pos==1)
        {
            newnode->next = head;
            head = newnode;
            return head;
        }

        else
        {
            if(pos==total+1)
            {
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=newnode;
                newnode->next=NULL;
                return head;
            }

            for(i=1;i<pos-1;i++)
            {
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
            return head;
        }
    }

}


int main()
{
     NODE head,newnode;
     printf("\nhead information");
     head=getnode();
     head=read(head);
     display(head);

     int i,n,pos;


     printf("\nenter the number of nodes to insert at the end");
     scanf("%d",&n);

     for(i=0;i<n;i++)
     {
         newnode=getnode();
         newnode=read(newnode);
         head=insert_end(head,newnode);
     }

     display_all(head);

     printf("\nenter node to be inserted");
     newnode=getnode();
    newnode=read(newnode);
    printf("\nenter the position at which you want to insert it");
    scanf("%d",&pos);

     head = insert_new_at_pos(head,newnode,pos);

     display_all(head);

     printf("\n\n");
}

