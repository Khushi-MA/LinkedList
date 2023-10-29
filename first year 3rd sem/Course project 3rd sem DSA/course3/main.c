#include "course3_header.h"

int main()
{
    int ;
    char s[20],d[20];
    int n=100, i, j;

    // storing all the destinations into an array
    // The function is just to separate the input form the code
    read_city_names(hot_details);
    int choice, source_city, dest_city, flag=1;

    // Array-"roadway" stores the distance between connected cities
    // The function is just to separate the input form the code
    read_road_dist(roadway);
    printf("roadway:  %d %d", roadway[3][2], roadway[10][5]);

    // To find the shortest distance between all the nodes, we are using
    // Floyd-Warshall Algorithm.
    // It finds the shortest distance between all the nodes
    floydWarshall(FWroad);

    printf("\nAvailable destinations to choose from:");
    for(i=1;i<15;i++)
        printf("\n%d. %s",i, cityy[i].name);

    printf("\n\nWhat do you want to know?");
    printf("\n1. Hotels in a city\n2. Distance between source and destination \n3. Display shortest distance between all the current available cities \n");
    printf("4. \n5. \nEnter choice:   ");

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
                    for(j=1, flag=1 ; j<=10 ; j++)
                    {
                        if(strcmp(d,cityy[j].name)==0)
                        {
                            dest_city=j;
                            flag=0;
                            break;
                        }
                    }

                    if(flag!=0)
                        printf("\nIncorrect city!!!  Please enter again");
                }

                printf("\nnear_hotels()\n");
                near_hotels(d);
                break;

        case 2: // "testing when running" "while loop"
                flag = 1;
                while(flag!=0)
                {
                    printf("\nEnter source:  ");
                    scanf("%s",s);

                    for(j=1, flag=1 ; j<=10 ; j++)
                    {
                        if(strcmp(s,cityy[j].name)==0)
                        {
                            source_city=j;
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
                    for(j=1, flag=1 ; j<=10 ; j++)
                    {
                        if(strcmp(d,cityy[j].name)==0)
                        {
                            dest_city=j;
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

                //printf("\nprint_2d_array() Floyd warshal in switch 2:\n");
            //print_2d_array(FWroad);

                printf("\nDistance between %s and %s is %d\n", s, d, FWroad[source_city][dest_city]);
                break;

        case 3: printf("\nprint_2d_array() Floyd-Warshall table:\n");
                print_2d_array(FWroad);
                break;

        case 4: printf("  yet done!");
                break;

        default: printf("choice unavailable :)");
    }
    printf("\n");
    return 0;
}

// floyd warshall for shortest distance between all the points
void floydWarshall(int arr[11][11])
{
      int graph[11][11], i, j, k;
      read_road_dist(graph);
      // making all zeroes as 9999 (here, equivalent to INFINITY)
      for(i=1;i<11;i++)
      {
          for(j=1;j<11;j++)
          {
              if(graph[i][j]==0)
              {
                  graph[i][j]=INF;
              }
          }
          graph[i][i]=0;
      }

      // copying (Our) graph array into (warshall's) matrix array
      for (i = 1; i < nV; i++)
        for (j = 1; j < nV; j++)
          arr[i][j] = graph[i][j];

      // Adding vertices individually
      for (k = 1; k < nV; k++)
      {
            for (i = 1; i < nV; i++)
            {
              for (j = 1; j < nV; j++)
              {
                if (arr[i][k] + arr[k][j] < arr[i][j])
                  arr[i][j] = arr[i][k] + arr[k][j];
              }
            }
      }

      printf("\nFloyd-Warshall road print_2d_array(arr)\n");
      print_2d_array(arr);
      return;
}



