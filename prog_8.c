#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
typedef struct {
    long long comparisons;
    long long swaps;
    double executionTime;
} Statistics;

void bubbleSort(int arr[], int n, Statistics *stats);
void selectionSort(int arr[], int n, Statistics *stats);
void insertionSort(int arr[], int n, Statistics *stats);
void mergeSort(int arr[], int n, Statistics *stats);
void mergeSortHelper(int arr[], int left, int right, Statistics *stats);
void merge(int arr[], int left, int mid, int right, Statistics *stats);

// Generate random array
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 1000) + 1; // Random numbers between 1 and 1000
    }
}

// Copy array
void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

// Print array
void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
        if ((i + 1) % 20 == 0 && i < n - 1) printf("\n ");
    }
    printf("]\n");
}

// Initialize statistics
void initStats(Statistics *stats) {
    stats->comparisons = 0;
    stats->swaps = 0;
    stats->executionTime = 0.0;
}

// Display statistics
void displayStats(Statistics *stats, const char *algorithmName) {
    printf("\n--- %s Statistics ---\n", algorithmName);
    printf("Comparisons: %lld\n", stats->comparisons);
    printf("Swaps: %lld\n", stats->swaps);
    printf("Execution Time: %.6f seconds\n", stats->executionTime);
}

void bubbleSort(int arr[], int n, Statistics *stats) {
    clock_t start = clock();
    
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            stats->comparisons++;
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                stats->swaps++;
                swapped = true;
            }
        }
        // If no swaps occurred, array is sorted
        if (!swapped) break;
    }
    
    clock_t end = clock();
    stats->executionTime = ((double)(end - start)) / CLOCKS_PER_SEC;
}

void selectionSort(int arr[], int n, Statistics *stats) {
    clock_t start = clock();
    
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        
        // Find minimum element in unsorted portion
        for (int j = i + 1; j < n; j++) {
            stats->comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap minimum with first unsorted element
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            stats->swaps++;
        }
    }
    
    clock_t end = clock();
    stats->executionTime = ((double)(end - start)) / CLOCKS_PER_SEC;
}

void insertionSort(int arr[], int n, Statistics *stats) {
    clock_t start = clock();
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements greater than key one position ahead
        while (j >= 0) {
            stats->comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                stats->swaps++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
    
    clock_t end = clock();
    stats->executionTime = ((double)(end - start)) / CLOCKS_PER_SEC;
}

void merge(int arr[], int left, int mid, int right, Statistics *stats) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));
    
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    
    // Merge the temporary arrays back
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        stats->comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        stats->swaps++; // Count array assignments as swaps
        k++;
    }
    
    // Copy remaining elements
    while (i < n1) {
        arr[k] = L[i];
        stats->swaps++;
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        stats->swaps++;
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

void mergeSortHelper(int arr[], int left, int right, Statistics *stats) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSortHelper(arr, left, mid, stats);
        mergeSortHelper(arr, mid + 1, right, stats);
        merge(arr, left, mid, right, stats);
    }
}

void mergeSort(int arr[], int n, Statistics *stats) {
    clock_t start = clock();
    
    mergeSortHelper(arr, 0, n - 1, stats);
    
    clock_t end = clock();
    stats->executionTime = ((double)(end - start)) / CLOCKS_PER_SEC;
}

int main() {
    int n, choice;
    
    printf("=== Sorting Algorithms Comparison ===\n\n");
    
    // Get array size from user
    printf("Enter the number of random integers to generate (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input!\n");
        return 1;
    }
    
    if (n > 100000) {
        printf("Warning: Large array size may take significant time.\n");
    }
    
    // Seed random number generator
    srand(time(NULL));
    
    // Allocate arrays
    int *original = (int*)malloc(n * sizeof(int));
    int *working = (int*)malloc(n * sizeof(int));
    
    if (original == NULL || working == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Generate random array
    generateRandomArray(original, n);
    
    printf("\nGenerated %d random integers.\n", n);
    
    // Display first few elements if array is large
    if (n <= 50) {
        printf("\nOriginal array:\n");
        printArray(original, n);
    } else {
        printf("\nFirst 20 elements of original array:\n");
        printf("[");
        for (int i = 0; i < 20; i++) {
            printf("%d", original[i]);
            if (i < 19) printf(", ");
        }
        printf(", ...]\n");
    }
    
    // Choose sorting algorithm
    printf("\n--- Choose Sorting Algorithm ---\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("Enter your choice (1-4): ");
    
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input!\n");
        free(original);
        free(working);
        return 1;
    }
    
    // Copy original array to working array
    copyArray(original, working, n);
    
    Statistics stats;
    initStats(&stats);
    
    printf("\nSorting...\n");
    
    switch (choice) {
        case 1:
            bubbleSort(working, n, &stats);
            displayStats(&stats, "Bubble Sort");
            break;
            
        case 2:
            selectionSort(working, n, &stats);
            displayStats(&stats, "Selection Sort");
            break;
            
        case 3:
            insertionSort(working, n, &stats);
            displayStats(&stats, "Insertion Sort");
            break;
            
        case 4:
            mergeSort(working, n, &stats);
            displayStats(&stats, "Merge Sort");
            printf("Note: For merge sort, 'swaps' represent array assignments.\n");
            break;
            
        default:
            printf("Invalid choice!\n");
            free(original);
            free(working);
            return 1;
    }
    
    // Display sorted array
    if (n <= 50) {
        printf("\nSorted array:\n");
        printArray(working, n);
    } else {
        printf("\nFirst 20 elements of sorted array:\n");
        printf("[");
        for (int i = 0; i < 20; i++) {
            printf("%d", working[i]);
            if (i < 19) printf(", ");
        }
        printf(", ...]\n");
        
        printf("\nLast 20 elements of sorted array:\n");
        printf("[..., ");
        for (int i = n - 20; i < n; i++) {
            printf("%d", working[i]);
            if (i < n - 1) printf(", ");
        }
        printf("]\n");
    }
    
    // Verify sorting
    bool isSorted = true;
    for (int i = 0; i < n - 1; i++) {
        if (working[i] > working[i + 1]) {
            isSorted = false;
            break;
        }
    }
    
    if (isSorted) {
        printf("\n✓ Array is correctly sorted!\n");
    } else {
        printf("\n✗ Error: Array is not properly sorted!\n");
    }
    
    // Comparison mode
    printf("\n\n--- Want to compare all algorithms? (y/n): ");
    char compare;
    scanf(" %c", &compare);
    
    if (compare == 'y' || compare == 'Y') {
        printf("Array size: %d\n", n);
        
        Statistics bubbleStats, selectionStats, insertionStats, mergeStats;
        int *arr1 = (int*)malloc(n * sizeof(int));
        int *arr2 = (int*)malloc(n * sizeof(int));
        int *arr3 = (int*)malloc(n * sizeof(int));
        int *arr4 = (int*)malloc(n * sizeof(int));
        
        // Bubble Sort
        copyArray(original, arr1, n);
        initStats(&bubbleStats);
        bubbleSort(arr1, n, &bubbleStats);
        
        // Selection Sort
        copyArray(original, arr2, n);
        initStats(&selectionStats);
        selectionSort(arr2, n, &selectionStats);
        
        // Insertion Sort
        copyArray(original, arr3, n);
        initStats(&insertionStats);
        insertionSort(arr3, n, &insertionStats);
        
        // Merge Sort
        copyArray(original, arr4, n);
        initStats(&mergeStats);
        mergeSort(arr4, n, &mergeStats);
        
        // Display comparison table
        printf("\n%-20s %-15s %-15s %-20s\n", "Algorithm", "Comparisons", "Swaps", "Time (seconds)");
        printf("%-20s %-15lld %-15lld %-20.6f\n", "Bubble Sort", bubbleStats.comparisons, bubbleStats.swaps, bubbleStats.executionTime);
        printf("%-20s %-15lld %-15lld %-20.6f\n", "Selection Sort", selectionStats.comparisons, selectionStats.swaps, selectionStats.executionTime);
        printf("%-20s %-15lld %-15lld %-20.6f\n", "Insertion Sort", insertionStats.comparisons, insertionStats.swaps, insertionStats.executionTime);
        printf("%-20s %-15lld %-15lld %-20.6f\n", "Merge Sort", mergeStats.comparisons, mergeStats.swaps, mergeStats.executionTime);
        
        free(arr1);
        free(arr2);
        free(arr3);
        free(arr4);
    }
    
    // Cleanup
    free(original);
    free(working);
    
    return 0;
}