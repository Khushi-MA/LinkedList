#include "header.h"

int main()
{
     int n,run1,run2;
     NODE head;
     char Cname[30];
     printf("\nenter the number of planes\t");
     scanf("%d",&n);
     if(n<0 || n>50)
     {
         printf("Invalid input");
         return 0;
     }

     head = read_nodes(head,n);
     display_all(head);

     printf("\nenter the name of the country\t");
     scanf("%s",&Cname);
     run1=runway(head,Cname);
     printf("\nthe number of planes from first runway is %d",run1);

     run2=n-run1;
     printf("\nthe number of planes from second runway is %d",run2);
     run2_display(head,Cname);
     printf("\n\n");

     return 0;
}



