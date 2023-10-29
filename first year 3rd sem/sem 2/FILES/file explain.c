#include<stdio.h>
#include<math.h>

int main()
{
    FILE *fp1, *fp2;
    char c;
    fp1=fopen("IN.txt","r");
    c=getc(fp1);
    fp2=fopen("OUT.txt","w");
    putc(c,fp2);
    fclose(fp1);
    fclose(fp2);
}

