#include <stdio.h>

struct Edge {
    int src, dest, weight;
};

int n, m, i, j;
struct Edge edges[20], result[20];
int parent[20];

void kruskalMST();
int find(int);
void unionSets(int, int);

void main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (source, destination, weight):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    kruskalMST();
}

// Function to find the parent of a node
int find(int v) {
    if (parent[v] == v)
        return v;
    return find(parent[v]);
}

// Function to union two sets
void unionSets(int u, int v) {
    parent[v] = u;
}

// Function to implement Kruskal's Algorithm
void kruskalMST() {
    struct Edge temp;
    int cost = 0, edgeCount = 0;

    // Sort edges in ascending order of weight (Simple Bubble Sort)
    for (i = 0; i < m - 1; i++) {
        for (j = 0; j < m - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Initialize disjoint sets
    for (i = 0; i < n; i++)
        parent[i] = i;

    printf("\nMinimum Spanning Tree (MST):\n");
    printf("Edge \tWeight\n");

    // Pick edges one by one in sorted order
    for (i = 0; i < m && edgeCount < n - 1; i++) {
        int u = find(edges[i].src);
        int v = find(edges[i].dest);

        if (u != v) {
            result[edgeCount++] = edges[i];
            unionSets(u, v);
            cost += edges[i].weight;
            printf("%d - %d\t%d\n", edges[i].src, edges[i].dest, edges[i].weight);
        }
    }

    printf("Total Minimum Cost: %d\n", cost);
}
