#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define MAX_LEN 100
#define VERT 10  // defining the number of vertices (currently)
#define INF 9999  // INF as in INFINITY

struct hotel
{
    char name[50];
    float rating;
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


struct cityname
{
    char name[20];
};

/**
 struct flight_details
{
    char flname[30];
    int price;
    int seats;
    char place[30];
};
typedef struct flight_details * FLIGHTNODE;
*/

struct flight_details         ///airway structure
{
    char name[30];
    int price;
    int seats;
    char des[30];
};
typedef struct flight_details * FLIGHTNODE;

struct roam      ///structure to roam
{
    char place[30];
    int km;
    char loc[30];
};

struct stacking_structure
{
    char data[MAX_LEN];
    struct StackNode* next;
};
typedef struct stacking_structure StackNode;

// global declarations
PLACENODE place_head=NULL;
struct hotel hot_details[100];
int roadway[VERT][VERT], FWroad[VERT][VERT], longroute[27][27];
struct flight_details flights[100];
// struct hotel h[100];
int q[100],front=-1,rear=-1, vis[50];
struct cityname cityy[50], morecities[50];
int air[VERT][VERT];
struct roam roam[100];


void near_hotels(char d[]);
void read_road_dist(int roadway[VERT][VERT]);  // to read roadway array if given input
void read_road_from_file(int arr[VERT][VERT]);  // reads the distance between connected cities (graph) from existing file "road10.txt"
void print_2d_array(int a[VERT][VERT]);  // to print a 2d array
void floydWarshall(int arr[VERT][VERT]); // to floyd-warshall an adjacency matrix of a graph
void near_hotels(char d[]);  // to print particular place hotels
PLACENODE read_city_names(PLACENODE head); // to read places from a file city27 into a linked list
void display_places(PLACENODE head); // to display all places available in our system
void displaycityarr(struct cityname cityy[50]); // to display array form (later done) all places available in our system
void airways(int p,int q,struct flight_details flights[],char d[]);       //function call for sorting rating less to max
HOTELNODEE create(char namee[],float data,char addr[],int roka);   //function call for sorting rating less to max
void insert(HOTELNODEE root,char name[],float data,char addr[],int roka);
void inorder(HOTELNODEE root);
void read_allhotels(struct hotel A[100]);      // to read hotel names from a file "hotel.txt" into a struct array hot_details
void selection_sort(int n,struct flight_details a[], char d[]);

// DFS, we might traverse through more edges to reach a destination vertex from a source.
// BFS can be used to find a single source shortest path in an unweighted graph because, in BFS, we reach a vertex with a minimum number of edges from a source vertex.
void bfs(int s,int n, int arr[28][28]);
void add(int item); // enqueue
int delete();       // dequeue
//void dfs(int s,int n);

void read_arr_city_names(struct cityname A[50]);
void readmorecities(struct cityname A[50]);

void printSolution( int n, int dist[n]);

void flightdijikstra(int a[10][10], int n, int s,int q);
void hotel_rating(char d[],struct hotel z[]);
void places_roam(char d[],struct roam roam[]);
StackNode* push(StackNode* top, char* data);
StackNode* pop(StackNode* top) ;
void history(StackNode* top);
// void dijikstra(int a[10][10], int n, int s,int q);
void roaddijkstra(int ver, int graph[ver][ver], int src);
void dijikstra(int a[10][10], int n, int s,int q);


int main()
{
    printf("                                       WELCOME\n");
    printf("                          Namaste :)                   HOLA!!!!\n\n\n");
    char s[20],d[20];
    float r[30],o[30];
    int n=100, i, j, k, choice=0, source_city=0, dest_city=0, flag=1;
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

    // read the cities in "city27.txt"
    read_arr_city_names(cityy);
    readmorecities(morecities);
    printf("\nThese are our available destinations!!!!\n");
    displaycityarr(cityy);

    /************************************************8OOOOOOOOOOOOOOOOOOOOOOOOOOO______________________________****/

    // "testing when running" "while loop"

                    flag = 1;
                    while(flag!=0)
                    {
                        printf("\n\nWhere do you wanna start your journey from?\n");
                        scanf("%s",s);

                        for(cur=place_head, flag=1 ; cur!=NULL ; cur=cur->next)
                        {
                            if(strcasecmp(s,cur->name)==0)
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
                        printf("\nwhat's your destination?\n");
                        scanf("%s",d);
                        for(cur=place_head, flag=1 ; cur!=NULL ; cur=cur->next)
                        {
                            if(strcasecmp(d,cur->name)==0)
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
    printf("\n%d = %s : %d = %s",source_city, cityy[source_city].name, dest_city, cityy[dest_city].name);


    /***********************************OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO****/

    while(choice!=100)
    {
        /************file**************/
        FILE * file;
        file = fopen("search_history.txt","a");
        fprintf(file,"%s %s\n",cityy[source_city].name,cityy[dest_city].name);
        fclose(file);
        StackNode * top = NULL;
        char buffer[MAX_LEN];
        file = fopen("search_history.txt", "r");

        if (file == NULL)
        {
            printf("Error: Could not open file\n");
            return 1;
        }

        while (fgets (buffer, MAX_LEN, file) != NULL)
        {
            int len = strlen(buffer);
            if (buffer[len - 1] == '\n')
            {
                buffer[len - 1] = '\0';
            }
            top = push(top, buffer);
        }

        fclose(file);
        printf("\n\nWhat do you want to know?\n");
        printf("1: Best Hotels near %s\n",d);
        printf("2: High Rated Hotels on our page\n");
        printf("3: Attraction near/around %s\n",d);
        printf("4: Wanna travel by PLANE? see distance through Airway travel\n");
        printf("5: Checkout Flights Flying to %s\n",d);

        printf("\nAre you a long drive person? then-\n");
        printf("8. See the distance between source and destination \n");
        printf("9. Check the distance of all other destinations from source point\n");

        printf("\nBut, you are a looooooooooooong drive person? and want to travel from north to south?\n");
        printf("10. Show a large roadway plan from north to south\n");

        printf("11. Show the available cities\n");
        printf("12. would you like to switch source and destination\n");

        printf("13: Look what you Searched for\n");

        printf("");
        printf("");
        printf("\nChoose what you wish for :) \n>>>");

        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\n\nBTW...Nice choice of city\n");
                    near_hotels(d);
                    break;

            case 2: printf("\nHotels from highest to lowest rating\n");
                    hotel_root=create(hot_details[1].name ,hot_details[1].rating,hot_details[1].addr,hot_details[1].price);    //function call for sorting rating less to max
                    for(int l=2;l<=30;l++)
                        insert(hotel_root,hot_details[l].name,hot_details[l].rating,hot_details[l].addr,hot_details[l].price);

                    inorder(hotel_root);
                    break;

            case 3: places_roam(d,roam);
                    break;

            case 4: printf("\nflightdijikstra, %d %d \n\n", source_city, dest_city);
                    dijikstra(air,VERT,source_city,dest_city);
                    break;

            case 5: airways(source_city,dest_city,flights,d);
                    break;

            case 8: printf("\nDistance between %s and %s is %d\n", s, d, FWroad[source_city][dest_city]);
                    break;

            case 9: // Function call for dihikstra
                    roaddijkstra(VERT, roadway, source_city);
                    break;

            case 10: read_road_from_file(longroute);

                    printf("\nBFS-ing the roadway");
                    bfs(source_city, VERT , longroute);
                    break;

            case 11: printf("\nShow Available destinations to choose from:");
                    displaycityarr(cityy);
                    break;

            case 12: break;

            case 13: history(top);                 ///
                   break;

            case 50: printf("\nThe Floyd-Warshall table:\n");
                    print_2d_array(FWroad);
                    break;

            default: printf("choice unavailable :)");
                    break;
            case 100: exit(0);
        }
    }
    printf("\n");
    //return 0;
}

// (array formT) to display the places/cities in our system
void displaycityarr(struct cityname cityy[50])
{
    int i;
    for(i=1;i<=VERT;i++)
        printf("\n%d. %s",i, cityy[i].name);

    return;
}

//************BFS(breadth-frst search) code************//
void bfs(int s,int n, int arr[28][28])
{
      int p,i, count=0;
      add(s);
      vis[s]=1;
      p = delete();
      if(p!=0)
        printf("\n%d. %d- %s ",++count, p, morecities[p].name);

      while(p!=0)
      {
        for(i=1;i<=n;i++)
        {

            if((arr[p][i]!=0)&&(vis[i]==0))
               {
                  add(i);
                  vis[i]=1;
               }
        }

        p=delete();

        if(p!=0)
            printf("\n%d. %d- %s ",++count, p, cityy[p].name);
      }

      for(i=1;i<=n;i++)
      {
         if(vis[i]==0)
            bfs(i, n, arr);
      }
      return;
}


void add(int item)
{
    if(rear==99)
        printf("\nQUEUE FULL");
    else
    {
        if(rear==-1)
        {
            q[++rear]=item;
            front++;
        }
        else
            q[++rear]=item;
    }
}

int delete()
{
    int k;
    if((front>rear)||(front==-1))
        return(0);
    else
    {
        k=q[front++];
        return(k);
    }
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
        fscanf(fp1,"%s %f %s %d", hot_details[i].name, &hot_details[i].rating, hot_details[i].addr, &hot_details[i].price);

        if(strcasecmp(hot_details[i].addr,d)==0)
             printf("%-10s\t%-12.1f\t%10d\n", hot_details[i].name, hot_details[i].rating, hot_details[i].price);
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

    fp1=fopen("city.txt","r");

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

void read_arr_city_names(struct cityname A[50])
{
    FILE*fp1;
    int i;

    fp1=fopen("city10.txt","r");

    for(i=1;i<=VERT;i++)
        fscanf(fp1,"%s", A[i].name );

    fclose(fp1);
    return;
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


// read_road_from_file function, reads the distance between connected cities from existing file "road10.txt"
// road10.txt hold the adjacency matrix of the road-graph
void read_road_from_file(int arr[VERT][VERT])
{
    FILE*fp1;
    int i, j;
    fp1=fopen("road10.txt","r");
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

void selection_sort(int n,struct flight_details a[], char d[])
{
    int i,j;
    struct flight_details temp;
    for(i=1;i<=n-1;i++)
    {
        int min=i;
        for(j=i+1;j<=n;j++)
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
        printf("%-10s\t%-14d\t%8d\n",a[i].name,a[i].price,a[i].seats);
    printf("from %s:\n",d);

    for(i=1;i<n;i++)
    {
        if(strcasecmp(d,a[i].des)==0)
        printf("%-10s\t%-14d\t%8d\n",a[i].name,a[i].price,a[i].seats);
    }

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

// function to read all the hotel details into structure array A (from main, globally declared hot_details)
void read_allhotels(struct hotel A[100])
{
    FILE*fp1;
    fp1=fopen("hotel.txt","r");
    for(int i=1;i<=30;i++)
        fscanf(fp1,"%s %f %s %d", A[i].name, &A[i].rating, A[i].addr, &A[i].price);

    fclose(fp1);
    return;
}

// C program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graph

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int n, int dist[], bool sptSet[])
{
	// Initialize min value
	int min_index, min = INT_MAX;

	for (int v = 0; v < n; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance array
void printSolution( int n, int dist[n])
{
	printf("City \t\t Distance from initial point\n");
	for (int i = 1; i <= n; i++)
		printf("%d. %s \t\t\t\t %d\n", i,cityy[i].name, dist[i]);
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void roaddijkstra(int ver, int graph[ver][ver], int src)
{
    int dist[ver]; // The output array.  dist[i] will hold the
                 // shortest
    // distance from src to i

    bool sptSet[ver]; // sptSet[i] will be true if vertex i is
                    // included in shortest
    // path tree or shortest distance from src to i is
    // finalized

    // Initialize all distances as INFINITE and stpSet[] as
    // false
    for (int i = 1; i <= ver; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < ver - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(ver, dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 1; v <= ver; v++)

            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printSolution(30, dist);
    return;
}


void airways(int p,int q,struct flight_details flights[],char d[])                              ///flights to your destination
{

    printf("\nCurrently Running Flights to in our service \n");
    FILE* fp1;
    fp1=fopen("flight.txt","r");
    printf("Flight\tPrice\tSeats_Avalable\n");
    for(int i=1;i<=20;i++)
    {
        fscanf(fp1,"%s %d %d %s",flights[i].name,&flights[i].price,&flights[i].seats,flights[i].des);
        printf("%-10s\t%-14d\t%8d\t%s\n",flights[i].name, flights[i].price, flights[i].seats, flights[i].des);
    }
    fclose(fp1);
    printf("\n");
    printf("Flight details cheapest to costliest to %s\n",d);           ///.....................
    selection_sort(20,flights,d);
    return;
}

void hotel_rating(char d[],struct hotel z[])
{
    FILE* fp1;
    fp1=fopen("hotel.txt","r");
    for(int i=1;i<=30;i++)
    {
        fscanf(fp1,"%s %f %s %d",z[i].name,&z[i].rating,z[i].addr,&z[i].price);
    }
    fclose(fp1);
}

void places_roam(char d[],struct roam roam[])             ///search plces nearby
{
    int i=1;
    FILE* fp1;
    fp1=fopen("roam.txt","r");
    for(int i=1;i<=200;i++)
    {
        fscanf(fp1,"%s %d %s",roam[i].place,&roam[i].km,roam[i].loc);
        i++;
    }
    printf("\n");
    //printf("Hotels in %s\n",d);
    printf("Places to roam                Distance(in kms)  Location\n ");
    for(int i=1;i<=100;i++)
    {
        if(strcasecmp(roam[i].loc,d)==0)
        {
            printf("%-29s\t%-12.01d\t%8s\n",roam[i].place,roam[i].km,roam[i].loc);
        }
    }
    fclose(fp1);
}

StackNode* push(StackNode* top, char* data)
{
    StackNode* new_node = malloc(sizeof(StackNode));
    strcpy(new_node->data, data);
    new_node->next = top;
    return new_node;
}

StackNode* pop(StackNode* top)
{
    if (top == NULL) {
        return NULL;
    }
    StackNode* temp = top;
    top = top->next;
    free(temp);
    return top;
}


void history(StackNode * top)
{
    printf("\nSearch history:\n");
    while (top != NULL)
    {
        printf("%s\n", top->data);
        top = top->next;
    }
    return;
}

void dijikstra(int a[10][10], int n, int s,int q)
{
    int i,j;
    FILE* fp1;
    fp1=fopen("distance_air.txt","r");
	for(i=0;i<10;i++)
    {
		for(j=0;j<10;j++)
        {
			fscanf(fp1,"%d",&a[i][j]);
        }
    }
	int cost[10][10], distance[10], path[10];
	int visited[10], count, min, u;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i][j]==0)
				cost[i][j]=999;
			else
				cost[i][j]=a[i][j];

	for(i=0;i<n;i++)
	{
		distance[i]=cost[s][i];
		path[i]=s;
		visited[i]=0;
	}
	distance[s]=0;
	visited[s]=1;
	count=1;
	while(count < n-1){
		min=999;
		for(i=0;i < n;i++)
			if(distance[i] < min&&!visited[i])
			{
				min=distance[i];
				u=i;
			}
		visited[u]=1;
		for(i=0;i < n;i++)
			if(!visited[i])
				if(min+cost[u][i] < distance[i])
				{
					distance[i]=min+cost[u][i];
					path[i]=u;
				}
			count++;
	}

	for(i=0;i<n;i++)
    {

		if(i!=s && i==q)
		{
			printf("\nDistance between %s and %s = %d  \t", cityy[s].name,cityy[i].name ,distance[i]);
			printf("Path = %s", cityy[i].name);
			j=i;
			do
			{
				j=path[j];
				printf("<-%s", cityy[j].name);
			}
			while(j!=s);
		}
    }
    printf("\n");
    return;
}


/*

void flightdijikstra(int air[10][10], int n, int s,int q)
{
	int i,j;
    FILE* fp1;
    fp1=fopen("distance_air.txt","r");
	for(i=1;i<=10;i++)
    {
		for(j=1;j<=10;j++)
        {
			fscanf(fp1,"%d",&air[i][j]);
        }
    }
	int cost[10][10], distance[10], path[10];
	int visited[10], count, min, u;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(air[i][j]==0)
				cost[i][j]=999;
			else
				cost[i][j] = air[i][j];

	for(i=1;i<=n;i++)
	{
		distance[i]=cost[s][i];
		path[i]=s;
		visited[i]=0;
	}
	distance[s]=0;
	visited[s]=1;
	count=1;
	while(count <= n-1){
		min=999;
		for(i=1;i <= n;i++)
			if(distance[i] < min&&!visited[i])
			{
				min=distance[i];
				u=i;
			}
		visited[u]=1;
		for(i=1;i <= n;i++)
			if(!visited[i])
				if(min+cost[u][i] < distance[i])
				{
					distance[i]=min+cost[u][i];
					path[i]=u;
				}
			count++;
	}


	for(i=1;i<=n;i++)
    {
		if(i!=s && i==q)
		{
			printf("\nDistance between %s and %s = %d  \t", cityy[s].name,cityy[i].name ,distance[i]);
			printf("Path = %s", cityy[i].name);
			j=i;
			do
			{
				j=path[j];
				printf("<-%s", cityy[j].name);
			}
			while(j!=s);
		}
    }
    printf("\n");
    return;
}
*/

void readmorecities(struct cityname A[50])
{
    FILE*fp1;
    int i;

    fp1=fopen("city27.txt","r");

    for(i=1;i<=28;i++)
        fscanf(fp1,"%s", A[i].name );

    fclose(fp1);
    return;
}
