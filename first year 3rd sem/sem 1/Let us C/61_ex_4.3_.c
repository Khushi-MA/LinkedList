#include<stdio.h>
int main()
{
    int yos, qual, salary;
    char g;

    printf("enter the gender of the employ \nmale m \nfemale f\n");
    scanf("%c",&g);
    getchar();
    printf("\nenter years of experience\n");
    scanf("%d",&yos);
    printf("\nenter qualifications\n1 for Post graduate\n2 for Graduate\n");
    scanf("%d",&qual);

    if(g='f')
    {
        if(yos>=10)
        {
            if(qual==1)
            salary = 12000;

            if(qual==2)
            salary = 9000;
        }

        else
        {
            if(qual==1)
            salary = 10000;

            if(qual==2)
            salary = 6000;
        }

    }

    else
    {

        if(yos>=10)
        {
            if(qual==1)
            salary = 11000;

            if(qual==2)
            salary = 10000;
        }

        else
        {
            if(qual==1)
            salary = 10000;

            if(qual==2)
            salary = 7000;
        }

    }

    printf("\n\nsalary = %d\n\n",salary);


}
