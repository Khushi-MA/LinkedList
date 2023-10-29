#include "SLL menu header.h"

//function to read details of the candidate
NODE read()
{
    NODE temp;
    temp=getnode();
    printf("\nENTER DETAILS\n");
    scanf("%s%d%d",temp->name,&temp->rank,&temp->age);
    return temp;
}

// Function to allocate memory dynamically using malloc() function
NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct candidate));
    if(temp==NULL)
        return NULL;
    else
        temp->next=NULL;

    return temp;
}


// function to count the number of nodes in the list
int count(NODE head)
{   NODE temp=head;
     if (head == NULL)
        return 0;
    int c=0;
    while(temp !=NULL)
    {
        c++;
        temp = temp->next;

    }
    return c;
}
