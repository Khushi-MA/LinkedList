#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct mango
{
    int ripe;
    struct mango *prev,*next;
};
typedef struct mango* NODE;
NODE readnode(NODE);
NODE getnode();
NODE insertend(NODE , NODE);
NODE condition(NODE);

int main() {
    int N;
    scanf("%d",&N);
    if(N<=0 || N>100)
    {
        printf("Invalid input.");
        return 0;
    }
    NODE head=NULL,newnode;
    int i;
    for(i=0;i<N;i++)
    {
        newnode=readnode(newnode);
        head=insertend(head,newnode);
    }

    head=condition(head);
}

NODE readnode(NODE temp)
{
    temp=getnode();
    temp->next=temp->prev=NULL;
    scanf("%d",&temp->ripe);
    return temp;
}

NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct mango));
    return temp;
}

NODE insertend(NODE head, NODE newnode)
{
    if (head==NULL)
    {
        head=newnode;
        newnode->next=newnode->prev=NULL;
        return head;
    }
    NODE cur;
    for(cur=head;cur->next!=NULL;cur=cur->next);
    cur->next=newnode;
    newnode->prev=cur;
    return head;
}

NODE condition(NODE head)
{
    NODE cur,back;
    int count=0;
    for(cur=head->next,back=head;cur!=NULL;cur=cur->next)
    {
        if(cur->ripe < back->ripe)
        {
            //delete "back" node
            if(back==head)
            {
                free(back);
                back=head=cur;
                cur->prev=NULL;
                count++;
            }

            else
            {
                (back->prev)->next = cur;
                cur->prev=back->prev;
                free(back);
                back=cur;
                count++;
            }

        }
        else
            back=cur;
    }
    for(cur=head;cur!=NULL;cur=cur->next)
    {
        printf("%d ",cur->ripe);
    }
    printf("\n%d",count);
    return head;
}
