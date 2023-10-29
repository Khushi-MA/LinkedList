/*
the code is written by KHUSHI M APPANNAVAR
of J division
roll no. 1013
*/

#include <stdio.h>
#include <string.h>

/// writing the structure
typedef struct visitor_info
{
    char name[20]; // name of the visitor
    char nat;      // nationality
    int age;       // age
    char mn[15];   // museum name
    int year;      // year of visit
} VIS;             // structure typedef as VIS

/// to read data
void read_visitors(VIS *p, int n)
{
    int i;
    printf("\nenter the information of the visitors:\n");
    for (i = 0; i < n; i++, p++)
    {
        printf("\nname\t");
        scanf("%s", p->name);

        printf("nationality of the visitor,\nN: national \nI: international\t");
        getchar();
        scanf("%c", &p->nat);

        printf("age\t");
        scanf("%d", &p->age);

        printf("museum name\t");
        scanf("%s", p->mn);

        printf("year of visit\t");
        scanf("%d", &p->year);
    }
    return;
}

/// display one by one
void display_visitors(VIS *p, int n)
{
    int i;
    printf("\ns.no\tname\tnationality\tage\tmus_name\tyear\t");
    for (i = 0; i < n; i++, p++)
    {
        printf("\n%d \nname:%s", (1 + i), p->name);
        printf("\nnationality:%c", p->nat);
        printf("\nage:%d", p->age);
        printf("\nmuseum name:%s", p->mn);
        printf("\nyear of est.:%d", p->year);
    }
    return;
}

/// tabular display
void display_visitors_2(VIS *p, int n)
{
    int i;
    printf("\n\nvisitors are:");
    printf("\ns.no \t name \t nationality \t age \t mus.name \t year");
    for (i = 0; i < n; i++, p++)
    {
        printf("\n%d \t %s \t %c \t \t %d \t %s \t %d \t", (1 + i), p->name, p->nat, p->age, p->mn, p->year);
    }
}

/// to count the number of school children (b/w age 3 and 17)
int school_count(VIS *p, int n)
{
    int i, count = 0;

    for (i = 0; i < n; i++, p++)
    {
        if (p->age < 17)
        {
            count++;
        }
    }
    return count;
}

/// to check the nationality
int nationality_count(VIS *p, int n)
{
    int i, count = 0;

    for (i = 0; i < n; i++)
    {
        if (p->nat == 'i')
        {
            count++;
        }
        p++;
    }
    return count;
}

/// to display according to museum name
void accord_name_museum(char um[15], VIS *p, int n)
{
    int i, j, k = 0;
    printf("\n\nvisitors in museum: %s", um);
    printf("\n s.no \t name \t nationality \t age \t mus_name \t year \t");
    for (i = 0; i < n; i++, p++)
    {
        if (strcmp(p->mn, um) == 0)
        {
            printf("\n %d \t %s \t %c \t \t %d \t %s \t %d \t", (1 + i), p->name, p->nat, p->age, p->mn, p->year);
            k = 1;
        }
    }
    if (k != 1)
        printf("\nNAME NOT FOUND");
    return;
}

int main()
{
    VIS v[500];
    int n;
    int sc, ic;  // sc = school children,  ic = international people count
    char um[15]; // unknown museum for visitor info

    printf("\nenter the total no. of visitors:  ");
    scanf("%d", &n);

    read_visitors(v, n);
    display_visitors(v, n);   // display one by one
    display_visitors_2(v, n); // display in tabular form

    printf("\n");
    // to count the number of school children (b/w age 3 and 17)
    sc = school_count(v, n);
    printf("\nthe number of school children visiting is %d", sc);

    // to check the nationality
    ic = nationality_count(v, n);
    printf("\nthe number of international visitors is %d", ic);

    // to display according to museum name
    printf("\nenter the name of museum for visitor info:  ");
    scanf("%s", um);
    accord_name_museum(um, v, n);
    return 0;
}
