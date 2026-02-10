# Program 5: Undirected Graph with BFS and DFS

## Data Structures

### 1. Graph Structure
```c
typedef struct {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;
```
- **numVertices**: Number of vertices in the graph
- **adjMatrix**: 2D array representing adjacency matrix
  - `adjMatrix[i][j] = 1` means edge exists between vertex i and j
  - `adjMatrix[i][j] = 0` means no edge
- **MAX_VERTICES**: Maximum vertices allowed (set to 20)

### 2. Queue Structure (for BFS)
```c
typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;
```
- **items**: Array to store queue elements
- **front**: Index of front element
- **rear**: Index of rear element

### 3. Stack Structure (for DFS)
```c
typedef struct {
    int items[MAX_VERTICES];
    int top;
} Stack;
```
- **items**: Array to store stack elements
- **top**: Index of top element

## Functions Implemented

### Graph Operations

#### 1. `void initGraph(Graph *g, int vertices)`
- **Purpose**: Initialize a graph with given number of vertices
- **Parameters**: Pointer to graph, number of vertices
- **Operation**: Sets numVertices and initializes adjacency matrix to 0

#### 2. `void addEdge(Graph *g, int src, int dest)`
- **Purpose**: Add an undirected edge between two vertices
- **Parameters**: Graph pointer, source vertex, destination vertex
- **Algorithm**:
  - For undirected graph, set both `adjMatrix[src][dest]` and `adjMatrix[dest][src]` to 1
- **Time Complexity**: O(1)

#### 3. `void displayGraph(Graph *g)`
- **Purpose**: Display the adjacency matrix representation
- **Output**: Formatted matrix showing all edges

### Queue Operations (for BFS)

#### 4. `void initQueue(Queue *q)`
- **Purpose**: Initialize empty queue
- **Operation**: Sets front and rear to -1

#### 5. `bool isQueueEmpty(Queue *q)`
- **Purpose**: Check if queue is empty
- **Returns**: true if front is -1

#### 6. `void enqueue(Queue *q, int value)`
- **Purpose**: Add element to rear of queue
- **Operation**: Increments rear and adds value

#### 7. `int dequeue(Queue *q)`
- **Purpose**: Remove and return front element
- **Returns**: Value from front of queue

### Stack Operations (for DFS)

#### 8. `void initStack(Stack *s)`
- **Purpose**: Initialize empty stack
- **Operation**: Sets top to -1

#### 9. `bool isStackEmpty(Stack *s)`
- **Purpose**: Check if stack is empty
- **Returns**: true if top is -1

#### 10. `void push(Stack *s, int value)`
- **Purpose**: Add element to top of stack

#### 11. `int pop(Stack *s)`
- **Purpose**: Remove and return top element

### Graph Traversal Algorithms

#### 12. `void BFS(Graph *g, int startVertex)`
- **Purpose**: Breadth-First Search traversal
- **Algorithm**:
  1. Create visited array and queue
  2. Mark start vertex as visited and enqueue it
  3. While queue is not empty:
     - Dequeue a vertex and print it
     - For all unvisited adjacent vertices:
       - Mark as visited
       - Enqueue them
- **Time Complexity**: O(V²) where V is number of vertices (due to adjacency matrix)
- **Space Complexity**: O(V) for queue and visited array
- **Use Cases**: Shortest path in unweighted graph, level-order traversal

#### 13. `void DFS(Graph *g, int startVertex)`
- **Purpose**: Depth-First Search traversal (iterative)
- **Algorithm**:
  1. Create visited array and stack
  2. Push start vertex to stack
  3. While stack is not empty:
     - Pop a vertex
     - If not visited, mark as visited and print
     - Push all unvisited adjacent vertices
- **Time Complexity**: O(V²) with adjacency matrix
- **Space Complexity**: O(V) for stack and visited array

#### 14. `void DFSRecursiveUtil(Graph *g, int vertex, bool visited[])`
- **Purpose**: Recursive helper function for DFS
- **Algorithm**:
  1. Mark current vertex as visited and print
  2. Recursively call for all unvisited adjacent vertices

#### 15. `void DFSRecursive(Graph *g, int startVertex)`
- **Purpose**: DFS traversal (recursive implementation)
- **Algorithm**: Initializes visited array and calls recursive utility
- **Time Complexity**: O(V²)
- **Space Complexity**: O(V) for recursion stack

### Helper Functions

#### 16. `void createExampleGraph(Graph *g)`
- **Purpose**: Create a predefined example graph for demonstration
- **Graph Structure**:
```
     0
    / \
   1   2
  / \   \
 3   4   5
      \ /
       6
```

## Main Method Organization

### 1. Example Demonstration
- Creates sample graph with 7 vertices
- Displays visual representation and adjacency matrix
- Demonstrates BFS from vertices 0, 3, and 6
- Demonstrates DFS (iterative) from vertices 0, 3, and 6
- Demonstrates DFS (recursive) from vertices 0, 3, and 6

### 2. Interactive Mode
Menu-driven interface:
1. Create new graph
2. Add edge
3. Display graph
4. BFS traversal
5. DFS traversal (iterative)
6. DFS traversal (recursive)
7. Exit

## Sample Output

```
=== Undirected Graph Implementation with BFS and DFS ===

--- Example Graph ---
Graph Structure:
     0
    / \
   1   2
  / \   \
 3   4   5
      \ /
       6

Adjacency Matrix:
    0  1  2  3  4  5  6 
 0  0  1  1  0  0  0  0 
 1  1  0  0  1  1  0  0 
 2  1  0  0  0  0  1  0 
 3  0  1  0  0  0  0  0 
 4  0  1  0  0  0  0  1 
 5  0  0  1  0  0  0  1 
 6  0  0  0  0  1  1  0 

--- BFS Demonstrations ---

BFS Traversal starting from vertex 0: 0 1 2 3 4 5 6 

BFS Traversal starting from vertex 3: 3 1 0 4 2 6 5 

BFS Traversal starting from vertex 6: 6 4 5 1 2 3 0 

--- DFS Demonstrations (Iterative) ---

DFS Traversal starting from vertex 0: 0 1 3 4 6 5 2 

DFS Traversal starting from vertex 3: 3 1 0 2 5 6 4 

DFS Traversal starting from vertex 6: 6 4 1 0 2 5 3 

--- DFS Demonstrations (Recursive) ---

DFS Traversal (Recursive) starting from vertex 0: 0 1 3 4 6 5 2 

DFS Traversal (Recursive) starting from vertex 3: 3 1 0 2 5 6 4 

DFS Traversal (Recursive) starting from vertex 6: 6 4 1 0 2 5 3 

--- Interactive Mode ---

1. Create new graph
2. Add edge
3. Display graph
4. BFS traversal
5. DFS traversal (iterative)
6. DFS traversal (recursive)
7. Exit
Enter choice: 1
Enter number of vertices (max 20): 5
Graph with 5 vertices created.

1. Create new graph
2. Add edge
3. Display graph
4. BFS traversal
5. DFS traversal (iterative)
6. DFS traversal (recursive)
7. Exit
Enter choice: 2
Enter source vertex: 0
Enter destination vertex: 1
Edge added between 0 and 1

1. Create new graph
2. Add edge
3. Display graph
4. BFS traversal
5. DFS traversal (iterative)
6. DFS traversal (recursive)
7. Exit
Enter choice: 2
Enter source vertex: 1
Enter destination vertex: 2
Edge added between 1 and 2

1. Create new graph
2. Add edge
3. Display graph
4. BFS traversal
5. DFS traversal (iterative)
6. DFS traversal (recursive)
7. Exit
Enter choice: 3

Adjacency Matrix:
    0  1  2  3  4 
 0  0  1  0  0  0 
 1  1  0  1  0  0 
 2  0  1  0  0  0 
 3  0  0  0  0  0 
 4  0  0  0  0  0 

1. Create new graph
2. Add edge
3. Display graph
4. BFS traversal
5. DFS traversal (iterative)
6. DFS traversal (recursive)
7. Exit
Enter choice: 4
Enter starting vertex for BFS: 0

BFS Traversal starting from vertex 0: 0 1 2 

1. Create new graph
2. Add edge
3. Display graph
4. BFS traversal
5. DFS traversal (iterative)
6. DFS traversal (recursive)
7. Exit
Enter choice: 7
Exiting...
```

## BFS vs DFS Comparison

| Aspect | BFS | DFS |
|--------|-----|-----|
| Data Structure | Queue | Stack (or recursion) |
| Traversal Pattern | Level by level | Depth first |
| Path Found | Shortest path | Any path |
| Memory Usage | Higher (all nodes at current level) | Lower (one path at a time) |
| Applications | Shortest path, level-order | Topological sort, cycle detection |

## Adjacency Matrix Properties

**Advantages:**
- Edge lookup: O(1)
- Simple implementation
- Good for dense graphs

**Disadvantages:**
- Space complexity: O(V²)
- Adding vertex: O(V²)
- Inefficient for sparse graphs

## Time Complexity Summary

| Operation | Adjacency Matrix |
|-----------|-----------------|
| Add Edge | O(1) |
| Remove Edge | O(1) |
| Query Edge | O(1) |
| BFS | O(V²) |
| DFS | O(V²) |
| Space | O(V²) |

where V = number of vertices