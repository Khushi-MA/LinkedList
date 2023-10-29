#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


int wrhfunc(char code[])
{
    int i, point=0;
    char wrh[999];
    for (i=0;code[i]!='\0';i++)
    {
        if(isdigit(code[i]))
        {
            break;
        }
        else
        {
            wrh[i]=code[i];
            point = point +1;
        }

    }
    printf("Wharehouse = ");
        puts(wrh);
        return point;
}

int prodfunc(char code[], int po)
{
    int i=po, point=0;
    char prod[999];
    for (i=po;code[i]!='\0';i++)
    {
        if(isalpha(code[i]))
        {
            break;
        }
        else
        {
            prod[i-po]=code[i];
            point = point +1;
        }
    }
    printf("product = ");
    puts(prod);
    return point;
}

void szfunc(char code[], int point)
{
    int i, pointt=0;
    char sz[999];
    printf("Qualifiers = ");
    for (i=point+3;code[i]!='\0';i++)
    {
        printf("%c",code[i]);
    }



}

int main()
{
    char code[999];
    int po, point;
    printf("enter the warehouse code");
    gets(code);
    po = wrhfunc(code);
    point = prodfunc(code, po);
    szfunc(code,point);

}
