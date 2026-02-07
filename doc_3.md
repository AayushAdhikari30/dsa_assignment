# Program 3: Reverse Traversal in Linked List

## Data Structures

### Node Structure
```c
typedef struct Node {
    int data;
    struct Node *next;
} Node;
```
- **data**: Integer value stored in the node
- **next**: Pointer to the next node in the list

## Functions Implemented

### 1. `Node* createNode(int data)`
- **Purpose**: Create and initialize a new node
- **Parameters**: Integer data value
- **Returns**: Pointer to newly created node
- **Operation**: Allocates memory, sets data, and initializes next to NULL

### 2. `void insertAtEnd(Node **head, int data)`
- **Purpose**: Insert a new node at the end of the list
- **Parameters**: Double pointer to head and data value
- **Operation**: 
  - If list is empty, new node becomes head
  - Otherwise, traverse to end and append new node

### 3. `void forwardTraversal(Node *head)`
- **Purpose**: Display list from head to tail (normal traversal)
- **Parameters**: Pointer to head
- **Output**: Prints nodes in format: 10 -> 20 -> 30

### 4. `void reverseTraversalRecursive(Node *head)`
- **Purpose**: Recursively traverse and print list in reverse
- **Algorithm**:
  1. Recursively call function for next node
  2. Print current node data while backtracking
- **Time Complexity**: O(n)
- **Space Complexity**: O(n) due to recursion stack

### 5. `void reverseTraversalRecursiveWrapper(Node *head)`
- **Purpose**: Wrapper function that handles edge cases and formatting
- **Parameters**: Pointer to head
- **Output**: Prints nodes in reverse: 50 <- 40 <- 30 <- 20 <- 10

### 6. `void reverseTraversalStack(Node *head)`
- **Purpose**: Use explicit stack to traverse in reverse
- **Algorithm**:
  1. Count total nodes
  2. Create array to act as stack
  3. Push all node pointers onto stack
  4. Pop and print in reverse order
- **Time Complexity**: O(n)
- **Space Complexity**: O(n) for stack array

### 7. `Node* reverseList(Node *head)`
- **Purpose**: Reverse the linked list by changing pointers
- **Algorithm**:
  1. Use three pointers: prev, current, next
  2. Iterate through list reversing next pointers
  3. Return new head (previously tail)
- **Returns**: New head of reversed list

### 8. `void reverseTraversalByReversingList(Node **head)`
- **Purpose**: Print reverse by actually reversing the list twice
- **Algorithm**:
  1. Reverse the list
  2. Print forward
  3. Reverse back to restore original order
- **Time Complexity**: O(n)
- **Space Complexity**: O(1) - most efficient

### 9. `void displayList(Node *head)`
- **Purpose**: Helper function to display current list state
- **Parameters**: Pointer to head

### 10. `void freeList(Node **head)`
- **Purpose**: Free all memory allocated for the list
- **Parameters**: Double pointer to head
- **Operation**: Iterates through list freeing each node

## Main Method Organization

### 1. Demonstration Phase
- Creates linked list with values: 10, 20, 30, 40, 50
- Displays original list
- Shows forward traversal
- Demonstrates all three reverse traversal methods with complexity analysis

### 2. Interactive Mode
Provides menu-driven interface:
- Option 1: Insert new element
- Option 2: Display forward
- Option 3: Display reverse (recursive method)
- Option 4: Display reverse (stack method)
- Option 5: Display reverse (list reversal method)
- Option 6: Exit and cleanup

## Sample Output

```
=== Linked List Reverse Traversal Demonstration ===

Building the linked list...
Current List: 10 -> 20 -> 30 -> 40 -> 50

Forward Traversal: 10 -> 20 -> 30 -> 40 -> 50

--- Method 1: Using Recursion ---
Reverse Traversal (Recursive): 50 <- 40 <- 30 <- 20 <- 10
Time Complexity: O(n), Space Complexity: O(n) [recursion stack]

--- Method 2: Using Stack ---
Reverse Traversal (Stack): 50 <- 40 <- 30 <- 20 <- 10
Time Complexity: O(n), Space Complexity: O(n) [explicit stack]

--- Method 3: By Reversing List ---
Reverse Traversal (List Reversal): 50 -> 40 -> 30 -> 20 -> 10
Time Complexity: O(n), Space Complexity: O(1)

Verification - Original list preserved:
Current List: 10 -> 20 -> 30 -> 40 -> 50

--- Interactive Mode ---

1. Insert element
2. Display forward
3. Display reverse (recursive)
4. Display reverse (stack)
5. Display reverse (list reversal)
6. Exit
Enter choice: 1
Enter value to insert: 60
Inserted 60

1. Insert element
2. Display forward
3. Display reverse (recursive)
4. Display reverse (stack)
5. Display reverse (list reversal)
6. Exit
Enter choice: 3
Reverse Traversal (Recursive): 60 <- 50 <- 40 <- 30 <- 20 <- 10

1. Insert element
2. Display forward
3. Display reverse (recursive)
4. Display reverse (stack)
5. Display reverse (list reversal)
6. Exit
Enter choice: 6
Exiting...
```

## Algorithm Comparison

| Method | Time Complexity | Space Complexity | Advantages |
|--------|----------------|------------------|------------|
| Recursive | O(n) | O(n) | Simple, elegant code |
| Stack | O(n) | O(n) | Explicit control, no recursion |
| List Reversal | O(n) | O(1) | Memory efficient |

## Key Concepts Demonstrated

1. **Recursion**: Using call stack for reverse traversal
2. **Stack Data Structure**: Explicit stack implementation
3. **Pointer Manipulation**: Reversing linked list
4. **Memory Management**: Dynamic allocation and deallocation
5. **Multiple Approaches**: Different solutions to same problem