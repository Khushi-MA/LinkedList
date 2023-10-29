#include "DLL menu.h"

int countsinger (NODE head,char fsinger[100])
{
    int cnt;
    NODE temp;
    for(temp=head,cnt=0;temp!=NULL;temp=temp->next)
    {
        if(strcmp(fsinger,temp->data.singer)==0)
        {
            cnt++;
            displayonedown(temp);
        }
    }

    return cnt;
}

int countsongs(NODE head)
{
    NODE temp;
    int cnt;
    for(temp=head,cnt=0;temp!=NULL;temp=temp->next,cnt++);
    return cnt;
}


