#include "DLL circular menu.h"

int countnodes(NODE head)
{
    if(head==NULL)
    {
        return 0;
    }
    NODE temp=head;
    int cnt=0;
    do
    {
        cnt++;
        temp=temp->next;
    }while(temp!=head);
    return cnt;
}
