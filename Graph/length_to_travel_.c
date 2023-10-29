#include<stdio.h>
#include<math.h>

int matrix[10][10], S=1, expo[10]={0}, count=0;
void depthfs(int a[10][10],int v,int S);

int main (){
    int test,n ,s,d,i;
    scanf("%d", &test );  // printf("Number of Test cases\n");
    while (test--){
        scanf("%d", &n ); // printf("Number of Nodes\n");
        for (i=1;i<n;i++){
            scanf("%d %d",&s,&d);  // printf("enter start and end\n");
            matrix[s][d]=1;
        }
        depthfs(matrix , n , 1);
        if(test!=1)
        count--;
        printf("length travelled...  %d\n", count);
    }
    return 0;
}

void depthfs(int a[10][10],int vertex,int S){
    int i;
    expo[S]=1;
    for(i=1;i<vertex;i++)
        if(a[S][i]==1 && expo[i]==0){
            count++;
            depthfs(a,vertex,i);
            count++;
        }
    return;
}

