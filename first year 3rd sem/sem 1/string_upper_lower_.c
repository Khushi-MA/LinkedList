/*
A-Z    65-90
a-z    97-122
0-9    48-57
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main()
{
    char str[10];
    int i;
    gets(str);

    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>=65 && str[i]<=90)   // for(str[i]>='A' && str[i]<='Z')
        {
            str[i]=tolower(str[i]);
        }

        else
        {
            str[i]=toupper(str[i]);
        }
    }

    puts(str);


}
