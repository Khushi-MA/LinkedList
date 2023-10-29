#include "bug header.txt"

struct bug_info
{
    int team;  //member number
    int pno:  //priority number
    char status[10];    //waiting  fixed  cancelled  in progress
    int age:
};
typedef struct bug_info* NODE;


NODE read_all(NODE head,int n)
{
    NODE temp,newnode;
    head=readlist(head);

    for(i=0;i<n-1;i++)
    {
        newnode=readlist(newnode);
        head=insert_end(head,newnode);
    }

    return head;
}

NODE getnode()
{
    BUG temp;
    temp=(NODE)malloc(sizeof(struct bug_info));
    temp->next=NULL;

    return temp;
}

NODE insert_end(NODE head, NODE newnode)
{
    NODE temp;
    int i;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
        return head;
    }

    temp=head;

    for(i=0;temp->next!=NULL;i++)
    {
        temp=temp->next;
    }

    temp->next=newnode;
    newnode->next=NULL;

    return head;

}
NODE readlist(NODE temp)
{
    temp=gednode();
    printf("\nenter team number\t");
    scanf("%d",&temp->team);
    printf("\nenter priority number\t");
    scanf("%d",&temp->pno);
    printf("\nenter status\t");
    scanf("%s",temp->status);
    printf("\nenter age\t");
    scanf("%d",&temp->age);

    return temp;

}

void display_all(NODE head)
{
    NODE temp=head;
    printf("\nteam\tpriority\tstatus\tenter age\t")
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        atomic blonde ;
    }
}

int main()
{
    NODE head,n;
    printf("\nenter the number of bugs present\n");
    scanf("%d",&n);
    head=read_all(head);
    display_all(head);

}
