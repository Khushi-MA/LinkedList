#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 100


    struct node
    {
        char arr[M];
        struct node *next;
    };

    typedef struct node *NODE;

NODE readnode(NODE,int);
NODE insertend(NODE,NODE);
NODE getnode(NODE);
int allpresent(NODE , int );
void oneday(NODE ,int ,int );
NODE deleteabsent(NODE, int);
//void displayall(NODE);

int main()
{
    int m,n,i;
    printf("enter the number of students\t");
    scanf("%d",&m);
    printf("\nenter number of days\t");
    scanf("%d",&n);

    NODE head=NULL,newnode,temp;

    printf("\nenter details\n");

    for(i=0;i<n;i++)
    {
        printf("\nenter the details of day %d\n",i);
        newnode=readnode(newnode,m);
        head=insertend(head,newnode);
    }

    int ap,day;
    ap=allpresent(head, m);
    printf("\n%d days- all students are present\n",ap);
    printf("\nenter the day\t");
    scanf("%d",&day);
    oneday(head,m,day);
    head=deleteabsent(head,m);
    //displayall(head);

    return 0;
}

NODE readnode(NODE temp, int m)
{
    temp=getnode(temp);

    int i=1;
        scanf("%s",&temp->arr);

    return temp;
}

NODE getnode(NODE temp)
{
    temp=(NODE)malloc(sizeof(struct node));
    temp->next=NULL;
    return temp;
}

NODE insertend(NODE head, NODE newnode)
{
    NODE temp=head;
    if(temp==NULL)
    {
        head=newnode;
    }

    else
    {
        for(temp=head;temp->next!=NULL;temp=temp->next);
        temp->next=newnode;
    }
    newnode->next=NULL;
        return head;
}

int allpresent(NODE head, int m)
{
    NODE temp;
    temp=head;
    int i,flag=0,count=0;
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        for(i=0,flag=0;i<m;i++)
        {
            if(temp->arr[i]==112 || temp->arr[i]==80)
            {
                flag++;
            }
        }
        if(flag==m)
            count++;
    }
    return count;
}

void oneday(NODE head,int m,int day)
{
    NODE temp;
    int i,flag1,flag2;
    for(temp=head,i=0;i<day;i++);

        for(i=0,flag1=0,flag2=0;i<m;i++)
        {
            if(temp->arr[i]==112 || temp->arr[i]==80)
            {
                flag1++;
            }

             if(temp->arr[i]==97 || temp->arr[i]==65)
            {
                flag2++;
            }
        }

    printf("\npresent = %d\nabsent = %d",flag1,flag2);
    return;
}

NODE deleteabsent(NODE head, int m)
{
    NODE temp,prev=NULL;
    int i,flag;

    for(temp=head;temp!=NULL;prev=temp,temp=temp->next)
    {
        for(i=0;i<m;i++)
        {
            if(temp->arr[i]==97 || temp->arr[i]==65)
            {
                flag++;
            }
        }

            if(flag!=m)
                continue;

            else
            {
                if(temp==head)
                {
                    head=head->next;
                    free(temp);
                    temp=head;
                    return head;
                }
                else
                {
                    prev->next=temp->next;
                    free(temp);
                    temp=prev->next;
                    return head;
                }
            }
    }
    return head;

}



