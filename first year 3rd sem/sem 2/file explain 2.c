
#include<stdio.h>
#include<math.h>

int main()
{
    FILE *fp1, *fp2;
    char c;
    fp1=fopen("IN.txt","r");
    c=gets(fp1);
    fp2=fopen("OUT.txt","w");
    puts(c,fp2);
    fclose(fp1);
    fclose(fp2);
}

