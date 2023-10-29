#include<stdio.h>
#include<math.h>
#include<string.h>



struct letter_info
{
    char name[30];                  // name of the person
    int hno;                        // house number
    char area[30];                  // area they live in
    double mobile;                  // phone number
    struct letter_info *next;       // pointer to point next
};

typedef struct letter_info* NODE;
NODE read(NODE);
NODE getnode();
NODE read_all();
NODE read(NODE);
NODE getnode();
void display_one(NODE);
void display_all(NODE);
int count_node(NODE);
void insert_switch(NODE);
NODE insert_end(NODE, NODE);
NODE insert_pos(NODE, int, NODE );
NODE delete_pos(NODE, int);
NODE delete_front(NODE);
NODE delete_end(NODE);
NODE delete_area(NODE, char[]);
NODE delete_house(NODE,int);
NODE delete_switch(NODE);


NODE read_all()
{
    NODE head,newnode;
     int i,n;

    printf("\nenter the number of nodes to insert to the circle\t");
     scanf("%d",&n);

     printf("\nhead information");
     head=read(head);

     for(i=0;i<n-1;i++)
     {
         newnode=read(newnode);
         head=insert_end(head,newnode);
     }
     return head;
}


int count_node(NODE head)
{
    int i=0;
    NODE temp;
    temp=head;
    if(temp == NULL)
        return 0;

    do
    {
       i++;
       temp = temp->next;

    }while(temp != head);

    return i;
}



NODE read(NODE temp)
{
    temp=getnode();
    printf("\nenter details:\n");
    printf("Name of the person:\t");
    scanf("%s",temp->name);
    printf("house number\t");
    scanf("%d",&temp->hno);
    printf("area\t");
    scanf("%s",temp->area);
    printf("phone number\t");
    scanf("%lf",&temp->mobile);
    return (temp);
}


NODE getnode()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct letter_info));
    if (temp== NULL)
    {
       printf("\ninsufficient space");
       return NULL;
    }

    else
        temp->next= temp;

     return (temp);
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
        do
        {
            temp=temp->next;
        }while(temp->next != head);
        temp->next=newnode;
        newnode->next=head;
    }
    return(head);
}


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

    do
    {
        prev=target;
        target=target->next;
    }while(target->next!=head);

    printf("\n\nnode being deleted:\n");
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
         printf("\n\nrequired loop entered\n");
         head=delete_front(head);
         return head;
     }

     else if(pos==total)
     {
         head=delete_end(head);
         return head;
     }

     else
     {
         printf("\nlet's see");
         return head;
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


void display_one(NODE temp) //only one
{
    printf("\nDetails:");
    printf("\nname\t\t%s",temp->name);
    printf("\nhouse number\t\t%d",temp->hno);
    printf("\narea\t\t%s",temp->area);
    printf("\nmobile number\t\t%lf",temp->mobile);
    return;
}

void display_all(NODE temp)
{
    NODE head;
    head=temp;
    if(temp==NULL)
    {
        printf("\nempty list");
        return;
    }

    do
    {
        printf("\nname\t\t%s",temp->name);
        printf("\nhouse number\t%d",temp->hno);
        printf("\narea\t\t%s",temp->area);
        printf("\nmobile number\t%lf",temp->mobile);
        temp=temp->next;
    }while(temp != head);

    return;
}


int main()
{
     NODE head,newnode;
     int i,n,total,choice;

    head=read_all();
    delete_switch(head);
    display_all(head);

}





