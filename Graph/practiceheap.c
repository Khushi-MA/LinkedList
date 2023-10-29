#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define INF 999

void heapsort(int arr[], int n);
void heapify(int n, int arr[]);

int main()
{
    int nV;
    printf("\nenter the number of element\n");
    scanf("%d", &nV);
    int arr[nV+1];
    printf("\nenter the unsorted array");
    for(int i=1; i<=nV; i++)
    {
        arr[i] = 99-i;
        printf("%d  ", arr[i]);
    }
        

    heapsort(arr,nV);
    printf("\nheap\n");
    for(int i=1;i<=nV;i++)
        printf("%d  ", arr[i]);
}

void heapsort(int arr[], int n)
{
    heapify(n, arr);
    while(n>1)
    {
        int temp = arr[n];
        arr[n] = arr[1];
        arr[1] = temp;
        n--;
        heapify(n, arr);
    }
    return;
}

void heapify(int n, int arr[])
{
    for(int i=n/2;i>=1;--i)
    {
        int k = i, j;
        int value = arr[i];
        int heap = 0;
        
        while(!heap && 2*k<=n)
        {
            j = 2 * k;

            if(j<n)
                if(arr[j]<arr[j+1])
                    j++;

            if(arr[j]<value)
                heap = 1;

            else
            {
                arr[k] = arr[j];
                k = j;
            }
        }
        arr[k] = value;
    }
    return;

}