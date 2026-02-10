# Program 4: Doubly Linked List Implementation

## Data Structures

### Node Structure
```c
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;
```
- **data**: Integer value stored in the node
- **prev**: Pointer to the previous node in the list
- **next**: Pointer to the next node in the list

This structure enables bidirectional traversal, allowing movement both forward and backward through the list.

## Functions Implemented

### 1. `Node* createNode(int data)`
- **Purpose**: Allocate and initialize a new node
- **Parameters**: Integer data value
- **Returns**: Pointer to newly created node
- **Operation**: Allocates memory, sets data, initializes prev and next to NULL

### 2. `void insertAtBeginning(Node **head, int data)`
- **Purpose**: Insert a new node at the start of the list
- **Parameters**: Double pointer to head, data value
- **Algorithm**:
  1. Create new node
  2. Point new node's next to current head
  3. Update current head's prev to new node
  4. Update head to new node
- **Time Complexity**: O(1)

### 3. `void insertAtEnd(Node **head, int data)`
- **Purpose**: Insert a new node at the end of the list
- **Parameters**: Double pointer to head, data value
- **Algorithm**:
  1. Create new node
  2. Traverse to last node
  3. Update last node's next to new node
  4. Set new node's prev to last node
- **Time Complexity**: O(n)

### 4. `void insertAfterNode(Node *prevNode, int data)`
- **Purpose**: Insert a new node after a specified node
- **Parameters**: Pointer to previous node, data value
- **Algorithm**:
  1. Validate prevNode is not NULL
  2. Create new node
  3. Set new node's next to prevNode's next
  4. Set new node's prev to prevNode
  5. Update next node's prev (if exists)
  6. Update prevNode's next to new node
- **Time Complexity**: O(1) - constant time operation
- **Key Feature**: This is the main insert operation requested in the assignment

### 5. `Node* findNode(Node *head, int data)`
- **Purpose**: Search for a node containing specific data
- **Parameters**: Pointer to head, data value to find
- **Returns**: Pointer to found node, or NULL if not found
- **Time Complexity**: O(n)

### 6. `void deleteNode(Node **head, Node *delNode)`
- **Purpose**: Delete a specific node from the list
- **Parameters**: Double pointer to head, pointer to node to delete
- **Algorithm**:
  1. Validate inputs
  2. If deleting head, update head pointer
  3. Update next node's prev pointer (if next exists)
  4. Update previous node's next pointer (if prev exists)
  5. Free the node
- **Time Complexity**: O(1) - when node pointer is known
- **Key Feature**: This is the main delete operation requested in the assignment

### 7. `void deleteByValue(Node **head, int data)`
- **Purpose**: Delete a node by searching for its value
- **Parameters**: Double pointer to head, data value
- **Algorithm**:
  1. Find the node with given value
  2. Call deleteNode to remove it
- **Time Complexity**: O(n) - due to search

### 8. `void displayForward(Node *head)`
- **Purpose**: Display the list from head to tail
- **Output Format**: `NULL <-> 10 <-> 20 <-> 30 <-> NULL`
- **Time Complexity**: O(n)

### 9. `void displayBackward(Node *head)`
- **Purpose**: Display the list from tail to head
- **Algorithm**:
  1. Traverse to last node
  2. Traverse backward using prev pointers
- **Output Format**: `NULL <-> 30 <-> 20 <-> 10 <-> NULL`
- **Time Complexity**: O(n)

### 10. `int getLength(Node *head)`
- **Purpose**: Count the number of nodes in the list
- **Returns**: Integer count of nodes
- **Time Complexity**: O(n)

### 11. `void freeList(Node **head)`
- **Purpose**: Deallocate all nodes and free memory
- **Parameters**: Double pointer to head
- **Operation**: Iterates through list freeing each node

## Main Method Organization

### 1. Demonstration Phase
- **Initial List Creation**: Builds list with values 10, 20, 30, 40, 50
- **Display Operations**: Shows forward and backward traversal
- **Insert After Demonstrations**:
  - Insert 25 after node with value 20
  - Insert 45 after node with value 40
- **Insert at Beginning**: Adds 5 at the start
- **Delete Demonstrations**:
  - Delete middle node (25)
  - Delete head node (5)
  - Delete tail node (50)
  - Delete another middle node (30)

### 2. Interactive Mode
Menu-driven interface with 8 options:
1. Insert at beginning
2. Insert at end
3. Insert after specific node
4. Delete node by value
5. Display forward
6. Display backward
7. Display length
8. Exit and cleanup

## Sample Output

```
=== Doubly Linked List Implementation ===

Building doubly linked list...

Initial List:
Forward: NULL <-> 10 <-> 20 <-> 30 <-> 40 <-> 50 <-> NULL
Backward: NULL <-> 50 <-> 40 <-> 30 <-> 20 <-> 10 <-> NULL
Length: 5

--- Demonstrating Insert After Node ---
Found node with value 20
Inserted 25 after node with value 20
Forward: NULL <-> 10 <-> 20 <-> 25 <-> 30 <-> 40 <-> 50 <-> NULL

Found node with value 40
Inserted 45 after node with value 40
Forward: NULL <-> 10 <-> 20 <-> 25 <-> 30 <-> 40 <-> 45 <-> 50 <-> NULL

Inserting 5 at beginning:
Forward: NULL <-> 5 <-> 10 <-> 20 <-> 25 <-> 30 <-> 40 <-> 45 <-> 50 <-> NULL

--- Demonstrating Delete Node ---
Deleting node with value 25:
Deleted node with value 25
Forward: NULL <-> 5 <-> 10 <-> 20 <-> 30 <-> 40 <-> 45 <-> 50 <-> NULL

Deleting node with value 5 (head):
Deleted node with value 5
Forward: NULL <-> 10 <-> 20 <-> 30 <-> 40 <-> 45 <-> 50 <-> NULL

Deleting node with value 50 (tail):
Deleted node with value 50
Forward: NULL <-> 10 <-> 20 <-> 30 <-> 40 <-> 45 <-> NULL

Deleting node with value 30 (middle):
Deleted node with value 30
Forward: NULL <-> 10 <-> 20 <-> 40 <-> 45 <-> NULL
Backward: NULL <-> 45 <-> 40 <-> 20 <-> 10 <-> NULL

--- Interactive Mode ---

1. Insert at beginning
2. Insert at end
3. Insert after node
4. Delete node by value
5. Display forward
6. Display backward
7. Display length
8. Exit
Enter choice: 3
Enter value of node to insert after: 20
Enter value to insert: 25
Inserted 25 after node with value 20
Forward: NULL <-> 10 <-> 20 <-> 25 <-> 40 <-> 45 <-> NULL

1. Insert at beginning
2. Insert at end
3. Insert after node
4. Delete node by value
5. Display forward
6. Display backward
7. Display length
8. Exit
Enter choice: 4
Enter value to delete: 25
Deleted node with value 25
Forward: NULL <-> 10 <-> 20 <-> 40 <-> 45 <-> NULL

1. Insert at beginning
2. Insert at end
3. Insert after node
4. Delete node by value
5. Display forward
6. Display backward
7. Display length
8. Exit
Enter choice: 8
Exiting...
List memory freed.
```

## Advantages of Doubly Linked List

1. **Bidirectional Traversal**: Can traverse forward and backward
2. **Efficient Deletion**: O(1) deletion when node pointer is known
3. **Easier Insertion**: Can insert before or after a given node
4. **Reverse Traversal**: No need for recursion or stack

## Disadvantages

1. **Extra Memory**: Requires additional pointer for prev
2. **Complex Operations**: More pointer updates needed
3. **Overhead**: More memory per node compared to singly linked list

## Time Complexity Summary

| Operation | Time Complexity |
|-----------|----------------|
| Insert at beginning | O(1) |
| Insert at end | O(n) |
| Insert after node | O(1) |
| Delete node (pointer known) | O(1) |
| Delete by value | O(n) |
| Search | O(n) |
| Forward traversal | O(n) |
| Backward traversal | O(n) |