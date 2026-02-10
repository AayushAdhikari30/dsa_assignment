# Program 8: Sorting Algorithms with Performance Analysis

## Data Structures

### Statistics Structure
```c
typedef struct {
    long long comparisons;
    long long swaps;
    double executionTime;
} Statistics;
```
- **comparisons**: Total number of element comparisons
- **swaps**: Total number of element swaps or assignments
- **executionTime**: Time taken to sort in seconds

## Functions Implemented

### Utility Functions

#### 1. `void generateRandomArray(int arr[], int n)`
- **Purpose**: Fill array with random integers between 1 and 1000
- **Parameters**: Array pointer, array size
- **Uses**: `rand()` function seeded with current time

#### 2. `void copyArray(int source[], int dest[], int n)`
- **Purpose**: Create a copy of an array
- **Parameters**: Source array, destination array, size
- **Used**: To preserve original array for multiple algorithm runs

#### 3. `void printArray(int arr[], int n)`
- **Purpose**: Display array contents
- **Features**: Formats output, line breaks every 20 elements

#### 4. `void initStats(Statistics *stats)`
- **Purpose**: Initialize statistics structure to zero
- **Parameters**: Pointer to Statistics structure

#### 5. `void displayStats(Statistics *stats, const char *algorithmName)`
- **Purpose**: Display sorting statistics
- **Output**: Algorithm name, comparisons, swaps, execution time

### Sorting Algorithms

#### 6. `void bubbleSort(int arr[], int n, Statistics *stats)`
- **Purpose**: Sort array using bubble sort algorithm
- **Algorithm**:
  1. Repeatedly step through the list
  2. Compare adjacent elements and swap if in wrong order
  3. Repeat until no swaps needed
  4. Optimization: Stop if no swaps in a pass
- **Time Complexity**:
  - Best: O(n) - when already sorted
  - Average: O(n²)
  - Worst: O(n²)
- **Space Complexity**: O(1)
- **Stable**: Yes
- **Features**: Counts comparisons and swaps, measures execution time

#### 7. `void selectionSort(int arr[], int n, Statistics *stats)`
- **Purpose**: Sort array using selection sort algorithm
- **Algorithm**:
  1. Find minimum element in unsorted portion
  2. Swap it with first unsorted element
  3. Move boundary of sorted portion
  4. Repeat until array is sorted
- **Time Complexity**:
  - Best: O(n²)
  - Average: O(n²)
  - Worst: O(n²)
- **Space Complexity**: O(1)
- **Stable**: No (this implementation)
- **Features**: Fewer swaps than bubble sort

#### 8. `void insertionSort(int arr[], int n, Statistics *stats)`
- **Purpose**: Sort array using insertion sort algorithm
- **Algorithm**:
  1. Start with second element
  2. Compare with elements in sorted portion
  3. Shift larger elements right
  4. Insert element in correct position
  5. Repeat for all elements
- **Time Complexity**:
  - Best: O(n) - when already sorted
  - Average: O(n²)
  - Worst: O(n²)
- **Space Complexity**: O(1)
- **Stable**: Yes
- **Features**: Efficient for small or nearly sorted arrays

#### 9. `void merge(int arr[], int left, int mid, int right, Statistics *stats)`
- **Purpose**: Merge two sorted subarrays
- **Algorithm**:
  1. Create temporary arrays for left and right halves
  2. Compare elements and merge in sorted order
  3. Copy remaining elements
- **Parameters**: Array, left index, middle index, right index
- **Used by**: mergeSortHelper

#### 10. `void mergeSortHelper(int arr[], int left, int right, Statistics *stats)`
- **Purpose**: Recursive helper for merge sort
- **Algorithm**:
  1. Divide array into two halves
  2. Recursively sort each half
  3. Merge the sorted halves
- **Parameters**: Array, left boundary, right boundary

#### 11. `void mergeSort(int arr[], int n, Statistics *stats)`
- **Purpose**: Sort array using merge sort algorithm
- **Algorithm**: Divide and conquer approach
  1. Divide array into halves recursively
  2. Sort each half
  3. Merge sorted halves
- **Time Complexity**:
  - Best: O(n log n)
  - Average: O(n log n)
  - Worst: O(n log n)
- **Space Complexity**: O(n) - for temporary arrays
- **Stable**: Yes
- **Features**: Most efficient for large datasets, predictable performance

## Main Method Organization

### 1. Input Phase
- Get array size N from user
- Validate input
- Warn if N is very large
- Allocate memory for arrays

### 2. Array Generation
- Seed random number generator with current time
- Generate N random integers (1-1000)
- Display array (or first 20 elements if large)

### 3. Algorithm Selection
- Display menu with 4 sorting options
- Get user choice
- Create working copy of original array

### 4. Sorting Phase
- Initialize statistics
- Execute chosen sorting algorithm
- Track comparisons, swaps, and execution time
- Display statistics

### 5. Verification
- Display sorted array
- Verify correctness by checking order
- Display success or error message

### 6. Comparison Mode (Optional)
- Ask user if they want to compare all algorithms
- Run all four algorithms on the same data
- Display comparison table with all statistics

## Sample Output

```
=== Sorting Algorithms Comparison ===

Enter the number of random integers to generate (N): 1000

Generated 1000 random integers.

First 20 elements of original array:
[734, 248, 912, 67, 523, 891, 456, 123, 789, 234, 567, 890, 345, 678, 901, 234, 567, 890, 123, 456, ...]

--- Choose Sorting Algorithm ---
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter your choice (1-4): 4

Sorting...

--- Merge Sort Statistics ---
Comparisons: 8697
Swaps: 9976
Execution Time: 0.001234 seconds

First 20 elements of sorted array:
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, ...]

Last 20 elements of sorted array:
[..., 981, 982, 983, 984, 985, 986, 987, 988, 989, 990, 991, 992, 993, 994, 995, 996, 997, 998, 999, 1000]

✓ Array is correctly sorted!


--- Want to compare all algorithms? (y/n): y

=== Comparing All Sorting Algorithms ===
Array size: 1000

Algorithm            Comparisons     Swaps           Time (seconds)      
-------------------------------------------------------------------------
Bubble Sort          499500          248732          0.023456
Selection Sort       499500          999             0.012345
Insertion Sort       250234          249234          0.008901
Merge Sort           8697            9976            0.001234
```

## Performance Comparison Table

### Small Array (N = 100)
| Algorithm | Comparisons | Swaps | Time (approx) | Best For |
|-----------|-------------|-------|---------------|----------|
| Bubble Sort | ~5,000 | ~2,500 | Slow | Educational purposes |
| Selection Sort | ~5,000 | ~100 | Medium | Minimal swaps needed |
| Insertion Sort | ~2,500 | ~2,500 | Fast | Nearly sorted data |
| Merge Sort | ~500 | ~600 | Fastest | Predictable performance |

### Large Array (N = 10,000)
| Algorithm | Comparisons | Swaps | Time (approx) | Best For |
|-----------|-------------|-------|---------------|----------|
| Bubble Sort | ~50M | ~25M | Very Slow | Not recommended |
| Selection Sort | ~50M | ~10K | Slow | Not recommended |
| Insertion Sort | ~25M | ~25M | Slow | Not recommended |
| Merge Sort | ~100K | ~120K | Fast | Large datasets |

## Algorithm Characteristics

### Bubble Sort
- **Pros**: Simple, stable, detects sorted array
- **Cons**: Slowest, inefficient for large arrays
- **Use Case**: Teaching, very small arrays

### Selection Sort
- **Pros**: Minimal swaps, simple
- **Cons**: Always O(n²), not stable
- **Use Case**: When swap cost is high

### Insertion Sort
- **Pros**: Fast for small/sorted data, stable, online algorithm
- **Cons**: O(n²) for large random data
- **Use Case**: Small arrays, nearly sorted data, online sorting

### Merge Sort
- **Pros**: O(n log n) guaranteed, stable, predictable
- **Cons**: Requires extra space, overkill for small arrays
- **Use Case**: Large datasets, guaranteed performance needed

## Key Concepts Demonstrated

1. **Algorithm Analysis**: Practical measurement of comparisons and swaps
2. **Time Complexity**: Real-world execution time measurement
3. **Trade-offs**: Space vs. time, simplicity vs. efficiency
4. **Stability**: Preservation of relative order
5. **Adaptive Algorithms**: Performance based on input characteristics
6. **Memory Management**: Dynamic allocation for flexible array sizes

## Compilation and Execution

```bash
gcc prog_8.c -o prog_8
./prog_8
```

## Notes

- For arrays larger than 100,000 elements, O(n²) algorithms may take significant time
- Merge sort's "swaps" count includes all array assignments during merging
- Execution time may vary based on system load and hardware
- Random number generation is seeded with time for different data each run