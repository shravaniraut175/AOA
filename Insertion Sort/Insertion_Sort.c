#include <stdio.h>

int n, i, j, A[20], key;

void Insertion_Sort(int A[], int n);

void main()
{
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter the elements of array: \n");
    for(i=0; i<n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &A[i]);
    }
    printf("The unsorted array is: ");
    for(i=0; i<n; i++)
    {
        printf("%d\t",A[i]);
    }
    Insertion_Sort(A,n);
    printf("\nAfter sorting array is: ");
    for(i=0; i<n; i++)
    {
        printf("%d\t",A[i]);
    }
}


void Insertion_Sort(int A[], int n)
{
    for(i = 1; i<= n-1; i++)
    {
        key = A[i];
        j = i -1;
        while(j >= 0 && A[j] > key)
        {
            A[j+1] = A[j];
            j = j-1;
        }
        A[j+1] = key;
    }
}

