#include "war_header.h"

int main()
{
    NODE head,female;
    int n,pos;

    printf("\nenter the number of male soldiers");
    scanf("%d",&n);

    if(n<5)
    {
        printf("\nNOT ENOUGH SOLDIERS\n\n");
        return 0;
    }

    head=read_nodes(head,n);
    display_all(head);
    printf("\n\nenter the female soldier information");
    female=read_list(female);

    pos=insertbeforemale(head,female);

    display_all(head);
    printf("\nposition of the female soldier is %d\n\n",pos);

    return 0;
}

