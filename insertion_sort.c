#include<stdio.h>

int i, j, x, n, A[10];

void main()
{
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    for(j = 1; j < n; j++)
    {
        x = A[j];
        i = j - 1;
        
        while(i >= 0 && A[i] > x)
        {
            A[i + 1] = A[i];
            i--;
        }

        A[i + 1] = x;
    }

    printf("Elements after sorting: ");
    for(i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
}
