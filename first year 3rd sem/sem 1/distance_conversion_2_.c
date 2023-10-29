/*program to convert distance in kilometres to
metres, feet, inches and centimetres*/

#include<stdio.h>
int main()
{
    float Km,m,f,i,cm;
    printf("Enter distance in Km");
    scanf("%f",&Km);
    m=Km*1000;
    f=Km*3280.84;
    i=Km*39370.1;
    cm=Km*100000;
    printf("m=%f\n",m);
    printf("f=%f\n",f);
    printf("i=%f\n",i);
    printf("cm=%f\n",cm);



return 0;

}



