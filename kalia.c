/*

Q2.

Kaalia the thief wants to loot money from a society having N houses in a single line. He is a weird
person and follows a certain rule when looting the houses. According to the rule, he will never loot
two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief
knows which house has what amount of money but is unable to come up with an optimal looting
strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule.
Each house has amount of money present in it. Kaalia keeps house information using Money, HNo
and Owner name fields.


Input format:
The first line contains an integer N which denotes the number of houses. Next N lines contains the
details of houses . Each record is entered on separated line

Output format:
First line prints an integer which denotes the maximum amount that he can take home.

Constraints:
1 <= HNo<= 100
1 <= Money <= 100000
Owner name contains maximum 30 characters


Test Case1:
5
5 93 sai
10 94 avni
100 95 shashi
10 96 mantesh
5 97 amit

Output:
110


Test Case2:
Input :
3
1 7 moin
2 8 praveen
3 9 vijay

Output: :
4


*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

struct kalia
{
    int money;
    int hno;
    char name[30];
    struct kalia* next;
};

typedef struct kalia * NODE;


NODE getnode();
NODE read_list(NODE);
NODE read_nodes(NODE,int);
NODE insert_end(NODE,NODE );
void display_one(NODE);
void display_all(NODE);
int kalia_count(NODE);


int kalia_count(NODE head)
{
    NODE temp=head;

    int count1=0, count2=0;

    do
    {
        count1=count1+temp->money;
        temp=temp->next->next;
    }while(temp!=NULL);

    temp=head->next;

    do
    {
        count2=count2+temp->money;
        temp=temp->next->next;
    }while(temp!=NULL);

    if(count1>count2)
    {
        return count1;
    }

    else
    {
        return count2;

    }
}



void display_one(NODE temp)
{
    printf("\n%d\t%d\t%s\t",temp->money,temp->hno,temp->name);
    return;
}

void display_all(NODE head)
{
    NODE temp=head;
    printf("\nmoney\tH.No\tname\t");

    do
    {
        printf("\n%d\t%d\t%s\t",temp->money,temp->hno,temp->name);
        temp=temp->next;
    }while(temp!=NULL);

    return;
}


NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct kalia));

    temp->next=temp;
    return (temp);
}


NODE read_list(NODE temp)
{
    temp=getnode();

    printf("\nenter the amount in the house\t");
    scanf("%d",&temp->money);
    printf("enter the house number\t");
    scanf("%d",&temp->hno);
    printf("enter the house owner's name");
    scanf("%s",temp->name);

    return temp;
}


NODE read_nodes(NODE head,int n)
{
    NODE newnode;
    int i;
    printf("\n\nnumber of houses\n)");
    head=read_list(head);

    for(i=0;i<n-1;i++)
    {
        newnode=read_list(newnode);
        head=insert_end(head,newnode);
    }
    return (head);
}




NODE insert_end(NODE head,NODE newnode)
{
    NODE temp;

    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
        return (head);
    }

    temp=head;
    do
    {
        temp=temp->next;
    }while(temp->next!=head);

    temp->next=newnode;
    newnode->next=NULL;

    return head;
}



int main()
{
    NODE head;
    int i,n,maxM;

    printf("\nenter the number of houses\t");
    scanf("%d",&n);
    head=read_nodes(head,n);
    display_all(head);
    maxM=kalia_count(head);
    printf("\nmax money he can loot is %d",maxM);
}


