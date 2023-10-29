#include<stdio.h>
int main()
{
    char +,-,option,*,/,;
    int a,b;
    float r;
    printf("enter option");
    getchar();
    scanf("%c",&option);

    switch(option)
    {
        case '+':
        r=a+b;
        printf("r=",&r);

        case '-':
        r=a-b;
        printf("r=",&r);

        case '/':
        r=a/b;
        printf("r=",&r);

        case '*':
        r=a*b;
        printf("r=",&r);

        default: printf("invalid");

    }

    return 0;

}


