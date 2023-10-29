/*two numbers are input in two locations C and D.
write a program to interchange the contents ofmC and D*/

#include<stdio.h>
int main()
{
    int C,D,E;
    printf("enter digits for C and D");
    scanf("%d%d",&C,&D);
    E=C;
    C=D;
    D=E;
    printf("C=%d\nD=%d\n",C,D);
    return 0;

}
