#include <stdio.h>

int arr[10], low = 0, high, i, n, j, p, pivot;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    pivot = arr[high];
    i = (low - 1);
    for(j = low; j <= high - 1; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void QuickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        p = partition(arr, low, high);
        QuickSort(arr, low, p - 1);
        QuickSort(arr, p + 1, high);
    }
}

void main()
{
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("\nEnter the elements of unsorted array: \n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    high = n - 1;
    QuickSort(arr, low, high);

    printf("\nSorted array: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

