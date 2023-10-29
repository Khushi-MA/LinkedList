#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct friend
{
    int popularity;
    struct friend* next;
};

typedef struct friend *NODE;

void display(NODE);
NODE insert_end(NODE);
NODE getnode();
void deletefriend(NODE, int);

NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct friend));
    temp->next=NULL;
    printf("enter popularity  ");
    scanf("%d",&temp->popularity);
    return temp;
}

void display(NODE head)
{
     NODE cur=head;
     printf("NOW POPULARITY\n");
			while(cur!=NULL)
			{
				printf("%d ",cur->popularity);
				cur=cur->next;
			}
            return;
}

NODE insert_end(NODE head)
{
    NODE newnode,cur=head;
    newnode=getnode();

    if(head==NULL)
        head=newnode;
        

    else
    {
        while(cur->next!=NULL)
            cur=cur->next;
        
        cur->next=newnode;
    }
    return head;
    display(head);

}

void deletefriend(NODE head, int K)
{
  NODE temp, cur=head, prev=NULL;
  int i=0;
  printf("\ni=%d K=%d",i, N);
  while(i<K)
  {
    printf("\ni=%d enter while in deletefriend)",i);
    if(cur->popularity < cur->next->popularity)
    {
       if(cur==head)
       head=cur->next;
       printf("\nenter delete friend");
       prev->next = cur->next;
       free(cur);
       cur=prev->next;
       i++;
    }

    else
    {
        cur=cur->next;
        printf("\ntraverse");
    }
    
    if(cur->next==NULL)
    {
        cur=head;
        printf("exceptional case of stuck in the end)");
    }
    
  }
 display(head);
    return;
}

int main()
{
    NODE head=NULL,newnode;
    int T,N,K,i,j;
    printf("enter test cases:  ");
    scanf("%d",&T);

    for(i=0;i<T;i++)
    {
        printf("\nenter current number:  ");
        scanf("%d",&N);
        printf("enter to delete:  ");
        scanf("%d",&K);
        for(j=0;j<N;j++)
            head = insert_end(head);

        deletefriend(head,K);
        free(head);
        head=NULL;
    }
    return 0;
}
