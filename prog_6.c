#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Min Heap structure
typedef struct {
    int arr[MAX_SIZE];
    int size;
} MinHeap;

// Max Heap structure
typedef struct {
    int arr[MAX_SIZE];
    int size;
} MaxHeap;

// Helper function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


// Initialize min heap
void initMinHeap(MinHeap *heap) {
    heap->size = 0;
}

// Get parent index
int getParent(int i) {
    return (i - 1) / 2;
}

// Get left child index
int getLeftChild(int i) {
    return 2 * i + 1;
}

// Get right child index
int getRightChild(int i) {
    return 2 * i + 2;
}

// Heapify down for min heap
void minHeapifyDown(MinHeap *heap, int i) {
    int smallest = i;
    int left = getLeftChild(i);
    int right = getRightChild(i);
    
    if (left < heap->size && heap->arr[left] < heap->arr[smallest]) {
        smallest = left;
    }
    
    if (right < heap->size && heap->arr[right] < heap->arr[smallest]) {
        smallest = right;
    }
    
    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        minHeapifyDown(heap, smallest);
    }
}

// Heapify up for min heap
void minHeapifyUp(MinHeap *heap, int i) {
    if (i && heap->arr[getParent(i)] > heap->arr[i]) {
        swap(&heap->arr[i], &heap->arr[getParent(i)]);
        minHeapifyUp(heap, getParent(i));
    }
}

// Build min heap from array
void buildMinHeap(MinHeap *heap, int arr[], int n) {
    if (n > MAX_SIZE) {
        printf("Array size exceeds maximum heap size!\n");
        return;
    }
    
    heap->size = n;
    for (int i = 0; i < n; i++) {
        heap->arr[i] = arr[i];
    }
    
    // Start from last non-leaf node and heapify down
    for (int i = (n / 2) - 1; i >= 0; i--) {
        minHeapifyDown(heap, i);
    }
}

// Insert into min heap
void insertMinHeap(MinHeap *heap, int value) {
    if (heap->size >= MAX_SIZE) {
        printf("Heap overflow!\n");
        return;
    }
    
    heap->arr[heap->size] = value;
    heap->size++;
    minHeapifyUp(heap, heap->size - 1);
}

// Extract minimum
int extractMin(MinHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap is empty!\n");
        return -1;
    }
    
    int min = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    minHeapifyDown(heap, 0);
    
    return min;
}

// Display min heap
void displayMinHeap(MinHeap *heap) {
    printf("Min Heap: [");
    for (int i = 0; i < heap->size; i++) {
        printf("%d", heap->arr[i]);
        if (i < heap->size - 1) printf(", ");
    }
    printf("]\n");
}


// Initialize max heap
void initMaxHeap(MaxHeap *heap) {
    heap->size = 0;
}

// Heapify down for max heap
void maxHeapifyDown(MaxHeap *heap, int i) {
    int largest = i;
    int left = getLeftChild(i);
    int right = getRightChild(i);
    
    if (left < heap->size && heap->arr[left] > heap->arr[largest]) {
        largest = left;
    }
    
    if (right < heap->size && heap->arr[right] > heap->arr[largest]) {
        largest = right;
    }
    
    if (largest != i) {
        swap(&heap->arr[i], &heap->arr[largest]);
        maxHeapifyDown(heap, largest);
    }
}

// Heapify up for max heap
void maxHeapifyUp(MaxHeap *heap, int i) {
    if (i && heap->arr[getParent(i)] < heap->arr[i]) {
        swap(&heap->arr[i], &heap->arr[getParent(i)]);
        maxHeapifyUp(heap, getParent(i));
    }
}

// Build max heap from array
void buildMaxHeap(MaxHeap *heap, int arr[], int n) {
    if (n > MAX_SIZE) {
        printf("Array size exceeds maximum heap size!\n");
        return;
    }
    
    heap->size = n;
    for (int i = 0; i < n; i++) {
        heap->arr[i] = arr[i];
    }
    
    // Start from last non-leaf node and heapify down
    for (int i = (n / 2) - 1; i >= 0; i--) {
        maxHeapifyDown(heap, i);
    }
}

// Insert into max heap
void insertMaxHeap(MaxHeap *heap, int value) {
    if (heap->size >= MAX_SIZE) {
        printf("Heap overflow!\n");
        return;
    }
    
    heap->arr[heap->size] = value;
    heap->size++;
    maxHeapifyUp(heap, heap->size - 1);
}

// Extract maximum
int extractMax(MaxHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap is empty!\n");
        return -1;
    }
    
    int max = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    maxHeapifyDown(heap, 0);
    
    return max;
}

// Display max heap
void displayMaxHeap(MaxHeap *heap) {
    printf("Max Heap: [");
    for (int i = 0; i < heap->size; i++) {
        printf("%d", heap->arr[i]);
        if (i < heap->size - 1) printf(", ");
    }
    printf("]\n");
}


void printHeapTree(int arr[], int n, int i, int level) {
    if (i < n) {
        printHeapTree(arr, n, getRightChild(i), level + 1);
        
        for (int j = 0; j < level; j++) {
            printf("    ");
        }
        printf("%d\n", arr[i]);
        
        printHeapTree(arr, n, getLeftChild(i), level + 1);
    }
}

void visualizeMinHeap(MinHeap *heap) {
    printf("\nMin Heap Tree Structure:\n");
    printHeapTree(heap->arr, heap->size, 0, 0);
}

void visualizeMaxHeap(MaxHeap *heap) {
    printf("\nMax Heap Tree Structure:\n");
    printHeapTree(heap->arr, heap->size, 0, 0);
}


int main() {
    printf("=== Min Heap and Max Heap Implementation ===\n\n");
    
    // Test data (unsorted array)
    int data[] = {12, 11, 13, 5, 6, 7, 15, 3, 9, 8};
    int n = sizeof(data) / sizeof(data[0]);
    
    printf("Original unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n\n");
    
    // Build Min Heap
    printf("--- Building Min Heap ---\n");
    MinHeap minHeap;
    initMinHeap(&minHeap);
    buildMinHeap(&minHeap, data, n);
    displayMinHeap(&minHeap);
    visualizeMinHeap(&minHeap);
    
    printf("\nMin Heap Property: Parent <= Children\n");
    printf("Root (minimum element): %d\n", minHeap.arr[0]);
    
    // Build Max Heap
    printf("\n--- Building Max Heap ---\n");
    MaxHeap maxHeap;
    initMaxHeap(&maxHeap);
    buildMaxHeap(&maxHeap, data, n);
    displayMaxHeap(&maxHeap);
    visualizeMaxHeap(&maxHeap);
    
    printf("\nMax Heap Property: Parent >= Children\n");
    printf("Root (maximum element): %d\n", maxHeap.arr[0]);
    
    // Demonstrate extract operations
    printf("\n--- Extract Operations ---\n");
    printf("Extracting minimum from min heap: %d\n", extractMin(&minHeap));
    displayMinHeap(&minHeap);
    
    printf("\nExtracting maximum from max heap: %d\n", extractMax(&maxHeap));
    displayMaxHeap(&maxHeap);
    
    // Demonstrate insert operations
    printf("\n--- Insert Operations ---\n");
    printf("Inserting 2 into min heap\n");
    insertMinHeap(&minHeap, 2);
    displayMinHeap(&minHeap);
    visualizeMinHeap(&minHeap);
    
    printf("\nInserting 20 into max heap\n");
    insertMaxHeap(&maxHeap, 20);
    displayMaxHeap(&maxHeap);
    visualizeMaxHeap(&maxHeap);
    
    // Interactive mode
    printf("\n--- Interactive Mode ---\n");
    int choice, value;
    
    while (1) {
        printf("\n1. Insert into Min Heap\n");
        printf("2. Extract from Min Heap\n");
        printf("3. Display Min Heap\n");
        printf("4. Insert into Max Heap\n");
        printf("5. Extract from Max Heap\n");
        printf("6. Display Max Heap\n");
        printf("7. Build new Min Heap from array\n");
        printf("8. Build new Max Heap from array\n");
        printf("9. Exit\n");
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
                insertMinHeap(&minHeap, value);
                displayMinHeap(&minHeap);
                break;
                
            case 2:
                value = extractMin(&minHeap);
                if (value != -1) {
                    printf("Extracted minimum: %d\n", value);
                    displayMinHeap(&minHeap);
                }
                break;
                
            case 3:
                displayMinHeap(&minHeap);
                visualizeMinHeap(&minHeap);
                break;
                
            case 4:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertMaxHeap(&maxHeap, value);
                displayMaxHeap(&maxHeap);
                break;
                
            case 5:
                value = extractMax(&maxHeap);
                if (value != -1) {
                    printf("Extracted maximum: %d\n", value);
                    displayMaxHeap(&maxHeap);
                }
                break;
                
            case 6:
                displayMaxHeap(&maxHeap);
                visualizeMaxHeap(&maxHeap);
                break;
                
            case 7: {
                printf("Enter number of elements: ");
                int count;
                scanf("%d", &count);
                if (count > MAX_SIZE) {
                    printf("Too many elements!\n");
                    break;
                }
                int *newData = (int*)malloc(count * sizeof(int));
                printf("Enter %d elements: ", count);
                for (int i = 0; i < count; i++) {
                    scanf("%d", &newData[i]);
                }
                initMinHeap(&minHeap);
                buildMinHeap(&minHeap, newData, count);
                displayMinHeap(&minHeap);
                free(newData);
                break;
            }
                
            case 8: {
                printf("Enter number of elements: ");
                int count;
                scanf("%d", &count);
                if (count > MAX_SIZE) {
                    printf("Too many elements!\n");
                    break;
                }
                int *newData = (int*)malloc(count * sizeof(int));
                printf("Enter %d elements: ", count);
                for (int i = 0; i < count; i++) {
                    scanf("%d", &newData[i]);
                }
                initMaxHeap(&maxHeap);
                buildMaxHeap(&maxHeap, newData, count);
                displayMaxHeap(&maxHeap);
                free(newData);
                break;
            }
                
            case 9:
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}