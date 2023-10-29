#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include<limits.h>

void bubblesort(int, int *);
void selectionsort(int, int *);
void insertionsort(int, int *);
void printarray (int, int *);
void generatearray (int , int *);
void merge(int, int, int, int *);
void mergesort( int, int, int *);
int partition(int, int, int[]);
void quicksort(int, int , int a[]);
void countsort(int , int a[]);

int main()
{
    int n, choice=0, i, num;
    while(1)
    {
        printf("enter the length of array\n");
        scanf("%d",&n);
        int arr[n];
        printf("\nUnsorted array:\n");
        generatearray(n,arr);
    
    /**************  sorting  *******************************/
        //bubblesort(n, arr);  
        //selectionsort(n, arr);
        // insertionsort(n, arr);
        mergesort(0, n, arr);
        printf("\nmerge sort:");
        // quicksort(0, n, arr);
        // printf("\nQuick sort:");
        // countsort(n, arr);

    /*********************************************************/

        printf("\nsorted array:\n");
        printarray(n,arr);
        printf("\nDo you want to continue??? if no, type 0 else, type some other number\n");
        //scanf("%d",&choice);
        if(choice==0)
        break;
    }
    
    return 0;
}

void printarray(int n, int a[n])
{
    int i;
    for(i=0;i<n;i++) 
    printf("%d  ",a[i]);

    return;
}

void generatearray (int n, int a[n])
{
    int i;
    for(i=0;i<n;i++)
    {
        a[i] = rand();
        printf("%d  ",a[i]);
    }

    return;    
}

void bubblesort(int n, int a[n])
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("\nBubble_sort:");

    return;
}

void selectionsort(int n, int a[n])
{
    int i, imin, j, temp;
    for(i=0;i<n-1;i++)
    {
        imin = i;
        for(j=i+1;j<n;j++)
        {
            if(a[j] < a[imin])
            imin = j;
        }

        temp = a[i];
        a[i] = a[imin];
        a[imin] = temp;
    }
    printf("\nSelection sort:");

    return;
} 

void insertionsort(int n, int a[n])
{
    int i, j, key;
    for(i=0 ; i<=n-1 ; i++)
    {
        key = a[i];
        j = i-1;
        while(a[j] < key && j >= 0)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
    printf("\nInsertion sort:");

    return;
}

void merge(int mid, int low, int high, int a[])
{
    int i = low, j = mid+1, k = low, b[100];
    while(i<=mid && j<=high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i]; i++; k++;
        }
        else
        {
            b[k] = a [j];
            j++;
            k++;
        }
    }
    
    while(i<=mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }

     while(j<=high)
    {
        b[k] = a[j];
        j++;
        k++;
    }

    for(i = low ; i <= high ; i++)
        a[i] = b[i];

    return;
}

void mergesort( int low, int high, int a[])
{
    int mid;
    if(low < high)
    {
        mid = (low+high) / 2;
        mergesort(low, mid, a);
        mergesort(mid+1, high, a);
        merge(mid, low, high, a);
    }

    return;
}

void quicksort(int low, int high, int a[])
{
    int partitionindex;          // index of pivot after partition
    partitionindex = partition(low, high, a);
    quicksort(low, partitionindex-1, a);     // sort left subarray
    quicksort(partitionindex+1, high, a);    // sort right subarray

    return;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
int partition(int low, int high, int a[])
{
    int i = low + 1, j = high, temp, pivot = a[low];
    do
    {
        while(a[i] <= pivot)
            i++;

        while(a[j] > pivot)
            j--;

        if(i<j)
        {   // swapping the number at ith and jth place
            temp = a[i]; a[i] = a[j]; a[j] = temp;
        }
    } while (i < j);

    // swapping the pivot with jth place
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void countsort(int n, int a[n])
{
    int i, j;
    printf("Changed array for countsort\n");
    for(i=0;i<n;i++)
    a[i] = a[i]%100;

    printarray(n,a);
    int max = 100;
    int arr[max];
    arr[max] = 0;

    for (i=0;i<n;i++)
        arr[a[i]]++;

    for(i=0, j=0 ; i<999 || j<n ; i++, j++)
    {
        if(arr[i]==1)
            a[j]=i+1;
    }

    return;
}

