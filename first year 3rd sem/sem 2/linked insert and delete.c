#include<stdio.h>
#include<math.h>
#include<string.h>
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
    temp = (NODE)malloc(sizeof(struct planet));
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

NODE delete_node_planetpos(NODE head, int pos)
{
    printf("\n\ndelte as per position entered when called by name function\n");
    int total,i;
    total=count_node(head);
    NODE cur=head, prev=NULL;
    printf("\nnumber of elements in the list\t%d",total);

    if(pos<1 || pos>total)
    {
        printf("\n\nINVALID POSITION");
        return head;
    }

    else
    {
        if(pos == 1)
        {
            head = head->next;
            printf("\nthe node being deleted is:");
            display(cur);
            free(cur);
            return head;
        }

        for(i=1;i<pos;i++)
        {
            prev = cur;
            cur = cur->next;
        }

        prev->next = cur->next;
        printf("\nthe node being deleted is:");
        display(cur);
        free(cur);
        return head;
    }
}


NODE delete_node_planet_name_only_one(NODE head, char N[20])
{
    NODE cur=head, prev=NULL, temp=head;
    printf("\n\nfunction entered\n\n");
    int total,i,change=0,a;
    total=count_node(head);

    for(i=1;i<=total;i++,cur=cur->next)
    {
        printf("\n\nfor loop entered\n\n");
        if (strcmp(cur->name,N)==0)
        {
            head=delete_node_planetpos(head,i);
            change++;
        }
    }

    if(change==0)
        printf("\n\nINVALID NAME");

    else
        printf("\nnumber of nodes deleted is %d",change);

    return head;

}


NODE delete_node_planet_name_multiple_ones(NODE head, char N[20])
{
    NODE cur=head, prev=NULL, temp=head;
    printf("\n\nfunction entered\n\n");
    int total,i,j,change=0,a;
    total=count_node(head);

    for(j=1;j<=total;j++,cur=cur->next)
    {
        printf("\n\nfor loop entered\n\n");
        if (strcmp(cur->name,N)==0)
        {
            printf("\n\nif in the for loop entered\n\n");

            if(j==1)
            {
                head = head->next;
                printf("\nthe node being deleted is:");
                display(cur);
                free(cur);
            }

            else
            {
                for(i=1;i<j;i++)
            {
                prev = cur;
                cur = cur->next;
            }

            prev->next = cur->next;
            printf("\nthe node being deleted is:");
            display(cur);
            free(cur);

            change++;
            }
        }
    }

    if(change==0)
        printf("\n\nINVALID NAME");

    else
        printf("\nnumber of nodes deleted is %d",change);

    return head;
}


int main()
{
     NODE head,newnode;
     char deleteplanet[10];
     int deleteposition,c;

     printf("\nhead information");
     head=getnode();
     head=read(head);
     display(head);

     int i,n;

     printf("\nenter the number of nodes to insert at the end\t");
     scanf("%d",&n);

     for(i=0;i<n;i++)
     {
         newnode=getnode();
         newnode=read(newnode);
         head=insert_end(head,newnode);
     }

     display_all(head);

     printf("\ndelete as per \n1.position \n2.only one name\n3.multiple name comparison");
     scanf("%d",&c);

     if(c==1)
     {
          printf("\nenter the planet position you want to delete");
         scanf("%d",&deleteposition);
         head = delete_node_planetpos(head,deleteposition);
     }


      if(c==2)
      {
          printf("\nenter the name of the planet whose node you want to delete");
         scanf("%s",deleteplanet);
         head = delete_node_planet_name_only_one(head,deleteplanet);
      }

      if(c==3)
      {
          printf("\nenter the name of the planet whose node you want to delete");
         scanf("%s",deleteplanet);
         head = delete_node_planet_name_multiple_ones(head,deleteplanet);
      }

     printf("\n\nlist after changes");
     display_all(head);
     printf("\n\n");
}

