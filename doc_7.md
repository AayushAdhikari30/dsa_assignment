# Program 7: Dijkstra's Shortest Path Algorithm

## Data Structures

### 1. Graph Structure
```c
typedef struct {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;
```
- **numVertices**: Number of vertices in the graph
- **adjMatrix**: 2D array storing edge weights
  - `adjMatrix[i][j]` = weight of edge from i to j
  - `adjMatrix[i][j]` = 0 means no edge (or i == j)
- **MAX_VERTICES**: Maximum vertices allowed (20)

### 2. DijkstraResult Structure
```c
typedef struct {
    int distance[MAX_VERTICES];
    int parent[MAX_VERTICES];
    bool visited[MAX_VERTICES];
} DijkstraResult;
```
- **distance**: Shortest distance from source to each vertex
- **parent**: Previous vertex in shortest path (for path reconstruction)
- **visited**: Boolean array tracking visited vertices
- **INF**: Constant representing infinity (INT_MAX)

## Functions Implemented

### Graph Operations

#### 1. `void initGraph(Graph *g, int vertices)`
- **Purpose**: Initialize graph with given number of vertices
- **Parameters**: Graph pointer, number of vertices
- **Operation**: Sets numVertices and initializes adjacency matrix to 0

#### 2. `void addEdge(Graph *g, int src, int dest, int weight)`
- **Purpose**: Add weighted edge between two vertices
- **Parameters**: Graph pointer, source, destination, weight
- **Validation**:
  - Checks for valid vertices
  - Rejects negative weights (Dijkstra's doesn't handle them)
- **Operation**: Sets both `adjMatrix[src][dest]` and `adjMatrix[dest][src]` for undirected graph
- **Time Complexity**: O(1)

#### 3. `void displayGraph(Graph *g)`
- **Purpose**: Display adjacency matrix with weights
- **Output**: Formatted matrix showing all edges and weights

### Dijkstra's Algorithm Functions

#### 4. `int findMinDistance(DijkstraResult *result, int numVertices)`
- **Purpose**: Find unvisited vertex with minimum distance
- **Algorithm**: Linear search through distance array
- **Returns**: Index of vertex with minimum distance, or -1 if none found
- **Time Complexity**: O(V) where V is number of vertices

#### 5. `void dijkstra(Graph *g, int source, DijkstraResult *result)`
- **Purpose**: Find shortest paths from source to all other vertices
- **Algorithm**:
  1. Initialize all distances to INF except source (0)
  2. Initialize all parents to -1
  3. Mark all vertices as unvisited
  4. For each vertex:
     - Find unvisited vertex with minimum distance
     - Mark it as visited
     - For each unvisited neighbor:
       - Calculate new distance through current vertex
       - Update if new distance is shorter
       - Update parent for path reconstruction
- **Time Complexity**: O(V²) with adjacency matrix
- **Space Complexity**: O(V) for result arrays
- **Key Feature**: Prints step-by-step execution for learning

#### 6. `void printPath(DijkstraResult *result, int dest)`
- **Purpose**: Recursively print shortest path to destination
- **Algorithm**: Backtrack through parent array
- **Output Format**: `0 -> 3 -> 4 -> 5`

#### 7. `void displayResults(DijkstraResult *result, int source, int numVertices)`
- **Purpose**: Display all shortest paths and distances from source
- **Output**: Formatted table with destination, distance, and path

### Example Graph Function

#### 8. `void createExampleGraph(Graph *g)`
- **Purpose**: Create predefined weighted graph for demonstration
- **Graph Structure**:
```
       1
   (4)/ \(2)
     0   2
   (1)\  /(5)
       3--4
        (1)
         |
        (3)
         5
```

## Dijkstra's Algorithm Explanation

### How It Works

1. **Initialization**:
   - Set distance to source as 0
   - Set all other distances as infinity
   - Mark all vertices as unvisited

2. **Main Loop**:
   - Select unvisited vertex with minimum distance
   - Mark it as visited
   - Update distances to all unvisited neighbors

3. **Relaxation**:
   - For each neighbor v of current vertex u:
   - If `distance[u] + weight(u,v) < distance[v]`:
     - Update `distance[v] = distance[u] + weight(u,v)`
     - Update `parent[v] = u`

4. **Termination**:
   - When all vertices are visited
   - Or when no more reachable vertices exist

### Greedy Approach

Dijkstra's uses a **greedy strategy**: always pick the vertex with the smallest known distance, update its neighbors, and never revisit it. This works because with non-negative weights, once we've found the shortest path to a vertex, we'll never find a shorter one.

## Main Method Organization

### 1. Example Demonstration
- Creates sample weighted graph with 6 vertices
- Displays graph structure and adjacency matrix
- Runs Dijkstra's from vertex 0
- Shows step-by-step execution
- Displays final results table
- Runs again from vertex 2 to show different source

### 2. Interactive Mode
Menu with 5 options:
1. Create new graph
2. Add weighted edge
3. Display graph
4. Run Dijkstra's algorithm from chosen source
5. Exit

## Sample Output

```
=== Dijkstra's Shortest Path Algorithm ===

--- Example Weighted Graph ---
Graph Structure:
       1
   (4)/ \(2)
     0   2
   (1)\  /(5)
       3--4
        (1)
         |
        (3)
         5

Adjacency Matrix (Weighted):
       0   1   2   3   4   5 
  0    0   4   -   1   -   - 
  1    4   0   2   -   -   - 
  2    -   2   0   5   -   - 
  3    1   -   5   0   1   - 
  4    -   -   -   1   0   3 
  5    -   -   -   -   3   0 

=== Running Dijkstra's Algorithm ===
Source vertex: 0

Step 1: Visiting vertex 0 (distance: 0)
  -> Updated distance to vertex 1: 4 (via 0)
  -> Updated distance to vertex 3: 1 (via 0)
Step 2: Visiting vertex 3 (distance: 1)
  -> Updated distance to vertex 2: 6 (via 3)
  -> Updated distance to vertex 4: 2 (via 3)
Step 3: Visiting vertex 4 (distance: 2)
  -> Updated distance to vertex 5: 5 (via 4)
Step 4: Visiting vertex 1 (distance: 4)
  -> Updated distance to vertex 2: 6 (via 1)
Step 5: Visiting vertex 5 (distance: 5)

=== Shortest Paths from Source 0 ===
Destination	Distance	Path
-------------------------------------------
0		0		0
1		4		0 -> 1
2		6		0 -> 1 -> 2
3		1		0 -> 3
4		2		0 -> 3 -> 4
5		5		0 -> 3 -> 4 -> 5


--- Running from Different Source ---

=== Running Dijkstra's Algorithm ===
Source vertex: 2

Step 1: Visiting vertex 2 (distance: 0)
  -> Updated distance to vertex 1: 2 (via 2)
  -> Updated distance to vertex 3: 5 (via 2)
Step 2: Visiting vertex 1 (distance: 2)
  -> Updated distance to vertex 0: 6 (via 1)
Step 3: Visiting vertex 3 (distance: 5)
  -> Updated distance to vertex 0: 6 (via 3)
  -> Updated distance to vertex 4: 6 (via 3)
Step 4: Visiting vertex 0 (distance: 6)
Step 5: Visiting vertex 4 (distance: 6)
  -> Updated distance to vertex 5: 9 (via 4)

=== Shortest Paths from Source 2 ===
Destination	Distance	Path
-------------------------------------------
0		6		2 -> 1 -> 0
1		2		2 -> 1
2		0		2
3		5		2 -> 3
4		6		2 -> 3 -> 4
5		9		2 -> 3 -> 4 -> 5

--- Interactive Mode ---

1. Create new graph
2. Add edge
3. Display graph
4. Run Dijkstra's algorithm
5. Exit
Enter choice: 1
Enter number of vertices (max 20): 4
Graph with 4 vertices created.

1. Create new graph
2. Add edge
3. Display graph
4. Run Dijkstra's algorithm
5. Exit
Enter choice: 2
Enter source vertex: 0
Enter destination vertex: 1
Enter edge weight: 10
Edge added: 0 -- 1 (weight: 10)

1. Create new graph
2. Add edge
3. Display graph
4. Run Dijkstra's algorithm
5. Exit
Enter choice: 2
Enter source vertex: 0
Enter destination vertex: 2
Enter edge weight: 5
Edge added: 0 -- 2 (weight: 5)

1. Create new graph
2. Add edge
3. Display graph
4. Run Dijkstra's algorithm
5. Exit
Enter choice: 2
Enter source vertex: 2
Enter destination vertex: 1
Enter edge weight: 2
Edge added: 2 -- 1 (weight: 2)

1. Create new graph
2. Add edge
3. Display graph
4. Run Dijkstra algorithm
5. Exit
Enter choice: 3

Adjacency Matrix (Weighted):
       0   1   2   3 
  0    0  10   5   - 
  1   10   0   2   - 
  2    5   2   0   - 
  3    -   -   -   0 

1. Create new graph
2. Add edge
3. Display graph
4. Run Dijkstra's algorithm
5. Exit
Enter choice: 4
Enter source vertex: 0

=== Running Dijkstra's Algorithm ===
Source vertex: 0

Step 1: Visiting vertex 0 (distance: 0)
  -> Updated distance to vertex 1: 10 (via 0)
  -> Updated distance to vertex 2: 5 (via 0)
Step 2: Visiting vertex 2 (distance: 5)
  -> Updated distance to vertex 1: 7 (via 2)
Step 3: Visiting vertex 1 (distance: 7)

=== Shortest Paths from Source 0 ===
Destination	Distance	Path
-------------------------------------------
0		0		0
1		7		0 -> 2 -> 1
2		5		0 -> 2
3		INF		No path

1. Create new graph
2. Add edge
3. Display graph
4. Run Dijkstra's algorithm
5. Exit
Enter choice: 5
Exiting...
```

## Algorithm Properties

### Correctness
- **Optimal Substructure**: Shortest path contains shortest subpaths
- **Greedy Choice**: Always selecting minimum distance vertex is safe

### Limitations
- **Negative Weights**: Doesn't work with negative edge weights
  - Use Bellman-Ford algorithm instead
- **Dense Graphs**: O(V²) can be slow for large graphs
  - Use priority queue (heap) for O((V+E) log V)

## Time Complexity Analysis

| Implementation | Time Complexity | Space Complexity |
|----------------|----------------|------------------|
| Array (this program) | O(V²) | O(V) |
| Binary Heap | O((V+E) log V) | O(V) |
| Fibonacci Heap | O(E + V log V) | O(V) |

where V = vertices, E = edges

## Applications

1. **GPS Navigation**: Finding shortest routes
2. **Network Routing**: Packet routing in networks
3. **Social Networks**: Finding closest connections
4. **Game Development**: Pathfinding for AI
5. **Transportation**: Optimal routes in logistics

## Key Concepts Demonstrated

1. **Single-Source Shortest Path**: Finds paths from one source to all vertices
2. **Greedy Algorithm**: Makes locally optimal choice at each step
3. **Relaxation**: Improving distance estimates
4. **Path Reconstruction**: Using parent array to trace paths
5. **Graph Representation**: Weighted adjacency matrix