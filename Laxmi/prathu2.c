#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Node
{
    int data;
    struct Node *link;
};

typedef struct Node *node;

node sorting(node first);
node createNode();
node insert_rear(node first);
void display_list(node first);

node createNode()
{
    node t;

    int ele;
    t = malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("not created\n");
        exit(0);
    }
    printf("element to be inserted\n");
    scanf("%d", &ele);

    t->data = ele;
    t->link = NULL;

    return t;
}

void display_list(node first)
{
    node t;
    FILE *fp1;
    fp1 = fopen("mitu.txt", "w+");
    if (first == NULL)
    {
        printf("empty list\n");
        return;
    }

    t = first;
    while (t != NULL)
    {

        printf("%d \n", t->data);

        t = t->link;
    }
    while (t != NULL)
    {
        fscanf(fp1, "%d", t->data);
        t = t->link;
    }
    printf("\n");
}

node insert_rear(node first)
{
    node t, c;
    t = createNode();
    if (first == NULL)
        return t;

    c = first;
    while (c->link != NULL)
    {
        c = c->link;
    }
    c->link = t;

    return first;
}

node sorting(node first)
{
    node t = first, cur = NULL;
    int temp;
    if (first == NULL)
    {
        return (0);
    }
    else
    {
        while (t != NULL)
        {
            cur = t->link;
            while (cur != NULL)
            {
                if (t->data > cur->data)
                {
                    temp = t->data;
                    t->data = cur->data;
                    cur->data = temp;
                }
                cur = cur->link;
            }
            t = t->link;
        }
    }
    return (first);
}

int main()
{
    node first = NULL;
    int choice, n;
    FILE *fp1, *fp2;
    
    fp1 = fopen("unsorted_input.txt", "w");
    fp2 = fopen("sorted_output.txt", "w");

    printf("enter the value of n\n");
    scanf("%d", &n);
    for (;;)
    {
        printf("1->insert rear\n 2->display\n 3->sort\n 4->exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                first = insert_rear(first);
                fprintf(fp1, "%d\n", first->data);
                printf("%d\n", first->data);
            }

            break;
        case 2:
            printf("Display list inserted\n");
            display_list(first);
            break;
        case 3:
            first = sorting(first);
            break;
        case 4:
            exit(0);
        }
    }
    fclose(fp1);
    return 0;
}