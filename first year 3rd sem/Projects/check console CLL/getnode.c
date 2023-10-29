NODE read_all()
{
    NODE head,newnode;
     int i,n;

    printf("\nenter the number of nodes to insert to the circle\t");
     scanf("%d",&n);

     printf("\nhead information");
     head=read(head);

     for(i=0;i<n-1;i++)
     {
         newnode=read(newnode);
         head=insert_end(head,newnode);
     }
     return head;
}


NODE read(NODE temp)
{
    temp=getnode();
    printf("\nenter details:\n");
    printf("Name of the person:\t");
    scanf("%s",temp->name);
    printf("house number\t");
    scanf("%d",&temp->hno);
    printf("area\t");
    scanf("%s",temp->area);
    printf("phone number\t");
    scanf("%lf",&temp->mobile);
    return (temp);
}


NODE getnode()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct letter_info));
    if (temp== NULL)
    {
       printf("\ninsufficient space");
       return NULL;
    }

    else
        temp->next= temp;

     return (temp);
}


