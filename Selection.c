#include <stdio.h>
#include <conio.h>
int i, n, j, minj, minx, A[20];
void main()
{
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("\nEnter the elements of unsorted array: \n");
    for (i=0; i<n ; i++)
    {
       scanf("%d", &A[i]);
    }
    for (i =0; i<n-1; i++)
    {
        minj = i;
        minx = A[i];
        for(j=i+1; j<n; j++)
        {
            if( A[j] < minx)
            {
                minj = j;
                minx = A[j];
            }
        }
        A[minj] = A[i];
        A[i] = minx;
    }
    printf("\nSorted array: \n");
    for (i=0; i<n ; i++)
    {
       printf("%d\t", A[i]);
    }
}
