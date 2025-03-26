#include <stdio.h>

int n, A[20];

void Quick_Sort(int A[], int low, int high);
int Partition(int A[], int low, int high);

int main() {
    int i;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the elements of array:\n");
    for (i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &A[i]);
    }

    printf("\nThe unsorted array is: \n");
    for (i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }

    Quick_Sort(A, 0, n - 1);

    printf("\nAfter sorting, the array is: \n");
    for (i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }

    return 0;
}

// Quick Sort function (Recursive)
void Quick_Sort(int A[], int low, int high) {
    if (low < high) {
        int pivotIndex = Partition(A, low, high);
        Quick_Sort(A, low, pivotIndex - 1);
        Quick_Sort(A, pivotIndex + 1, high);
    }
}

int Partition(int A[], int low, int high) {
    int pivot = A[high]; // Choose last element as pivot
    int i = low - 1;    

    for (int j = low; j < high; j++) {
        if (A[j] < pivot) {
            i++;
            // Swap A[i] and A[j]
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    int temp = A[i + 1];
    A[i + 1] = A[high];
    A[high] = temp;

    return i + 1; 
}
