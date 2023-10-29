#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
/*consider the student and perform the following program using trees.*/

struct student
{
    int usn;
    char name[10];
    int marks;
    float avg;
    char grade[2];
};

struct node
{
    struct student s;
    struct node *left,*right;
};
typedef struct node* NODE;


/*
Questions:
1.find and display all the student information,who have scored s grade
2.find and delete 'F' grade student information
3.find and display the number of students fall in each grade(s,a,b,c,d,e,f)
4.display the student information who have scored maximum average marks.
5.find and delete students who have withdrawn admission.

constraints:
1.use only one tree for implementation.
2.use usn as key for insertion.
3.do not modify struct student and node.
*/
