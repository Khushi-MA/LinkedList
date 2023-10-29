#include<stdio.h>
#include<stdlib.h>

struct random_call
{
    int integer;
    float decimal;
    char character;
    struct random_call *next;
};

typedef struct random_call *NODE;

NODE getnode()
{
    NODE temp;
    temp = (NODE) malloc(sizeof(struct random_call));
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
    printf("the integer:\t");
    scanf("%d",&temp->integer);
    printf("the float value\t");
    scanf("%f",&temp->decimal);
    printf("the character\t");
    scanf("%c",&temp->character);
    getchar();
    return temp;
}



NODE insert_end(NODE head, NODE newnode)
{
    NODE temp;
    temp = head;


        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;


    return(head);
}

void display_all(NODE temp)
{
    while(temp != NULL)
    {
        printf("\nthe integer\t%d",temp->integer);
        printf("\nthe float\t%f",temp->decimal);
        printf("\nthe character\t\t%c",*temp->character);
        putchar(temp->character);
        temp=temp->next;
    }
}

int main()
{
    NODE head, next_node;

    int choice,n,i;

    printf("\nenter the number of sets you want to read\t");
    scanf("%d",&n);



    head=getnode();
    head=read(head);

     for(i=0;i<n-1;i++)
     {

         next_node=getnode();
         next_node=read(next_node);
         head=insert_end(head,next_node);
     }

     display_all(head);
}


