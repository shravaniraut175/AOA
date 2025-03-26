#include <stdio.h>
int n, i, j, A[20], minIndex;

void Selection_Sort(int A[], int n);
void Swap(int A[], int i, int minIndex);


void main()
{
    int i, j;
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
    Selection_Sort(A,n);
    printf("\nAfter sorting array is: ");
    for(i=0; i<n; i++)
    {
        printf("%d\t",A[i]);
    }
}


void Selection_Sort(int A[], int n)
{
    for(i= 0; i<=n-2; i++)
    {
        minIndex = i;
        for(j=i+1; j<= n-1; j++)
        {
            if(A[j]< A[minIndex])
            {
                minIndex = j;
            }
        }
        
        Swap(A, i, minIndex);
    }
}


void Swap(int A[], int i, int minIndex)
{
    int temp;
    temp = A[i];
    A[i] = A[minIndex];
    A[minIndex] = temp;
}