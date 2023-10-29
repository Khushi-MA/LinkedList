#include "DLL circular menu.h"

int main()
{
    int ch1,ch2,pos,total;
    NODE head=NULL,newnode;
    char fname[100];

    do
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Count\n100.EXIT\nEnter choice:  ");
        scanf("%d",&ch1);

        switch(ch1)
        {
            case 1: printf("\nInsert\n1.beginning\n2.end\n3.at a position\nEnter choice:  ");
                    scanf("%d",&ch2);


                    switch(ch2)
                    {
                        case 1: newnode=readnode(newnode);
                                head=insertbegin(head,newnode);
                                break;

                        case 2: newnode=readnode(newnode);
                                head=insertend(head,newnode);
                                break;

                        case 3: newnode=readnode(newnode);
                                printf("\nenter position:\t");
                                scanf("%d",&pos);
                                total=countnodes(head);
                                if(pos<1 || pos>total+1)
                                {
                                    printf("\nposition non existent\n");
                                    break;
                                }
                                head=insertbyposition(head,newnode,pos);
                                break;

                        default: printf("\nInvalid option");
                                 break;
                    }
                    break;


            case 2: if(listempty(head))
                    {
                        printf("\nList is empty\n");
                        break;
                    }

                    if(head->next==head)
                    {
                        printf("\nnode being deleted is\n");
                        displayone(head);
                        free(head);
                        head=NULL;
                        break;
                    }

                    printf("\nDelete\n1.beginning\n2.end\n3.By position\n4.By name\nEnter choice:  ");
                    scanf("%d",&ch2);

                    switch(ch2)
                    {
                        case 1: head=deletebegin(head);
                                break;

                        case 2: head=deleteend(head);
                                break;

                        case 3: printf("\nenter position:\t");
                                scanf("%d",&pos);
                                total=countnodes(head);
                                if(pos<1 || pos>total+1)
                                {
                                    printf("\nposition non existent\n");
                                    break;
                                }
                                head=deletebyposition(head,pos);
                                break;

                        case 4: printf("\nenter the name:\t");
                                scanf("%s",fname);
                                head=deletebyname(head,fname);

                        default: printf("\nInvalid option");
                                 break;
                    }
                    break;



            case 3: if(listempty(head))
                    {
                        printf("\nList is empty\n");
                        break;
                    }

                    printf("\nDisplay\n1.Alright\n2.All Reverse\n3.By position\nEnter choice:  ");
                    scanf("%d",&ch2);

                    switch(ch2)
                    {
                        case 1: displayall(head);
                                break;

                        case 2: displayreverse(head);
                                break;

                        case 3: printf("\nenter position:\t");
                                scanf("%d",&pos);
                                total=countnodes(head);
                                if(pos<1 || pos>total)
                                {
                                    printf("\nposition non existent\n");
                                    break;
                                }
                                displaybyposition(head,pos);
                                break;

                        default: printf("\nInvalid option");
                                 break;

                    }
                    break;

            case 4: if(listempty(head))
                    {
                        printf("\nNumber of nodes in your list = 0\n\n");
                        break;
                    }

                    total=countnodes(head);
                    printf("\nNumber of nodes in your list = %d\n\n",total);
                    break;


            case 100: printf("\nCode exit...THANKYOU :)\n\n");
                      break;

            default: printf("\nInvalid option '_'\n\n");
                     break;
        }

    }while(ch1!=100);

    return 0;
}

