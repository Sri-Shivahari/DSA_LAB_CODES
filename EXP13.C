#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

// Structure to represent a graph
struct Graph {
    int vertices;
    int edges;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Function to initialize a graph
void initGraph(struct Graph *graph, int vertices) {
    graph->vertices = vertices;
    graph->edges = 0;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int start, int end) {
    if (start >= 0 && start < graph->vertices && end >= 0 && end < graph->vertices) {
        graph->adjMatrix[start][end] = 1;
        graph->adjMatrix[end][start] = 1; // Assuming an undirected graph
        graph->edges++;
    } else {
        printf("Invalid edge: (%d, %d)\n", start, end);
    }
}

// Function to print the adjacency matrix
void printGraph(struct Graph *graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges, start, end;
    struct Graph graph;

    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);

    if (vertices <= 0 || vertices > MAX_VERTICES) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    initGraph(&graph, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    if (edges < 0 || edges > (vertices * (vertices - 1) / 2)) {
        printf("Invalid number of edges.\n");
        return 1;
    }

    printf("Enter the edges (start end):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &start, &end);
        addEdge(&graph, start, end);
    }

    printGraph(&graph);

    return 0;
}
