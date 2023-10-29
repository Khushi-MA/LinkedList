#include<stdio.h>
int main()
{
char grade,A,B,C;
printf("enter character/grade");
grade=getchar();
scanf("%c",&grade);
switch(grade)
{
    case'A': printf("excellent");
    break;

    case'B': printf("keep it up\n\n");
    break;

    case'C': printf("well done\n\n");
    break;

    default:printf("invalid grade\n");
}



    return 0;


}
