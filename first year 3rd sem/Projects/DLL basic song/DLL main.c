#include "DLL menu.h"

int main()
{
    NODE head,temp;
    head=NULL;
    SONG s;
    char  fsinger[100];
    int ch1, ch2, count, pos,i;

    do
    {
        printf("\nSong functions:\n1.Insert\n2.Delete\n3.Count\n4.Display\n");
        printf("enter '100' to exit\nEnter choice\t");
        scanf("%d",&ch1);

        switch(ch1)
        {
            case 1: printf("\nInsert:\n1.Beginning\n2.End\n3.By position\nEnter choice\t");
                    scanf("%d",&ch2);
                    switch(ch2)
                    {
                        case 1: readsong(&s);
                                head=addatthebegin(head,s);
                                break;

                        case 2: readsong(&s);
                                head=addattheend(head,s);
                                break;

                        case 3: printf("\nEnter the song details");
                                readsong(&s);
                                printf("\nEnter the position\t");
                                scanf("%d",&pos);
                                if(pos<=0 || pos>1+count)
                                {
                                    printf("\nInvalid position");
                                    break;
                                }
                                count=countsongs(head);
                                head=insertposition(head,s,pos);
                                break;
                    }
                    break;

            case 2: printf("\nDelete:\n1.Beginning\n2.End\n3.By song\n");
                    scanf("%d",&ch2);
                    switch(ch2)
                    {
                        case 1: head=deleteatthebegin(head);
                                break;

                        case 2: head=deleteattheend(head);
                                break;

                        case 3: printf("\nenter the name of the singer\t");
                                scanf("%s",fsinger);
                                count=countsinger(head,fsinger);
                                printf("\n' %s ' has sung %d songs in your playlist",fsinger, count);
                                break;
                    }
                    break;

            case 3: printf("\nCount:\n1.Total songs\n2.By singer\n");
                    scanf("%d",&ch2);
                    switch(ch2)
                    {
                        case 1: count=countsongs(head);
                                if(count==0)
                                {
                                    printf("\nNo songs in the list");
                                    break;
                                }
                                printf("\nThere is/are %d song(s) in the list\n",count);
                                break;

                        case 2: printf("\nenter the name of the singer\t");
                                scanf("%s",fsinger);
                                count=countsinger(head,fsinger);
                                printf("\n'%d songs",count);
                                break;
                    }
                    break;

            case 4: printf("\nDisplay:\n1.All\n2.In reverse\n3.By position\n");
                    scanf("%d",&ch2);
                    switch(ch2)
                    {
                        case 1: displayall(head);
                                break;

                        case 2: displayallreverse(head);
                                break;

                        case 3: printf("\nEnter the position\t");
                                scanf("%d",&pos);
                                count=countsongs(head);
                                if(pos<=0 || pos>1+count)
                                {
                                    printf("\nInvalid position");
                                    break;
                                }
                                for(temp=head,i=1;i<pos-1;temp=temp->next);
                                displayonedown(temp);
                                break;
                    }
                    break;

            case 100: break;
        }
    }while(ch1!=100);
    return 0;
}

