
#include<stdio.h>
#include<math.h>

int main()
{
    FILE *fp1, *fp2;
    int i;
    char c;
    fp1=fopen("IN.txt","r");
    fp2=fopen("OUT.txt","w");
    for(i=0;*fp1!='\0';fp1++,fp2++)
    {
        c=gets(fp1);
        putc(c,fp2);
    }

    fclose(fp1);
    fclose(fp2);

}

