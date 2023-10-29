#include<stdio.h>
int main()
{
    /*input character indicating class ship*/
    char class_ID;
    printf("enter ship serial number");
    class_ID=getchar();
    scanf("%c",&class_ID);            /*scan first letter*/
    printf("ship class is %c:",class_ID);       /*display first character followed by ship class*/

    switch(class_ID)
    {

    case'B':
    case'b':
        printf("battleship\n");
    break;

    case'C':
    case'c':
        printf("cruiser\n");
    break;

    case'D':
    case'd':
        printf("destroyer\n");
    break;

    case'F':
    case'f':
        printf("frigate\n");
    break;

    default:
        printf("unknown");

    }

}
