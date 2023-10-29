#include<stdio.h>
int main()
{
   int c = 7, no = 10;

    do {

        no /= c;

      c--;

    } while(c);



    printf ("%dn", no);

}
