#include "DLL menu.h"

void displayall(NODE head)
{
    NODE cur;
    cur=head;
    printf("\nname\tsinger\tdate\t");
    while(cur!=NULL)
    {
        printf("\n%s\t%s\t%d-%d-%d\t",cur->data.name,cur->data.singer,cur->data.date.d,cur->data.date.m,cur->data.date.y);
        cur=cur->next;
    }
    printf("\n");
    return;
}

void displayonedown(NODE cur)
{
    printf("\nsong  %s\nsinger  %s\ndate  %d-%d-%d",cur->data.name,cur->data.singer,cur->data.date.d,cur->data.date.m,cur->data.date.y);
    printf("\n");
    return;
}

void displayoneline(NODE cur)
{
    printf("\n%s\t%s\t%d-%d-%d\t",cur->data.name,cur->data.singer,cur->data.date.d,cur->data.date.m,cur->data.date.y);
    printf("\n");
    return;
}

void displayallreverse(NODE head)
{
    NODE cur;
    for(cur=head;cur->next!=NULL;cur=cur->next);    // traverse till last node
    while(cur!=NULL)
    {
        printf("\n%s\t%s\t%d-%d-%d\t",cur->data.name,cur->data.singer,cur->data.date.d,cur->data.date.m,cur->data.date.y);
        cur=cur->prev;
    }
    printf("\n");
    return;
}
