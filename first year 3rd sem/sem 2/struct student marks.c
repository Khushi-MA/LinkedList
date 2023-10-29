#include<stdio.h>
#include<math.h>
#include<string.h>
#include<strings.h>
#define ze 100

typedef struct student_marks
{
    char name;   // name of the student
    int roll;    // roll number of the student
    float marks[ze],sum;    // marks in five subjects and their sum
}stu;

int main()
{
    stu cla[ze];
    int n,m;
    float max;

    printf("\nenter the number of students");
    scanf("%d",&n);

    printf("Enter the number of subjects");
    scanf("%d",&m);



    read(cla, n, M);
    display(cla,n);
    first = max_sum(cla,n);
}
