#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

    int i, j, k;
    int minimum, minweight = 0, weight[9][9], parent[9];

    int find(int);
    int uni(int, int);

    int a, b, u, v, n, index = 1;
    void main() 
    {
      printf("\nno. of vertices:");
      scanf("%d", &n);
      printf("\nweight adjacency:\n");
      for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
          scanf("%d", &weight[i][j]);
          if (weight[i][j] == -1)
            weight[i][j] = 999;
        }
      }
      printf("\nedges:\n");
      while (index < n) 
      {
        for (i = 1, minimum = 999; i <= n; i++) 
        {
          for (j = 1; j <= n; j++) 
          {
            if (weight[i][j] < minimum) 
            {
              minimum = weight[i][j];
              a = u = i;
              b = v = j;
            }
          }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v)) {
          printf("%d  :  %d --- %d \n", minimum, a, b);
          index++;
          minweight += minimum;
        }
        weight[a][b] = weight[b][a] = 999;
      }
      printf("\n\tMinimum weight = %d\n", minweight);
      getch();
    }

    int find(int i)
    {
      while(parent[i])
        i = parent[i];
      return i;
    }

    int uni(int i, int j)
    {
      if (i!=j)
      {
        parent[j] = i;
        return 1;
      }
      return 0;
    }

    /*
4
    -1 2 2 1 -1 -1
    2 -1 -1  2 1 -1
    2 -1 -1 -1 -1 3
    1 2 -1 -1 2 3
    -1 1 -1 2 -1 1
    -1 -1 3 3 1 -1
      
    */