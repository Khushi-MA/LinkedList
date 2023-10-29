#include <stdio.h>
#define MAX 100
#include<string.h>
void read(char text[]);
void display(char text[]);
void eliminate(char text[]);
void main()
{
    char text[MAX]={0};
    read(text);
    printf("Input string is...\n");
    display(text);
    printf("Value of \'text\' after eliminating first character of each word...\n");
    eliminate(text);
}
void read(char text[])
{
	int loop,j;
	printf("Please input string: ");
	scanf("%[^\n]s",text); //read string with spaces
}
void display(char text[])
{
    int z;
    puts(text);
}

void eliminate(char text[])
{ int loop,j;
	for(loop=0; text[loop]!='\0'; loop++)
	{
		if(loop==0 || (text[loop]==' ' && text[loop+1]!=' '))
		{
			//shift next characters to the left
			for(j=((loop==0)?loop:loop+1); text[j]!='\0'; j++)
				text[j]=text[j+1];
		}

		// Or,...can also write just
		// text[j]=text[j+1];    (here itself)

	}
	printf("%s\n",text);
	return 0;
}
