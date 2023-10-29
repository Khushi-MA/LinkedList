#include <stdio.h>
#include <stdlib.h>

static int m[10][10];
static int visited[10];

void dfs(int m[10][10], int v, int source)
{
    visited[source] = 1;

    int i;

    for (i = 0; i <= v; i++)
    {
        if (m[source][i] == 1 && visited[i] == 0)
        {
            printf("%d\t", i);
            dfs(m, v, i);
        }
    }
}

void bfs(int m[10][10], int v, int source)
{
    int queue[20];
    int front = 0, rear = 0, u, i;

    int visited1[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    printf("\nThe BFS Traversal is:\n");

    queue[rear] = source;
    rear++;
    printf("%d\t", source);
    visited1[source] = 1;

    while (front < rear)
    {
        u = queue[front];
        front = front + 1;

        for (i = 0; i <= v; i++)
        {
            if (m[u][i] == 1 && visited1[i] == 0)
            {
                printf("%d\t", i);
                visited1[i] = 1;
                queue[rear] = i;
                rear++;
            }
        }
    }
}

int main()
{
    visited[1] = 0;
    int n, i, x, y, v, source;

    printf("Enter the number of edges:\n");
    scanf("%d", &n);
    printf("Enter the number of vertices:\n");
    scanf("%d", &v);

    for (i = 0; i < n; i++)
    {
        printf("Enter the adjacent vertices:\n");
        scanf("%d%d", &x, &y);
        m[x][y] = m[y][x] = 1;
    }

    printf("Enter the source\n");
    scanf("%d", &source);

    printf("THE DFS is as follows: \n %d\t", source);

    dfs(m, v, source);
    bfs(m, v, source);
}
