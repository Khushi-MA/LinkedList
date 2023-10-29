#include <stdio.h>

void merge(int arr[], int start, int end)
{
    int i = 0, j = 0, k = 0;
    int mid = (start + end) / 2;
    int p = mid - start + 1;
    int q = end - mid;

    int b[100], c[100];
    k = start;

    for (i = 0; i < p; ++i)
        b[i] = arr[k++];

    for (i = 0; i < q; ++i)
        c[i] = arr[k++];

    k = start;
    i = j = 0;

    while (i < p && j < q)
    {
        if (b[i] <= c[j])
            arr[k++] = b[i++];
        else
            arr[k++] = c[j++];
    }

    while (j < q)
    {
        arr[k++] = c[j++];
    }

    while (i < p)
    {
        arr[k++] = b[i++];
    }
    return;
}

void mergeSort(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, end);
}

int main()
{
    int arr[100];
    for (int i = 0; i < 10; ++i)
        arr[i] = 100 - i;

    for (int i = 0; i < 10; ++i)
        printf("%d ", arr[i]);

    printf("\n");
    mergeSort(arr, 0, 9);

    for (int i = 0; i < 10; ++i)
        printf("%d ", arr[i]);
        
    return 0;
}