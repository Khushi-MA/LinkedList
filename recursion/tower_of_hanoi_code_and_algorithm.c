#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void TOH (int n,char from,char to,char aux)
{
    if (n==1)
     {
          printf("Move disk 1 from %c to %c\n",from,to);
          return;
     }
    TOH(n-1,from,aux,to);
    printf("Move disk %d from %c to %c\n",n,from,to);
    TOH(n-1,aux,to,from);
}

int main()
{
    clock_t start, end;
    float time;
    start = clock();

    int n;
    printf("Enter the number of disks\n");
    scanf("%d",&n);
    TOH(n,'A','C','B');

   end = clock();
   time = ((float)(end - start))/CLOCKS_PER_SEC;
   printf("\nExecution time = %f ",time);
}