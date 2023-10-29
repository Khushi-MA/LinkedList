/*
write c program to rad tex from from
1. user
2. file

display the longest line
no use of inbuitlt function

each line is max 100 characters

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define size 100

// if allocating a mamory space while reading text,
// we define a structure and use linked list to connect line by line

struct oneline
{
    char text[size];
    struct oneline *next;
};
typedef struct oneline *LINE;

LINE getnode();
LINE insertline(LINE head, LINE newnode);
void printlines_memory(LINE head);

int main()
{
    int choice, lines, i;
    LINE head, newnode;
    printf("\nDo you want to-\n1. enter your text?\n2. Read from file?");
    // scanf("%d",choice);
    // switch(choice)
    // {
    //     case 1: break;
    //     case 2: break;
    //     default: break;
    // }

    printf("\nenter the number of lines you want to read?  ");
    scanf("%d", &lines);
    printf("\nEnter the lines\n");

    newnode = getnode();
       
        // scanf("&[^\n]s", &newnode->text); // no '&' while reading string
        scanf("%[^\n]s",newnode->text);
        gets(&newnode->text);
        
        
        //printf("\nooo:   %s\n", newnode->text);
        head = insertline(head, newnode);

    for (i = 0; i < lines; i++)
    {
        
    }

    printlines_memory(head);
    return 0;
}

LINE getnode()
{
    LINE temp;
    temp = (LINE)malloc(sizeof(struct oneline));
    temp->next = NULL;

    return temp;
}

LINE insertline(LINE head, LINE newnode)
{
    LINE temp;

    if (head == NULL)
    {
        head = newnode;
    }
        

    else
    {
        for (temp = head; temp->next != NULL; temp = temp->next);
        temp->next = newnode;
    }
    return head;
}

void printlines_memory(LINE head)
{
    LINE temp;
    printf("\n\nInput text is:");
    for(temp = head; temp!=NULL;temp=temp->next)
        printf("\n%s", temp->text);
    
}