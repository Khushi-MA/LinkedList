#include <stdio.h>
#include <string.h>

typedef struct visitor_info
{
    char name[20];
    char nat;
    int age;
    char mn[15];
} VIS;

void read_visitors(VIS *p, int n)
{
    int i;
    printf("\nEnter the information of the visitors:\n");
    for (i = 0; i < n; i++, p++)
    {
        //printf("Name: ");
        scanf("%s", p->name);

        //printf("Nationality of the visitor (N for national, I for international): ");
        getchar();
        scanf(" %c", &p->nat);

        //printf("Age: ");
        scanf("%d", &p->age);

        //printf("Museum name: ");
        scanf("%s", p->mn);
    }
}

void display_visitor(VIS *visitor)
{
    printf("Name: %s\n", visitor->name);
    printf("Nationality: %c\n", visitor->nat);
    printf("Age: %d\n", visitor->age);
    printf("Museum name: %s\n", visitor->mn);
}

void display_visitors(VIS *p, int n)
{
    int i;
    printf("\n\nvisitors are:");
    printf("\ns.no\tname\tnat\tage\tmus.name");
    for (i = 0; i < n; i++, p++)
    {
        printf("\n%d.\t%s\t%c\t%d\t%s", (1 + i), p->name, p->nat, p->age, p->mn);
    }
}

int school_count(VIS *p, int n)
{
    int i, count = 0;

    for (i = 0; i < n; i++, p++)
    {
        if (p->age >= 3 && p->age <= 17)
        {
            count++;
        }
    }
    return count;
}

int nationality_count(VIS *p, int n)
{
    int i, count = 0;

    for (i = 0; i < n; i++, p++)
    {
        if (p->nat == 'I' || p->nat == 'i')
        {
            count++;
        }
    }
    return count;
}

void filter_by_museum(VIS *p, int n)
{
    char museum_name[15];
    int found = 0;

    printf("Enter the museum name to filter visitors: ");
    scanf("%s", museum_name);

    printf("\nVisitors in museum %s:\n", museum_name);

    for (int i = 0; i < n; i++, p++)
    {
        if (strcasecmp(p->mn, museum_name) == 0)
        {
            display_visitor(p);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No visitors found for museum %s.\n", museum_name);
    }
}

int main()
{
    VIS v[500];
    int n;
    int school_children_count, international_visitor_count;
    int choice;

    printf("Enter the total number of visitors: ");
    scanf("%d", &n);

    read_visitors(v, n);

    do
    {
        printf("\nMENU:\n");
        printf("1. Display all visitors\n");
        printf("2. Count school children\n");
        printf("3. Count international visitors\n");
        printf("4. Filter visitors by museum\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            display_visitors(v, n);
            break;

        case 2:
            school_children_count = school_count(v, n);
            printf("The number of school children visiting is %d\n", school_children_count);
            break;

        case 3:
            international_visitor_count = nationality_count(v, n);
            printf("The number of international visitors is %d\n", international_visitor_count);
            break;

        case 4:
            filter_by_museum(v, n);
            break;

        case 5:
            printf("Exiting the program. Goodbye!\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }
    } while (choice != 5);

    return 0;
}
