#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 20

typedef struct {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

typedef struct {
    int items[MAX_VERTICES];
    int top;
} Stack;

// Initialize graph
void initGraph(Graph *g, int vertices) {
    g->numVertices = vertices;
    
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// Add edge (undirected graph)
void addEdge(Graph *g, int src, int dest) {
    if (src >= g->numVertices || dest >= g->numVertices || src < 0 || dest < 0) {
        printf("Invalid vertices!\n");
        return;
    }
    
    // Since it's undirected, add edge in both directions
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1;
}

// Display adjacency matrix
void displayGraph(Graph *g) {
    printf("\nAdjacency Matrix:\n");
    printf("   ");
    for (int i = 0; i < g->numVertices; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < g->numVertices; i++) {
        printf("%2d ", i);
        for (int j = 0; j < g->numVertices; j++) {
            printf("%2d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Operations for BFS
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isQueueEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int value) {
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue *q) {
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

// Operations for DFS
void initStack(Stack *s) {
    s->top = -1;
}

bool isStackEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    s->items[++(s->top)] = value;
}

int pop(Stack *s) {
    return s->items[(s->top)--];
}

// Breadth First Search (BFS)
void BFS(Graph *g, int startVertex) {
    if (startVertex >= g->numVertices || startVertex < 0) {
        printf("Invalid start vertex!\n");
        return;
    }
    
    bool visited[MAX_VERTICES] = {false};
    Queue q;
    initQueue(&q);
    
    printf("\nBFS Traversal starting from vertex %d: ", startVertex);
    
    visited[startVertex] = true;
    enqueue(&q, startVertex);
    
    while (!isQueueEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);
        
        // Check all adjacent vertices
        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

// Depth First Search (DFS) 
void DFS(Graph *g, int startVertex) {
    if (startVertex >= g->numVertices || startVertex < 0) {
        printf("Invalid start vertex!\n");
        return;
    }
    
    bool visited[MAX_VERTICES] = {false};
    Stack s;
    initStack(&s);
    
    printf("\nDFS Traversal starting from vertex %d: ", startVertex);
    
    push(&s, startVertex);
    
    while (!isStackEmpty(&s)) {
        int currentVertex = pop(&s);
        
        if (!visited[currentVertex]) {
            printf("%d ", currentVertex);
            visited[currentVertex] = true;
        }
        
        // Push all adjacent unvisited vertices to stack
        // Push in reverse order to maintain left-to-right traversal
        for (int i = g->numVertices - 1; i >= 0; i--) {
            if (g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                push(&s, i);
            }
        }
    }
    printf("\n");
}

// DFS Recursive implementation
void DFSRecursiveUtil(Graph *g, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);
    
    // Recur for all adjacent vertices
    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSRecursiveUtil(g, i, visited);
        }
    }
}

void DFSRecursive(Graph *g, int startVertex) {
    if (startVertex >= g->numVertices || startVertex < 0) {
        printf("Invalid start vertex!\n");
        return;
    }
    
    bool visited[MAX_VERTICES] = {false};
    printf("\nDFS Traversal (Recursive) starting from vertex %d: ", startVertex);
    DFSRecursiveUtil(g, startVertex, visited);
    printf("\n");
}

// Create example graph
void createExampleGraph(Graph *g) {
    initGraph(g, 7);
    
    
    
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 5);
    addEdge(g, 4, 6);
    addEdge(g, 5, 6);
}

int main() {
    Graph g;
    
    printf("Undirected Graph Implementation with BFS and DFS \n");
    
    // Create and display example graph
    printf("Graph Structure:\n");
    printf("     0\n");
    printf("    / \\\n");
    printf("   1   2\n");
    printf("  / \\   \\\n");
    printf(" 3   4   5\n");
    printf("      \\ /\n");
    printf("       6\n");
    
    createExampleGraph(&g);
    displayGraph(&g);
    
    // Perform BFS from different starting vertices
    printf("\n BFS Demonstrations \n");
    BFS(&g, 0);
    BFS(&g, 3);
    BFS(&g, 6);
    
    // Perform DFS from different starting vertices
    printf("\n DFS Demonstrations (Iterative) \n");
    DFS(&g, 0);
    DFS(&g, 3);
    DFS(&g, 6);
    
    // Perform recursive DFS
    printf("\n DFS Demonstrations (Recursive) \n");
    DFSRecursive(&g, 0);
    DFSRecursive(&g, 3);
    DFSRecursive(&g, 6);
    
    // Interactive mode
    printf("\n Interactive Mode \n");
    int choice, vertices, src, dest, start;
    
    while (1) {
        printf("\n1. Create new graph\n");
        printf("2. Add edge\n");
        printf("3. Display graph\n");
        printf("4. BFS traversal\n");
        printf("5. DFS traversal (iterative)\n");
        printf("6. DFS traversal (recursive)\n");
        printf("7. Exit\n");
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
                addEdge(&g, src, dest);
                printf("Edge added between %d and %d\n", src, dest);
                break;
                
            case 3:
                displayGraph(&g);
                break;
                
            case 4:
                printf("Enter starting vertex for BFS: ");
                scanf("%d", &start);
                BFS(&g, start);
                break;
                
            case 5:
                printf("Enter starting vertex for DFS: ");
                scanf("%d", &start);
                DFS(&g, start);
                break;
                
            case 6:
                printf("Enter starting vertex for DFS: ");
                scanf("%d", &start);
                DFSRecursive(&g, start);
                break;
                
            case 7:
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}