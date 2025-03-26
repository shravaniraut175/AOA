#include <stdio.h>

int n, A[20];

void Merge_Sort(int A[], int low, int high);
void Combine(int A[], int low, int mid, int high);

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

    Merge_Sort(A, 0, n - 1);

    printf("\nAfter sorting, the array is: \n");
    for (i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }

    return 0;
}

// Recursive Merge Sort 
void Merge_Sort(int A[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        Merge_Sort(A, low, mid);
        Merge_Sort(A, mid + 1, high);
        Combine(A, low, mid, high);
    }
}

void Combine(int A[], int low, int mid, int high) {
    int n1 = mid - low + 1, n2 = high - mid;
    int Left[n1], Right[n2];


    for (int i = 0; i < n1; i++)
        Left[i] = A[low + i];
    for (int j = 0; j < n2; j++)
        Right[j] = A[mid + 1 + j];


    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j]) {
            A[k++] = Left[i++];
        } else {
            A[k++] = Right[j++];
        }
    }

    while (i < n1) {
        A[k++] = Left[i++];
    }

    while (j < n2) {
        A[k++] = Right[j++];
    }
}
