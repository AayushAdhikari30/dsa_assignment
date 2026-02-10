# Program 6: Min Heap and Max Heap Implementation

## Data Structures

### 1. MinHeap Structure
```c
typedef struct {
    int arr[MAX_SIZE];
    int size;
} MinHeap;
```
- **arr**: Array to store heap elements
- **size**: Current number of elements in heap
- **Heap Property**: For any node i, `arr[i] <= arr[2i+1]` and `arr[i] <= arr[2i+2]`

### 2. MaxHeap Structure
```c
typedef struct {
    int arr[MAX_SIZE];
    int size;
} MaxHeap;
```
- **arr**: Array to store heap elements
- **size**: Current number of elements in heap
- **Heap Property**: For any node i, `arr[i] >= arr[2i+1]` and `arr[i] >= arr[2i+2]`

### Heap Representation
- Parent of node at index i: `(i-1)/2`
- Left child of node at index i: `2i+1`
- Right child of node at index i: `2i+2`

## Functions Implemented

### Helper Functions

#### 1. `void swap(int *a, int *b)`
- **Purpose**: Swap two integer values
- **Parameters**: Pointers to two integers

#### 2. `int getParent(int i)`
- **Purpose**: Calculate parent index
- **Returns**: Parent index for node at position i

#### 3. `int getLeftChild(int i)`
- **Purpose**: Calculate left child index
- **Returns**: Left child index for node at position i

#### 4. `int getRightChild(int i)`
- **Purpose**: Calculate right child index
- **Returns**: Right child index for node at position i

### Min Heap Operations

#### 5. `void initMinHeap(MinHeap *heap)`
- **Purpose**: Initialize an empty min heap
- **Operation**: Sets size to 0

#### 6. `void minHeapifyDown(MinHeap *heap, int i)`
- **Purpose**: Maintain min heap property by moving element down
- **Algorithm**:
  1. Find smallest among node, left child, and right child
  2. If smallest is not current node, swap and recurse
- **Time Complexity**: O(log n)
- **Used**: After deletion operations

#### 7. `void minHeapifyUp(MinHeap *heap, int i)`
- **Purpose**: Maintain min heap property by moving element up
- **Algorithm**:
  1. Compare with parent
  2. If smaller than parent, swap and recurse
- **Time Complexity**: O(log n)
- **Used**: After insertion operations

#### 8. `void buildMinHeap(MinHeap *heap, int arr[], int n)`
- **Purpose**: Build min heap from unsorted array
- **Algorithm**:
  1. Copy array elements to heap
  2. Start from last non-leaf node: `(n/2) - 1`
  3. Call minHeapifyDown for each node going backwards
- **Time Complexity**: O(n) - optimal heap construction
- **Space Complexity**: O(1) excluding recursion stack

#### 9. `void insertMinHeap(MinHeap *heap, int value)`
- **Purpose**: Insert new element into min heap
- **Algorithm**:
  1. Add element at end
  2. Heapify up to maintain heap property
- **Time Complexity**: O(log n)

#### 10. `int extractMin(MinHeap *heap)`
- **Purpose**: Remove and return minimum element (root)
- **Algorithm**:
  1. Store root value
  2. Replace root with last element
  3. Decrease size
  4. Heapify down from root
- **Returns**: Minimum value
- **Time Complexity**: O(log n)

#### 11. `void displayMinHeap(MinHeap *heap)`
- **Purpose**: Print heap array representation
- **Output**: Array format showing all elements

### Max Heap Operations

#### 12. `void initMaxHeap(MaxHeap *heap)`
- **Purpose**: Initialize an empty max heap

#### 13. `void maxHeapifyDown(MaxHeap *heap, int i)`
- **Purpose**: Maintain max heap property by moving element down
- **Algorithm**:
  1. Find largest among node, left child, and right child
  2. If largest is not current node, swap and recurse
- **Time Complexity**: O(log n)

#### 14. `void maxHeapifyUp(MaxHeap *heap, int i)`
- **Purpose**: Maintain max heap property by moving element up
- **Algorithm**:
  1. Compare with parent
  2. If larger than parent, swap and recurse
- **Time Complexity**: O(log n)

#### 15. `void buildMaxHeap(MaxHeap *heap, int arr[], int n)`
- **Purpose**: Build max heap from unsorted array
- **Algorithm**: Same as buildMinHeap but uses maxHeapifyDown
- **Time Complexity**: O(n)

#### 16. `void insertMaxHeap(MaxHeap *heap, int value)`
- **Purpose**: Insert new element into max heap
- **Time Complexity**: O(log n)

#### 17. `int extractMax(MaxHeap *heap)`
- **Purpose**: Remove and return maximum element (root)
- **Time Complexity**: O(log n)

#### 18. `void displayMaxHeap(MaxHeap *heap)`
- **Purpose**: Print heap array representation

### Visualization Functions

#### 19. `void printHeapTree(int arr[], int n, int i, int level)`
- **Purpose**: Recursively print heap as tree structure
- **Parameters**: Array, size, current index, indentation level
- **Output**: Visual tree representation

#### 20. `void visualizeMinHeap(MinHeap *heap)`
- **Purpose**: Display min heap in tree format

#### 21. `void visualizeMaxHeap(MaxHeap *heap)`
- **Purpose**: Display max heap in tree format

## Main Method Organization

### 1. Demonstration Phase
- **Test Data**: Uses unsorted array `{12, 11, 13, 5, 6, 7, 15, 3, 9, 8}`
- **Min Heap Building**: Constructs and displays min heap
- **Max Heap Building**: Constructs and displays max heap
- **Extract Operations**: Demonstrates removing min/max elements
- **Insert Operations**: Shows insertion with heap property maintenance

### 2. Interactive Mode
Menu with 9 options:
1. Insert into Min Heap
2. Extract from Min Heap
3. Display Min Heap (with tree visualization)
4. Insert into Max Heap
5. Extract from Max Heap
6. Display Max Heap (with tree visualization)
7. Build new Min Heap from user array
8. Build new Max Heap from user array
9. Exit

## Sample Output

```
=== Min Heap and Max Heap Implementation ===

Original unsorted array: 12 11 13 5 6 7 15 3 9 8 

--- Building Min Heap ---
Min Heap: [3, 5, 7, 9, 6, 13, 15, 12, 11, 8]

Min Heap Tree Structure:
            15
        13
            12
    7
            11
        6
            8
3
        9
    5

Min Heap Property: Parent <= Children
Root (minimum element): 3

--- Building Max Heap ---
Max Heap: [15, 12, 13, 9, 11, 7, 5, 3, 6, 8]

Max Heap Tree Structure:
            5
        7
            3
    13
            6
        9
            8
15
        11
    12

Max Heap Property: Parent >= Children
Root (maximum element): 15

--- Extract Operations ---
Extracting minimum from min heap: 3
Min Heap: [5, 6, 7, 9, 8, 13, 15, 12, 11]

Extracting maximum from max heap: 15
Max Heap: [13, 12, 8, 9, 11, 7, 5, 3, 6]

--- Insert Operations ---
Inserting 2 into min heap
Min Heap: [2, 5, 7, 9, 6, 13, 15, 12, 11, 8]

Min Heap Tree Structure:
            15
        13
            12
    7
            11
        6
            8
2
        9
    5

Inserting 20 into max heap
Max Heap: [20, 13, 8, 9, 12, 7, 5, 3, 6, 11]

Max Heap Tree Structure:
            5
        7
            3
    8
            6
        9
            11
20
        12
    13

--- Interactive Mode ---

1. Insert into Min Heap
2. Extract from Min Heap
3. Display Min Heap
4. Insert into Max Heap
5. Extract from Max Heap
6. Display Max Heap
7. Build new Min Heap from array
8. Build new Max Heap from array
9. Exit
Enter choice: 7
Enter number of elements: 5
Enter 5 elements: 25 10 15 30 5
Min Heap: [5, 10, 15, 30, 25]

1. Insert into Min Heap
2. Extract from Min Heap
3. Display Min Heap
4. Insert into Max Heap
5. Extract from Max Heap
6. Display Max Heap
7. Build new Min Heap from array
8. Build new Max Heap from array
9. Exit
Enter choice: 3
Min Heap: [5, 10, 15, 30, 25]

Min Heap Tree Structure:
        25
    15
        30
5
    10

1. Insert into Min Heap
2. Extract from Min Heap
3. Display Min Heap
4. Insert into Max Heap
5. Extract from Max Heap
6. Display Max Heap
7. Build new Min Heap from array
8. Build new Max Heap from array
9. Exit
Enter choice: 9
Exiting...
```

## Heap Applications

### Min Heap
- Priority Queue (process with smallest priority first)
- Dijkstra's shortest path algorithm
- Huffman coding
- K largest elements
- Median maintenance

### Max Heap
- Priority Queue (process with largest priority first)
- Heap Sort algorithm
- K smallest elements
- Job scheduling

## Time Complexity Summary

| Operation | Time Complexity |
|-----------|----------------|
| Build Heap | O(n) |
| Insert | O(log n) |
| Extract Min/Max | O(log n) |
| Get Min/Max | O(1) |
| Heapify | O(log n) |
| Search | O(n) |

## Space Complexity
- O(n) for storing n elements
- O(log n) for recursion stack during heapify

## Key Concepts

1. **Complete Binary Tree**: Heap is a complete binary tree stored as array
2. **Heap Property**: Relationship between parent and children
3. **Efficient Construction**: Build heap in O(n) time
4. **Priority Queue**: Main application of heap
5. **In-place Algorithm**: Heap operations don't require extra space