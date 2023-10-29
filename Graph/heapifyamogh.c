#include <stdio.h>

void heapify(int arr[], int n)
{
    // int heap;
    for (int i = n / 2; i >= 1; --i)
    {
        int k = i;
        int val = arr[k];
        int heap = 0;
        while (!heap && 2 * k <= n)
        {
            int j = 2 * k;
            if (j < n)
                if (arr[j] < arr[j + 1])
                    ++j;
            if (arr[j] <= val)
                heap = 1;
            else
            {
                arr[k] = arr[j];
                k = j;
            }
        }
        arr[k] = val;
    }
    return;
}

void heapSort(int arr[], int n)
{
    heapify(arr, n);
    while (n > 1)
    {
        int temp = arr[1];
        arr[1] = arr[n];
        arr[n] = temp;
        n--;
        heapify(arr, n);
    }
    return;
}

int main()
{
    int arr[100];
    for (int i = 1; i <= 20; ++i)
        arr[i] = 100 - i;

    for (int i = 1; i <= 20; ++i)
        printf("%d ", arr[i]);
        
    printf("\n");
    heapSort(arr, 20);
    for (int i = 1; i <= 20; ++i)
        printf("%d ", arr[i]);
    return 0;
}
