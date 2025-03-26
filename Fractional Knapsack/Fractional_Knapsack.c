#include <stdio.h>

// Structure to store item details
struct Item {
    int weight;
    int value;
    double ratio;
};

void mergeSort(struct Item arr[], int left, int right);
void merge(struct Item arr[], int left, int mid, int right);
void fractionalKnapsack(const struct Item items[], int n, int capacity);

int main() {
    int n, capacity;
    
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    struct Item items[n];  // Dynamic size based on input
    
    printf("Enter weight and value of each item:\n");
    for(int i = 0; i < n; i++) {
        printf("Enter weight and value: ");
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (double)items[i].value / items[i].weight;
    }
    
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    
    fractionalKnapsack(items, n, capacity);
    
    return 0;
}

// Function to solve Fractional Knapsack
void fractionalKnapsack(const struct Item items[], int n, int capacity) {
    struct Item sortedItems[n];
    
    // Copy original array to avoid modifying input
    for (int i = 0; i < n; i++) {
        sortedItems[i] = items[i];
    }
    
    mergeSort(sortedItems, 0, n - 1);
    
    double totalValue = 0.0;
    
    printf("\nItems taken in the knapsack:\n");
    
    for(int i = 0; i < n; i++) {
        if(capacity >= sortedItems[i].weight) {
            printf("Item with weight %d and value %d taken fully.\n", sortedItems[i].weight, sortedItems[i].value);
            capacity -= sortedItems[i].weight;
            totalValue += sortedItems[i].value;
        } else {
            double fraction = (double)capacity / sortedItems[i].weight;
            printf("Item with weight %d and value %d taken %.2f fraction.\n", sortedItems[i].weight, sortedItems[i].value, fraction);
            totalValue += sortedItems[i].value * fraction;
            break;
        }
    }
    
    printf("Maximum value in knapsack: %.2f\n", totalValue);
}

// Merge Sort function
void mergeSort(struct Item arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Merge function for sorting by value/weight ratio
void merge(struct Item arr[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    
    struct Item L[n1], R[n2];
    
    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    
    for(int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    
    while(i < n1 && j < n2) {
        if(L[i].ratio >= R[j].ratio)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    
    while(i < n1)
        arr[k++] = L[i++];
    
    while(j < n2)
        arr[k++] = R[j++];
}
