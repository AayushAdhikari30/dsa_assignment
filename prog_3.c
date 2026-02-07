#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

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
}

void forwardTraversal(Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Forward Traversal: ");
    Node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

void reverseTraversalRecursive(Node *head) {
    if (head == NULL) {
        return;
    }
    
    reverseTraversalRecursive(head->next);
    
    printf("%d", head->data);
    if (head->next != NULL) {
        printf(" <- ");
    }
}

void reverseTraversalRecursiveWrapper(Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Reverse Traversal (Recursive): ");
    reverseTraversalRecursive(head);
    printf("\n");
}

void reverseTraversalStack(Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    Node **stack = (Node**)malloc(count * sizeof(Node*));
    
    temp = head;
    int i = 0;
    while (temp != NULL) {
        stack[i++] = temp;
        temp = temp->next;
    }
    
    printf("Reverse Traversal (Stack): ");
    for (i = count - 1; i >= 0; i--) {
        printf("%d", stack[i]->data);
        if (i > 0) {
            printf(" <- ");
        }
    }
    printf("\n");
    
    free(stack);
}

Node* reverseList(Node *head) {
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

void reverseTraversalByReversingList(Node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Reverse Traversal (List Reversal): ");
    
    *head = reverseList(*head);
    
    Node *temp = *head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
    
    *head = reverseList(*head);
}

void displayList(Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Current List: ");
    Node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

void freeList(Node **head) {
    Node *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    Node *head = NULL;
    
    
    
    printf("Building the linked list...\n");
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
    displayList(head);
    printf("\n");
    
    forwardTraversal(head);
    printf("\n");
    
    printf("Method 1: Using Recursion\n");
    reverseTraversalRecursiveWrapper(head);
    printf("Time Complexity: O(n), Space Complexity: O(n) [recursion stack]\n\n");
    
    printf("Method 2: Using Stack\n");
    reverseTraversalStack(head);
    printf("Time Complexity: O(n), Space Complexity: O(n) [explicit stack]\n\n");
    
    printf(" By Reversing List \n");
    reverseTraversalByReversingList(&head);
    printf("Time Complexity: O(n), Space Complexity: O(1)\n\n");
    
    printf(" Original list preserved:\n");
    displayList(head);
    
    
    int choice, value;
    
    while (1) {
        printf("\n1. Insert element\n");
        printf("2. Display forward\n");
        printf("3. Display reverse (recursive)\n");
        printf("4. Display reverse (stack)\n");
        printf("5. Display reverse (list reversal)\n");
        printf("6. Exit\n");
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
                insertAtEnd(&head, value);
                printf("Inserted %d\n", value);
                break;
            case 2:
                forwardTraversal(head);
                break;
            case 3:
                reverseTraversalRecursiveWrapper(head);
                break;
            case 4:
                reverseTraversalStack(head);
                break;
            case 5:
                reverseTraversalByReversingList(&head);
                break;
            case 6:
                printf("Exiting\n");
                freeList(&head);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}