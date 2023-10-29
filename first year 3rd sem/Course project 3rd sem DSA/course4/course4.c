#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#define VERT 27  // defining the number of vertices (currently)
#define INF 9999  // INF as in INFINITY

struct hotel
{
    char name[50];
    float ratings;
    char addr[20];
    int price;
};

struct place {
    int numb;
    char name[20];
    struct place * next;
};
/// A user-defined data type called PLACE to store the city names in singly linked list
typedef struct place * PLACENODE;


struct flight_details
{
    char flname[30];
    int price;
    int seats;
    char place[30];
};
typedef struct flight_details * FLIGHTNODE;

struct hotel_tree_form
{
    struct hotel_tree_form *l;
    struct hotel_tree_form *r;
    float rat;
    char name[100];
    char add[100];
    int price;
};
typedef struct hotel_tree_form * HOTELNODEE;

// struct NODE = struct flight_details

// global declarations
PLACENODE place_head=NULL;
struct hotel hot_details[100];
int roadway[VERT][VERT], FWroad[VERT][VERT];
struct flight_details flights[100];
struct hotel h[100];


void near_hotels(char d[]);
void read_road_dist(int roadway[VERT][VERT]);  // to read roadway array if given input
void read_road_from_file(int arr[VERT][VERT]);  // reads the distance between connected cities (graph) from existing file "road27.txt"
void print_2d_array(int a[VERT][VERT]);  // to print a 2d array
void floydWarshall(int arr[VERT][VERT]); // to floyd-warshall an adjacency matrix of a graph
void near_hotels(char d[]);  // to print particular place hotels
PLACENODE read_city_names(PLACENODE head); // to read places from a file city27 into a linked list
void display_places(PLACENODE head); // to display all places available in our system
void selection_sort(int n,struct flight_details a[]);     //function call for sorting rating less to max
HOTELNODEE create(char namee[],float data,char addr[],int roka);   //function call for sorting rating less to max
void insert(HOTELNODEE root,char name[],float data,char addr[],int roka);
void inorder(HOTELNODEE root);
void read_allhotels(struct hotel A[100]);      // to read hotel names from a file "hotel.txt" into a struct array hot_details
void airways(int p,int q,struct flight_details flights[100]);


int main()
{
    printf("                                       WELCOME\n");
    printf("                          Namaste :)                   HOLA!!!!\n\n");
    char s[20],d[20];
    float r[30],o[30];
    int n=100, i, j, choice=0, source_city=0, dest_city=0, flag=1;
    PLACENODE cur;
    HOTELNODEE hotel_root = NULL;

    // Storing all the destinations into an array
    // The function is just to separate the input form the code
    place_head = read_city_names(place_head);

    // Array-"roadway" stores the distance between connected cities
    // The function is just to separate the input form the code
    read_road_from_file(roadway);

    // To find the shortest distance between all the nodes, we are using
    // Floyd-Warshall Algorithm.
    // It finds the shortest distance between all the nodes
    floydWarshall(FWroad);

    // to read hotel names from a file "hotel.txt" into a struct array hot_details
    read_allhotels(hot_details);



    while(choice!=100)
    {
        printf("\n\nWhat do you want to know?");
        printf("\n1. Hotels in a city\n2. Distance between source and destination \n3. Display shortest distance between all the current available cities \n");
        printf("4. Display available destination list \n5.High Rated Hotels on our page\n6.Airways \nChoose what you wish for :) \n>>> ");

        scanf("%d",&choice);
        switch(choice)
        {
            case 1: flag = 1;
                    // while loop makes sure that you enter the city name among the given names
                    // Therefore, it's a "testing when running" "while loop"
                    while(flag!=0)
                    {
                        printf("\nEnter city:  ");
                        scanf("%s",d);
                        printf("\n%s",strupr(d));
                        for(cur=place_head, flag=1 ; cur!=NULL ; cur=cur->next)
                        {
                            if(strcmp(strupr(d),cur->name)==0)
                            {
                                dest_city=cur->numb;
                                flag=0;
                                break;
                            }
                        }

                        if(flag!=0)
                            printf("\nIncorrect city!!!  Please enter again");
                    }

                    printf("Nice choice of city\n");
                    near_hotels(d);
                    break;

            case 2: // "testing when running" "while loop"
                    flag = 1;
                    while(flag!=0)
                    {
                        printf("\nEnter source:  ");
                        scanf("%s",s);

                        for(cur=place_head, flag=1 ; cur!=NULL ; cur=cur->next)
                        {
                            if(strcmp(strupr(s),cur->name)==0)
                            {
                                source_city=cur->numb;
                                flag=0;
                                break;
                            }
                        }

                        if(flag!=0)
                            printf("\n\nIncorrect source!!!  Please enter again\n\n");
                    }

                    // "testing when running" "while loop"
                    flag = 1;
                    while(flag!=0)
                    {
                        printf("Enter destination:  ");
                        scanf("%s",d);
                        for(cur=place_head, flag=1 ; cur!=NULL ; cur=cur->next)
                        {
                            if(strcmp(strupr(d),cur->name)==0)
                            {
                                dest_city=cur->numb;
                                flag=0;
                                break;
                            }
                        }

                        if(flag!=0)
                            printf("\n\nIncorrect destination!!!  Please enter again.\n\n");

                        if(strcmp(d,s)==0)
                        {
                            printf("\nSource and destination are SAME!!! Please enter different destination.\n\n");
                            flag = 1;
                        }
                    }

                    printf("\nHmmmm.... Trip planning???\n\nDistance between %s and %s is %d\n", s, d, FWroad[source_city][dest_city]);
                    break;

            case 3: printf("\nprint_2d_array() Floyd-Warshall table:\n");
                    print_2d_array(FWroad);
                    break;

            case 4: printf("\nAvailable destinations to choose from:");
                    display_places(place_head);
                    break;

            case 6: // "testing when running" "while loop"
                    flag = 1;
                    while(flag!=0)
                    {
                        printf("\nEnter source:  ");
                        scanf("%s",s);

                        for(cur=place_head, flag=1 ; cur!=NULL ; cur=cur->next)
                        {
                            if(strcmp(strupr(s),cur->name)==0)
                            {
                                source_city=cur->numb;
                                flag=0;
                                break;
                            }
                        }

                        if(flag!=0)
                            printf("\n\nIncorrect source!!!  Please enter again\n\n");
                    }

                    // "testing when running" "while loop"
                    flag = 1;
                    while(flag!=0)
                    {
                        printf("Enter destination:  ");
                        scanf("%s",d);
                        for(cur=place_head, flag=1 ; cur!=NULL ; cur=cur->next)
                        {
                            if(strcmp(strupr(d),cur->name)==0)
                            {
                                dest_city=cur->numb;
                                flag=0;
                                break;
                            }
                        }

                        if(flag!=0)
                            printf("\n\nIncorrect destination!!!  Please enter again.\n\n");

                        if(strcmp(d,s)==0)
                        {
                            printf("\nSource and destination are SAME!!! Please enter different destination.\n\n");
                            flag = 1;
                        }
                    }
                    airways(source_city,dest_city,flights);
                    break;

            case 5: hotel_root=create(hot_details[1].name ,hot_details[1].ratings,hot_details[1].addr,hot_details[1].price);    //function call for sorting rating less to max
                    for(int l=2;l<=30;l++)
                        insert(hotel_root,hot_details[l].name,hot_details[l].ratings,hot_details[l].addr,hot_details[l].price);
                    inorder(hotel_root);
                    break;

            default: printf("choice unavailable :)");
        }
    }
    printf("\n");
    return 0;
}


// floyd-warshall algorithm for shortest distance between all the points
void floydWarshall(int arr[VERT][VERT])
{
      int graph[VERT][VERT], i, j, k;
      // function-call to read the road distance values into arr[][] array
      read_road_from_file(arr);
      // making all zeroes as 9999 (here, equivalent to INFINITY)
      for(i=1 ; i<=VERT ; i++)
      {
          for(j=1 ; j<=VERT ; j++)
          {
              if(arr[i][j]==0)
                  arr[i][j]=INF;
          }
          arr[i][i]=0;
      }

      // Adding vertices individually
      for (k = 1; k <= VERT; k++)
      {
        for (i = 1; i <= VERT; i++)
        {
            for (j = 1; j <= VERT; j++)
            {
                if (arr[i][k] + arr[k][j] < arr[i][j])
                    arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
      }

      return;
}

// near_hotels function reads the hotel information from existing file of hotel.txt
// hotel.txt holds the information of hotels like- their name, city they are in, their ratings and 24 hour pricing
void near_hotels(char d[])
{
    FILE*fp1;
    fp1=fopen("hotel.txt","r");
    printf("Hotel\t\tRating\t\tPrice(24hr)\n");
    for(int i=1;i<=30;i++)
    {
        fscanf(fp1,"%s %f %s %d", hot_details[i].name, &hot_details[i].ratings, hot_details[i].addr, &hot_details[i].price);

        if(strcmp(hot_details[i].addr,d)==0)
             printf("%-10s\t%-12.1f\t%10d\n", hot_details[i].name, hot_details[i].ratings, hot_details[i].price);
    }
    fclose(fp1);
    return;
}

// Function to allocate memory dynamically using malloc() function
// memory size for one contains
PLACENODE read_city_names(PLACENODE head)
{
    FILE*fp1;
    int i, j;
    PLACENODE newnode, cur;

    fp1=fopen("visit_places.txt","r");

    head=(PLACENODE)malloc(sizeof(struct place));
    head->numb=1;
    fscanf(fp1,"%s",head->name);
    cur=head;

    for(i=2;i<=VERT;i++)
    {
        newnode=(PLACENODE)malloc(sizeof(struct place));
        newnode->next=NULL;
        newnode->numb=i;
        fscanf(fp1,"%s ",newnode->name);
        cur->next=newnode;
        cur=cur->next;
    }
    fclose(fp1);
    return head;
}

// to display (traverse) all elements of the list
void display_places(PLACENODE head)
{
    PLACENODE cur;
    cur=head;
    if(head==NULL)
        printf("EMPTY LIST");
    else
    {
        while(cur!=NULL)
        {
             printf("\n%d. %s",cur->numb, cur->name);
             cur=cur->next;
        }
    }
    return;
}

/*
Input function to read distance between connected places (By road)
void read_road_dist(int roadway[VERT][VERT]){
    int i,j;
    printf("Enter the distance\n");
    for(i=1;i<=VERT;i++)
    {
        for(j=1;j<=VERT;j++)
            scanf("%d",&roadway[i][j]);
    }
    return;
}
*/

// read_road_from_file function, reads the distance between connected cities from existing file "road27.txt"
// road27.txt hold the adjacency matrix of the road-graph
void read_road_from_file(int arr[VERT][VERT])
{
    FILE*fp1;
    int i, j;
    fp1=fopen("road27.txt","r");
    for(i=1;i<=VERT;i++)
        for(j=1;j<=VERT;j++)
            fscanf(fp1,"%d ",&arr[i][j]);
    fclose(fp1);
    return;
}

void print_2d_array(int a[VERT][VERT])
{
    int i, j;
    printf("\n\n");
    for(i=1 ; i<=VERT ; i++)
    {
        printf("\n");
        for(j=1 ; j<=VERT ; j++)
            printf("%d\t",a[i][j]);
    }
    return;
}

void selection_sort(int n,struct flight_details a[])
{
    int i,min,j;
    struct flight_details temp;
    printf("\n%s", a[10].flname);

    for(i=1;i<n-1;i++)
    {
        int min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j].price<a[min].price)
                min=j;
        }

        if(min!=i)
        {
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }

    printf("Flight Name\tSeats_Avalable\n");
    for(i=1;i<n;i++)
        printf("%-10s\t%-14d\t%8d\n",a[i].flname,a[i].price,a[i].seats);

    return;
}


HOTELNODEE create(char namee[],float data,char addr[],int roka)
{
    HOTELNODEE newnode=(HOTELNODEE)malloc(sizeof(struct hotel_tree_form));
    newnode->rat=data;
    newnode->price=roka;
    strcpy(newnode->name,namee);
    strcpy(newnode->add,addr);
    newnode->r=NULL;
    newnode->l=NULL;
    return newnode;
}

void insert(HOTELNODEE root,char name[],float data,char addr[],int roka)
{
    HOTELNODEE prev=NULL;
    while(root!=NULL)
    {
        prev=root;
        if(data<root->rat)
            root=root->l;

        else
            root=root->r;
    }

    HOTELNODEE newnode=create(name,data,addr,roka);

    if(data<prev->rat)
        prev->l=newnode;

    else
        prev->r=newnode;
    return;
}

void inorder(HOTELNODEE root)
{
    int i=1;
    if(root!=NULL)
    {
        inorder(root->r);
        printf("%-10s\t%-12.01f\t%8s\t%10d\n",root->name,root->rat,root->add,root->price);
        inorder(root->l);
    }
    return;
}


void airways(int p,int q,struct flight_details flights[100])
{
    printf("\nCurrently Running Flights\n");
    FILE* fp1;
    fp1=fopen("flight.txt","r");
    printf("Flight\tPrice\tSeats_Avalable\n");
    for(int i=1;i<=10;i++)
    {
        fscanf(fp1,"%s %d %d",flights[i].flname,&flights[i].price,&flights[i].seats);
        printf("%-10s\t%-14d\t%8d\n",flights[i].flname, flights[i].price, flights[i].seats);
    }
    fclose(fp1);
    printf("\n");
    printf("Flight details cheapest to costliest\n");
    selection_sort(11,flights);
    printf("\n");
    printf("Shortest distance between source and destination through airways\n");
    return;
}

// function to read all the hotel details into structure array A (from main, globally declared hot_details)
void read_allhotels(struct hotel A[100])
{
    FILE*fp1;
    fp1=fopen("hotel.txt","r");
    for(int i=1;i<=30;i++)
        fscanf(fp1,"%s %f %s %d", A[i].name, &A[i].ratings, A[i].addr, &A[i].price);

    fclose(fp1);
    return;
}
