#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<math.h>

// weighted and undirected graph
struct node
{
    int weight;
    char start, finish;
};

typedef struct node NODE;

int main()
{
    int i, j, r, index, k;
    printf("\nenter number of nodes\n");
    scanf("%d", &r);
    printf("\nstart entering the values\n");
    int arr[r][r];

    // reading the adjacency matrix;
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=r;j++)
            scanf("%d",&arr[i][j]);
    }

    for(i = r-1, index = 0 ; i!=0 ; index = index+i, i--);

    printf("\n\nindex = %d\n", index);
    
    NODE box[index], temp;
    for(i=1, k=0;i<=r;i++)
    {
        for(j=i+1;j<=r;j++, k++)
        {
            box[k].weight = arr[i][j];
            box[k].start = i+1;
            box[k].finish = j+1;
        }
    }

        for(i=1;i<index;i++)
        {
            for(j=0;j<index-i;j++)
            {
                if(box[j].weight>box[j+1].weight)
                {
                    temp = box[j];
                    box[j]=box[j+1];
                    box[j+1]=temp;
                }
            }
        }

        for(i=0;i<index;i++)
            printf("\n%d...%d->%d",box[i].weight, box[i].start, box[i].finish);
        
        return 0;
}

/*
0 30 20 10
30 0 40 60
20 40 0 50
10 60 50 0
*/
