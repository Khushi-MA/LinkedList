#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct //song details
{
    char song[100],singer[100];
    float dur;
    int year;
}SONG;

struct node
{
    struct node *next,*prev;
    SONG data;
};
typedef struct node* NODE;

NODE read(NODE );
NODE getnode();
NODE insertend(NODE ,NODE );
void displayall(NODE);
void displaysinger (NODE,char[]);
NODE deletesong(NODE,char[] );


int main() {
    int N;
    scanf("%d",&N);
    if(N<=0)
    {
        printf("Invalid input.");
        return 0;
    }
    NODE head=NULL,newnode;
    int i;
    for(i=0;i<N;i++)
    {
        newnode=read(newnode);
        head=insertend(head, newnode);
    }
    char fsinger[100],fsong[100];
    printf("\n\ndone data collecting");
    scanf("%s",fsinger);
    scanf("%s",fsong);
    displayall(head);
    displaysinger(head,fsinger);
    head=deletesong(head,fsong);
}

NODE read(NODE temp)
{
    temp=getnode();
    temp->prev=temp->next=NULL;
    scanf("%s %s %f %d",temp->data.song,temp->data.singer,&temp->data.dur,&temp->data.year);
    return temp;
}

NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    return temp;
}

NODE insertend(NODE head,NODE newnode)
{
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    NODE temp;
    for(temp=head;temp->next!=NULL;temp=temp->next);
    temp->next=newnode;
    newnode->prev=temp;
    return head;
}

void displayall(NODE head)
{
    NODE temp;
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        printf("%s %s %.2f %d\n",temp->data.song,temp->data.singer,temp->data.dur,temp->data.year);
    }
    return;
}

void displaysinger (NODE head,char fsinger[100])
{
    int cnt;
    NODE temp;
    for(temp=head,cnt=0;temp!=NULL;temp=temp->next)
    {
        if(strcmp(fsinger,temp->data.singer)==0)
        {
            cnt++;
            printf("\n%s %s %.2f %d",temp->data.song,temp->data.singer,temp->data.dur,temp->data.year);
        }
    }

    if(cnt==0)
    {
        printf("No songs of %s to display",fsinger);
    }

    return ;
}

NODE deletesong(NODE head,char name[100])
{
    NODE temp,back=NULL;
    int flag=0;
    for(temp=head;temp!=NULL;back=temp,temp=temp->next)
    {
        if(strcmp(temp->data.song,name)==0)
        {
            if(temp->prev==NULL)
            {
                head=head->next;
                head->prev=NULL;
            }

            else
            {
                back->next=temp->next;
                (temp->next)->prev=back;
            }
            flag=1;
        }

        if(flag==1)
        {
            break;
        }

    }

    if(flag==0)
    {
        printf("No song %s to delete",name);
        return head;
    }

    printf("\nDeleted %s %s %.2f %d",temp->data.song,temp->data.singer,temp->data.dur,temp->data.year);
    free(temp);
    return head;
}
