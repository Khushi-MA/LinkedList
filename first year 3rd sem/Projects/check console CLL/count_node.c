#include "header.h"
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

