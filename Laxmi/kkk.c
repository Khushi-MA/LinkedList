#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char word[30], sentence[30];

    printf("\nenter word\n");
    scanf("%s", word);
    printf("\n %s", word);


    printf("\n enter sentenec\n");
    gets(sentence);
    scanf("%[^\n]s", sentence);

    

    printf("\n %s", sentence); 
    return 0;
}