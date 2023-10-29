

#include<stdio.h>
#define size 500

typedef struct student_info
{
    int roll;
    char name[20];
    char dept[20];
    char course[5];
    int yoj;
}stud;

void read_info (stud s[size], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nenter student %d details\n",1+i);
        printf("roll no\t");
        scanf("%d",&s[i].roll);
        printf("name\t");
        scanf("%s",s[i].name);
        printf("department\t");
        scanf("%s",s[i].dept);
        printf("course\t");
        scanf("%s",s[i].course);
        printf("year of joining\t");
        scanf("%d",&s[i].yoj);
    }
}

void print_info (stud s[size], int n)
{
    int i;
    printf("\ns.no\troll.no.\tname\tdepartment\tcourse\tyear_of_joining\t");
    for (i=0;i<n;i++)
    {
        printf("\n%d\t%d\t\t%s\t%s\t\t%s\t%d\t",i+1,s[i].roll,s[i].name,s[i].dept,s[i].course,s[i].yoj);
    }
}

void print_only (stud s)
{

    printf("\nroll.no.\tname\tdepartment\tcourse\tyear_of_joining\t");
    printf("\n%d\t\t%s\t%s\t\t%s\t%d\t",s.roll,s.name,s.dept,s.course,s.yoj);

}

stud year_wise_struct(stud *yw,stud s[size], int n, int *n2, int y)
{
    int i,j;
    for(i=0,j=0;i<n;i++)
    {
        if(y==s[i].yoj)
        {
            yw[j]=s[i];
            j++;
        }
    }
    *n2 = j;
}

void search_roll(stud s[size], int uroll, int n, stud *Rs)
{
    int i;
    for (i=0;i<n;i++)
    {
        if(uroll==s[i].roll)
        {
            *Rs=s[i];
        }
    }
}

int main()
{
    stud s[size],yw[size],Rs;
    int n,n2,year,uroll;
    printf("\nenter the number of students \n");
    scanf("%d",&n);
    read_info(s,n);
    print_info(s,n);
    printf("\n\nenter  the year for list of students\t");
    scanf("%d",&year);
    year_wise_struct(&yw,s,n,&n2,year);
    printf("\n\nstudents joined in the year %d",year);
    print_info(yw,n2);
    printf("\n\nenter roll no of the student to be found\t");
    scanf("%d",&uroll);
    search_roll(s,uroll,n,&Rs);
    print_only(Rs);
}
