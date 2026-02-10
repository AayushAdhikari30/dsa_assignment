#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// Function to insert at the end
void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfterNode(Node *prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL!\n");
        return;
    }
    
    Node *newNode = createNode(data);
    
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    
    prevNode->next = newNode;
    
    printf("Inserted %d after node with value %d\n", data, prevNode->data);
}

// Function to find a node with given data
Node* findNode(Node *head, int data) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to delete a specific node
void deleteNode(Node **head, Node *delNode) {
    if (*head == NULL || delNode == NULL) {
        printf("Cannot delete: Invalid node or empty list!\n");
        return;
    }
    
    // If node to be deleted is head
    if (*head == delNode) {
        *head = delNode->next;
    }
    
    // Change next only if node to be deleted is NOT the last node
    if (delNode->next != NULL) {
        delNode->next->prev = delNode->prev;
    }
    
    // Change prev only if node to be deleted is NOT the first node
    if (delNode->prev != NULL) {
        delNode->prev->next = delNode->next;
    }
    
    printf("Deleted node with value %d\n", delNode->data);
    free(delNode);
}

// Function to delete node by value
void deleteByValue(Node **head, int data) {
    Node *nodeToDelete = findNode(*head, data);
    
    if (nodeToDelete == NULL) {
        printf("Node with value %d not found!\n", data);
        return;
    }
    
    deleteNode(head, nodeToDelete);
}

void displayForward(Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Forward: NULL <-> ");
    Node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf(" <-> NULL\n");
}

void displayBackward(Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    printf("Backward: NULL <-> ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->prev != NULL) {
            printf(" <-> ");
        }
        temp = temp->prev;
    }
    printf(" <-> NULL\n");
}

int getLength(Node *head) {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void freeList(Node **head) {
    Node *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    printf("List memory freed.\n");
}

int main() {
    Node *head = NULL;
    
    
    // Build initial list
    printf("Building doubly linked list...\n");
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
    printf("\nInitial List:\n");
    displayForward(head);
    displayBackward(head);
    printf("Length: %d\n", getLength(head));
    
    Node *node = findNode(head, 20);
    if (node != NULL) {
        printf("Found node with value 20\n");
        insertAfterNode(node, 25);
        displayForward(head);
    }
    
    node = findNode(head, 40);
    if (node != NULL) {
        printf("\nFound node with value 40\n");
        insertAfterNode(node, 45);
        displayForward(head);
    }
    
    // Insert at beginning
    printf("\nInserting 5 at beginning:\n");
    insertAtBeginning(&head, 5);
    displayForward(head);
    
    // Demonstrate deleteNode
    printf("Deleting node with value 25:\n");
    deleteByValue(&head, 25);
    displayForward(head);
    
    printf("\nDeleting node with value 5 (head):\n");
    deleteByValue(&head, 5);
    displayForward(head);
    
    printf("\nDeleting node with value 50 (tail):\n");
    deleteByValue(&head, 50);
    displayForward(head);
    
    printf("\nDeleting node with value 30 (middle):\n");
    deleteByValue(&head, 30);
    displayForward(head);
    displayBackward(head);
    
    // Interactive mode
    int choice, value, afterValue;
    
    while (1) {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after node\n");
        printf("4. Delete node by value\n");
        printf("5. Display forward\n");
        printf("6. Display backward\n");
        printf("7. Display length\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                printf("Inserted %d at beginning\n", value);
                displayForward(head);
                break;
                
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                printf("Inserted %d at end\n", value);
                displayForward(head);
                break;
                
            case 3:
                printf("Enter value of node to insert after: ");
                scanf("%d", &afterValue);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                node = findNode(head, afterValue);
                if (node != NULL) {
                    insertAfterNode(node, value);
                    displayForward(head);
                } else {
                    printf("Node with value %d not found!\n", afterValue);
                }
                break;
                
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(&head, value);
                displayForward(head);
                break;
                
            case 5:
                displayForward(head);
                break;
                
            case 6:
                displayBackward(head);
                break;
                
            case 7:
                printf("List length: %d\n", getLength(head));
                break;
                
            case 8:
                printf("Exiting...\n");
                freeList(&head);
                return 0;
                
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}