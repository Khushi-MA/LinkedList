#define<stdio.h>
#define<stdlib.h>

struct student
{
    char usn[20];
    int roll;
    char name[50];
    float percentage;
};

int main()
{
    char *filename="C:\\Users\\Hp\\Desktop\\c programs\\Savithasoft\\Files\\text files for c pracyice\\files god code text.txt";
    int choice;

    struct student stud;
    char usn2[20];

    do
    {
        printf("\nenter choice");
        printf("\n1.Add student\n2.DIsplay all\n3.Modify\n4.Delete5.6.Exit");
        scanf("%d",choice);

        switch(choice)
        {
           case 1:
            {
                printf("\nEnter student details\n");
                printf("usn\t");
                scanf("%s",stud.usn);
                printf("%d\t");
                scanf("%d",&stud.roll);
                printf("student name\t");
                scanf("%s",stud.name);
                printf("percentage gained");
                scanf("%f",&stud.percentage);
                add_student(filename,stud);
                break;
            }

           case 2:
            {

            }
        }
    }
}

void add_student(char *filename, struct student s)
{
    FILE *fp;
    fp = fopen(filename,"a");
    fprintf("fp,"%s\t%d\t%s\t%f\n",s.usn,s.roll,s.name,s.percentage);
    fclose(fp);
}

