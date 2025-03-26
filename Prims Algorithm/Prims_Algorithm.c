#include <stdio.h>
#include <limits.h>

int n, i, j;  // Global variables
int graph[20][20], parent[20], key[20], mstSet[20];

void primMST();
int minKey();

void main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST();
}

// Function to find the vertex with the minimum key value
int minKey() {
    int min = INT_MAX, minIndex;
    for (i = 0; i < n; i++) {
        if (mstSet[i] == 0 && key[i] < min) {
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to implement Prim's Algorithm
void primMST() {
    for (i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (i = 0; i < n - 1; i++) {
        int u = minKey();
        mstSet[u] = 1;

        for (j = 0; j < n; j++) {
            if (graph[u][j] && mstSet[j] == 0 && graph[u][j] < key[j]) {
                parent[j] = u;
                key[j] = graph[u][j];
            }
        }
    }

    printf("\nMinimum Spanning Tree (MST):\n");
    printf("Edge \tWeight\n");
    for (i = 1; i < n; i++) {
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}
