#include<stdio.h>
#include<string.h>
#define size 10

typedef struct movie_details
{
    char mn[10],    //  movie name
    prod[10],       //  producer
    dir[10],        //  director
    phouse[10];     //  production house
    int ry;         //  release year
}mdet;              //  movie details

void read_movie (mdet M[size], int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        printf("\nenter movie %d details:",i+1);
        printf("\nmovie name\t");
        scanf("%s",M[i].mn);
        printf("producer\t");
        scanf("%s",M[i].prod);
        printf("director\t");
        scanf("%s",M[i].dir);
        printf("production house\t");
        scanf("%s",M[i].mn);
        printf("release year\t");
        scanf("%d",&M[i].ry);
    }
}

void display_movie (mdet M[size], int n)
{
    int i;
    printf("\n\nS.no.\tmovie.name\tproducer\tdirector\tproduction_house\trelease year\t");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t%s\t\t%s\t%s\t%s\t%d\t",1+i,M[i].mn,M[i].prod,M[i].dir,M[i].phouse,M[i].ry);
    }
}

void sort_release (mdet M[size], int n)
{
    int i,j,t;

    for(i=0;i<n;i++);
    {
        for(j=0;j<n-i-1;j++)
        {
            if(M[i].ry>M[i+1].ry)
            {
                t = M[i].ry;
                M[i].ry = M[i+1].ry;
                M[i+1].ry = t;
            }
        }
    }
}

mdet search(mdet M[size], int n, char unknown[10])
{
    int i;
    for(i=0;i<n;i++)
    {
        if(strcmp(unknown,M[i].phouse[10]==0))
        {
            printf("\nproduction house found");
            return M[i];
        }

        else
            printf("\nproduction house not found");
    }
}

int main()
{
    mdet M[size], uk;
    char unknown[10];
    int n;

    printf("\nenter the number of movies: ");
    scanf("%d",&n);
    read_movie(M,n);
    display_movie(M,n);
    sort_release(M,n);
    display_movie(M,n);
    printf("\nenter the movie you want to search");
    scanf("%c",unknown[10]);
    getchar();
    uk = search(M,n,unknown);
}
