/*
strcmp    used to compare two strings

*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main()
{
    int i;
    char str[10],reverse_str[10];
    gets(str);

    reverse(str);
}

void reverse(char str[10])
{
    int i,j;
    char a[10],t;
    j=strlen(str)-1;

    for(i=0;i<j/2;i++,j--)
    {
        str[i]=str[i];
        str[i]=str[j];
        str[j]=t;

    }

    printf("reverse is %s",str);

    return a;
}
