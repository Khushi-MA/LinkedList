#include<stdio.h>
int main()
{
    int i,j,k,n;
    for(i=1;i<4;i++)
    {
        for(j=1;j<4;j++)
        {
             for(k=1;k<4;k++)
             {
                 n=(i*100)+(j*10)+k;
                  printf("\n%d",n);

             }

        }

    }

}
