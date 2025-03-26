#include <stdio.h>
int A[20], n, i, x, found=0, low, high, mid;

void main()
{
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter sorted array only\n");
    for(i=0; i<n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &A[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &x);
    low = 0;
    high = n-1;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(x == A[mid])
        {
            found ++;
            break;
        }
        else if(A[mid] < x)
        {
            low = mid +1;
        }
        else
        {
            high = mid -1;
        }
    }

    if(found == 1)
    {
        printf("Search successful!! \nFound at %d", mid);
    }
    else
    {
        printf("Element not present");
    }
}