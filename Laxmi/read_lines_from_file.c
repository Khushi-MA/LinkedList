// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void comparefun(char a[100], char b[10]);

// Driver code
int main()
{
    FILE *ptr, *ptrj;
    int choice, lines, i, n, count;
    char file_name[100], ch, chi, chj, str1, str[100], pattern[10], sentence[100];

    printf("\nDo you want to-\n1. enter your text?\n2. Read from file?\n3. count the number of lines in a file\n4. Pattern matching\nnchoice:  ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("\nenter the name of the file you want to save your text in\n");

        getchar();
        scanf("%[^\n]%*c", file_name);

        printf("\n enter the number of lines you want    ");
        scanf("%d", &n);

        printf("\n :: The lines are ::\n");
        ptr = fopen(file_name, "a"); // fname = "name_of_file"
        for (i = 0; i <= n; i++)
        {
            fgets(str, sizeof str, stdin);
            fputs(str, ptr);
        }
        fclose(ptr);
        break;

    case 2: // Opening file in reading mode
        printf("\n enter the name of file\n(along with the '.txt' extention)\n");

        getchar();
        scanf("%[^\n]%*c", file_name);

        ptr = fopen(file_name, "r");

        if (NULL == ptr)
            printf("file can't be opened \n");

        else
        {
            printf("content of this file are \n");

            // Printing what is written in file character by character using loop.
            do
            {
                ch = fgetc(ptr);
                printf("%c", ch);

                // Checking if character is not EOF.If it is EOF stop reading.
            } while (ch != EOF);

            // Closing the file
            fclose(ptr);
        }
        break;

    case 3:
        printf("\n enter the name of file\n(along with the '.txt' extention)\n");

        getchar();
        scanf("%[^\n]%*c", file_name);

        ptr = fopen(file_name, "r");

        if (NULL == ptr)
            printf("file can't be opened \n");

        else
        {
            for (ch = getc(ptr); ch != EOF; ch = getc(ptr))
            {
                // Increment count if this character is newline
                if (ch == '\n')
                    count = count + 1;
            }
            printf("\ncount = %d\n", count - 1);

            // Closing the file
            fclose(ptr);
        }
        break;

    case 4:
        printf("\n enter the name of file\n(along with the '.txt' extention)\n");

        getchar();
        scanf("%[^\n]%*c", file_name);
        printf("\nenter the pattern you want to find:  ");

        getchar();
        scanf("%[^\n]%*c", &pattern);

        printf("\npattern is: %s\n",pattern);

        ptr = fopen(file_name, "r");
        ptrj = fopen(file_name, "r");

        if (NULL == ptr)
            printf("file can't be opened \n");

        else
        {
            for (ch = getc(ptr); ch != EOF; ch = getc(ptr))
            {
                for (i = 0; ch != '\n'; i++, ch = getc(ptr))
                    sentence[i] = ch;

                printf("\nafter reading sentence in else-for\n%s", sentence);
                comparefun(sentence, pattern);
            }
        }

        printf("\ncount = %d\n", count - 1);

        // Closing the file
        fclose(ptr);

    default:
        exit(0);
    }

    return 0;
}

void comparefun(char a[100], char b[10])
{
    int i, j, count = 0, flag = 0;
    for (i = 0, count = 0; i < strlen(a); i++)
    {
        for (j = 0; j < strlen(b); j++)
        {
            if (a[i] == b[j])
                count++;

            if (count == strlen(b))
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
            printf("\n, not found");

        else
            printf('\n YAYYY!!!');
    }
}
