#include<stdio.h>
#include<string.h>

int main()
{
    char password[15];

    printf("enter your password");
    gets(password);
    if(strlen(password)<8)
        printf("invalid pass");

    else
        check_pass(password);

}

//   @  #  *  &

void check_pass (char password[15])
{
    int i,alpha=0,ALPHA=0,num=0,spec=0;

    for(i=0;i!='\0';i++)
    {

        if(password[i]>'a' && password[i]<'z')
            alpha++;

        else if(password[i]>'A' && password[i]<'Z')
            ALPHA++;

        else if(password[i]>=0 && password[i]<=9)
            num++;


        else if(password[i]=='@' || password[i]=='#' || password[i]=='*' || password[i]=='&')
            spec++;

    }


    if(alpha>=1 && ALPHA>=1 && num>=1 && spec>=1)
        printf("pass valid");


    else
        printf("pass invalid");



}
