#include "kalia_header.h"

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
