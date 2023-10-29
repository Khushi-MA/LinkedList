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

    for(i = r-1, index = 0;i!=0;i--)
        index = index + i;
    
    NODE box[index], temp;
    for(i=1, k=0;i<=r;i++)
    {
        for(j=i+1;j<=r;j++, k++)
        {
            box[k].weight = arr[i][j];
            box[k].start = i;
            box[k].finish = j;
        }
    }

        for(i=1;i<=index;i++)
        {
            for(j=0;j<=index-i-1;j++)
            {
                if(box[j].weight > box[j+1].weight)
                {
                    temp = box[j];
                    box[j]=box[j+1];
                    box[j+1]=temp;
                }
            }
        }

        for(i=0;i<index;i++)
            printf("\n%d...%d->%d",box[i].weight, box[i].start, box[i].finish);
        

    int span[r], refer[r], count;
    int totweigh=0;
    for(i=1;i<=r;i++)
    {
        span[i]=i;
        refer[i]=i;
    }

    printf("\n\n");
    for(i=1;i<=r;i++)
    printf("%d  ",span[i]);
    printf("\n\n");
    for(i=1;i<=r;i++)
    printf("%d  ",refer[i]);
    printf("\n\n");

    for(i=0, totweigh=0; i<index; i++)
    {
        printf("\n%d...%d->%d",box[i].weight, box[i].start, box[i].finish);
        if( span[box[i].start] != span[box[i].finish] )
        {
           // printf("\n%d != %d\n", span[box[i].start], span[box[i].finish]);  
            totweigh = totweigh + box[i].weight;
            printf("\n%d->%d",refer[box[i].start], refer[box[i].finish]);
            span[box[i].start] = span[box[i].finish];
        }

        printf("\n\n");
        printf("\nspan:\n");
        for(j=1;j<=r;j++)
            printf("%d  ",span[i]);
        
        for(j=0, count = 0;j<index-1;j++)
        {
            if(span[j] == span[j+1])
                count++;
        }

        if(count==index-1)
            break;
    }

    printf("\n\ntot weigh = %d", totweigh);

    return 0;
}

/*
0 30 20 10
30 0 40 60
20 40 0 50
10 60 50 0
*/
