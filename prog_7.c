#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 20
#define INF INT_MAX

typedef struct {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

typedef struct {
    int distance[MAX_VERTICES];
    int parent[MAX_VERTICES];
    bool visited[MAX_VERTICES];
} DijkstraResult;

void initGraph(Graph *g, int vertices) {
    g->numVertices = vertices;
    
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int src, int dest, int weight) {
    if (src >= g->numVertices || dest >= g->numVertices || src < 0 || dest < 0) {
        printf("Invalid vertices!\n");
        return;
    }
    
    if (weight < 0) {
        printf("Dijkstra's algorithm doesn't work with negative weights!\n");
        return;
    }
    
    g->adjMatrix[src][dest] = weight;
    g->adjMatrix[dest][src] = weight; // For undirected graph
}

void displayGraph(Graph *g) {
    printf("\nAdjacency Matrix (Weighted):\n");
    printf("     ");
    for (int i = 0; i < g->numVertices; i++) {
        printf("%3d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < g->numVertices; i++) {
        printf("%3d  ", i);
        for (int j = 0; j < g->numVertices; j++) {
            if (g->adjMatrix[i][j] == 0 && i != j) {
                printf("  - ");
            } else {
                printf("%3d ", g->adjMatrix[i][j]);
            }
        }
        printf("\n");
    }
}

int findMinDistance(DijkstraResult *result, int numVertices) {
    int min = INF;
    int minIndex = -1;
    
    for (int v = 0; v < numVertices; v++) {
        if (!result->visited[v] && result->distance[v] < min) {
            min = result->distance[v];
            minIndex = v;
        }
    }
    
    return minIndex;
}

void dijkstra(Graph *g, int source, DijkstraResult *result) {
    if (source >= g->numVertices || source < 0) {
        printf("Invalid source vertex!\n");
        return;
    }
    
    for (int i = 0; i < g->numVertices; i++) {
        result->distance[i] = INF;
        result->parent[i] = -1;
        result->visited[i] = false;
    }
    
    result->distance[source] = 0;
    
    printf("\n=== Running Dijkstra's Algorithm ===\n");
    printf("Source vertex: %d\n\n", source);
    
    for (int count = 0; count < g->numVertices - 1; count++) {
        int u = findMinDistance(result, g->numVertices);
        
        if (u == -1) break; // No more reachable vertices
        
        result->visited[u] = true;
        
        printf("Step %d: Visiting vertex %d (distance: %d)\n", count + 1, u, 
               result->distance[u] == INF ? -1 : result->distance[u]);
        
        // Update distance values of adjacent vertices
        for (int v = 0; v < g->numVertices; v++) {
            // Update distance[v] if:
            // - v is not visited
            // - there is an edge from u to v
            // - total weight from source to v through u is less than current distance[v]
            if (!result->visited[v] && 
                g->adjMatrix[u][v] != 0 && 
                result->distance[u] != INF && 
                result->distance[u] + g->adjMatrix[u][v] < result->distance[v]) {
                
                result->distance[v] = result->distance[u] + g->adjMatrix[u][v];
                result->parent[v] = u;
                
                printf("  -> Updated distance to vertex %d: %d (via %d)\n", 
                       v, result->distance[v], u);
            }
        }
    }
}

// Print path from source to destination
void printPath(DijkstraResult *result, int dest) {
    if (result->parent[dest] == -1) {
        printf("%d", dest);
        return;
    }
    
    printPath(result, result->parent[dest]);
    printf(" -> %d", dest);
}

// Display results
void displayResults(DijkstraResult *result, int source, int numVertices) {
    printf("Destination\tDistance\tPath\n");
    
    for (int i = 0; i < numVertices; i++) {
        printf("%d\t\t", i);
        
        if (result->distance[i] == INF) {
            printf("INF\t\tNo path\n");
        } else {
            printf("%d\t\t", result->distance[i]);
            printPath(result, i);
            printf("\n");
        }
    }
}

// Create example graph
void createExampleGraph(Graph *g) {
    initGraph(g, 6);
    
    
    addEdge(g, 0, 1, 4);
    addEdge(g, 0, 3, 1);
    addEdge(g, 1, 2, 2);
    addEdge(g, 2, 3, 5);
    addEdge(g, 3, 4, 1);
    addEdge(g, 4, 5, 3);
}

int main() {
    Graph g;
    DijkstraResult result;
    
    
    // Create and display example graph
    printf("\n--- Example Weighted Graph ---\n");
    printf("Graph Structure:\n");
    printf("       1\n");
    printf("   (4)/ \\(2)\n");
    printf("     0   2\n");
    printf("   (1)\\  /(5)\n");
    printf("       3--4\n");
    printf("        (1)\n");
    printf("         |\n");
    printf("        (3)\n");
    printf("         5\n");
    
    createExampleGraph(&g);
    displayGraph(&g);
    
    // Run Dijkstra's algorithm from vertex 0
    dijkstra(&g, 0, &result);
    displayResults(&result, 0, g.numVertices);
    
    // Run from different source
    dijkstra(&g, 2, &result);
    displayResults(&result, 2, g.numVertices);
    
    // Interactive mode
    int choice, vertices, src, dest, weight, source;
    
    while (1) {
        printf("\n1. Create new graph\n");
        printf("2. Add edge\n");
        printf("3. Display graph\n");
        printf("4. Run Dijkstra's algorithm\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("Enter number of vertices (max %d): ", MAX_VERTICES);
                scanf("%d", &vertices);
                if (vertices > MAX_VERTICES || vertices < 1) {
                    printf("Invalid number of vertices!\n");
                } else {
                    initGraph(&g, vertices);
                    printf("Graph with %d vertices created.\n", vertices);
                }
                break;
                
            case 2:
                printf("Enter source vertex: ");
                scanf("%d", &src);
                printf("Enter destination vertex: ");
                scanf("%d", &dest);
                printf("Enter edge weight: ");
                scanf("%d", &weight);
                addEdge(&g, src, dest, weight);
                printf("Edge added: %d -- %d (weight: %d)\n", src, dest, weight);
                break;
                
            case 3:
                displayGraph(&g);
                break;
                
            case 4:
                printf("Enter source vertex: ");
                scanf("%d", &source);
                dijkstra(&g, source, &result);
                displayResults(&result, source, g.numVertices);
                break;
                
            case 5:
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}