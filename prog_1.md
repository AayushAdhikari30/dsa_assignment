# Question 1: Balanced Parentheses Checker

## Overview
This program checks whether a given mathematical expression has a balanced number of parentheses. It uses a stack data structure to track opening and closing brackets of three types: `()`, `[]`, and `{}`.

## Data Structures Used

### Stack Structure
```c
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;
```

**Fields:**
- `items[MAX_SIZE]`: Character array to store opening brackets (maximum size: 100)
- `top`: Integer index pointing to the top element of the stack (-1 when empty)

**Purpose:** The stack stores opening brackets as we scan through the expression. When a closing bracket is encountered, we pop from the stack to check if it matches.

## Functions Implemented

### 1. `void initStack(Stack *s)`
- **Purpose:** Initializes an empty stack by setting the top to -1
- **Parameters:** 
  - `s`: Pointer to the Stack structure
- **Return value:** None (void)

### 2. `bool isEmpty(Stack *s)`
- **Purpose:** Checks if the stack is empty
- **Parameters:** 
  - `s`: Pointer to the Stack structure
- **Return value:** `true` if stack is empty (top == -1), `false` otherwise

### 3. `bool isFull(Stack *s)`
- **Purpose:** Checks if the stack is full
- **Parameters:** 
  - `s`: Pointer to the Stack structure
- **Return value:** `true` if stack is full (top == MAX_SIZE - 1), `false` otherwise

### 4. `void push(Stack *s, char ch)`
- **Purpose:** Pushes a character (opening bracket) onto the stack
- **Parameters:** 
  - `s`: Pointer to the Stack structure
  - `ch`: Character to push onto the stack
- **Return value:** None (void)
- **Note:** Displays error message if stack overflow occurs

### 5. `char pop(Stack *s)`
- **Purpose:** Removes and returns the top element from the stack
- **Parameters:** 
  - `s`: Pointer to the Stack structure
- **Return value:** The character at the top of the stack, or `'\0'` if stack is empty

### 6. `char peek(Stack *s)`
- **Purpose:** Returns the top element without removing it from the stack
- **Parameters:** 
  - `s`: Pointer to the Stack structure
- **Return value:** The character at the top of the stack, or `'\0'` if stack is empty

### 7. `bool isOpeningBracket(char ch)`
- **Purpose:** Checks if a character is an opening bracket
- **Parameters:** 
  - `ch`: Character to check
- **Return value:** `true` if character is `(`, `[`, or `{`, `false` otherwise

### 8. `bool isClosingBracket(char ch)`
- **Purpose:** Checks if a character is a closing bracket
- **Parameters:** 
  - `ch`: Character to check
- **Return value:** `true` if character is `)`, `]`, or `}`, `false` otherwise

### 9. `bool isMatchingPair(char opening, char closing)`
- **Purpose:** Checks if an opening and closing bracket form a valid pair
- **Parameters:** 
  - `opening`: Opening bracket character
  - `closing`: Closing bracket character
- **Return value:** `true` if brackets match (e.g., `(` matches `)`), `false` otherwise

### 10. `bool isBalanced(char *expression)`
- **Purpose:** Main algorithm to check if the entire expression has balanced parentheses
- **Parameters:** 
  - `expression`: String containing the mathematical expression
- **Return value:** `true` if expression is balanced, `false` otherwise
- **Algorithm:**
  1. Initialize an empty stack
  2. Scan each character in the expression
  3. If opening bracket → push to stack
  4. If closing bracket → pop from stack and verify it matches
  5. Return false if mismatch or stack is empty when closing bracket is found
  6. After scanning, return true only if stack is empty

### 11. `void checkAndPrint(char *expression)`
- **Purpose:** Helper function to check an expression and print the result in a formatted manner
- **Parameters:** 
  - `expression`: String containing the mathematical expression
- **Return value:** None (void)

## Main Method Organization

The `main()` function is organized as follows:

1. **Program Header:** Displays a title banner for the program

2. **Required Test Cases:** Tests the three expressions specified in the assignment:
   - `a + (b − c) * (d` - Expected: NOT BALANCED (missing closing parenthesis)
   - `m + [a − b * (c + d * {m)]` - Expected: NOT BALANCED (mismatched brackets)
   - `a + (b − c)` - Expected: BALANCED

3. **Additional Test Cases:** Demonstrates the program with extra examples to show robustness:
   - `{[()]}` - Nested brackets (balanced)
   - `((a + b) * (c - d))` - Multiple nested parentheses (balanced)
   - `[(])` - Interleaved brackets (not balanced)
   - `a + b)` - Extra closing bracket (not balanced)

4. **Output:** Each test case prints:
   - The expression being tested
   - Whether it is balanced or not balanced
   - A separator line for clarity

## Sample Output

```
Expression: a + (b − c) * (d
Result: NOT BALANCED ✗
----------------------------------------

Expression: m + [a − b * (c + d * {m)]
Result: NOT BALANCED ✗
----------------------------------------

Expression: a + (b − c)
Result: BALANCED ✓
----------------------------------------
```

## How to Compile and Run

```bash
# Compile the program
gcc prog_1.c -o prog_1

# Run the program
./prog_1
```

## Algorithm Explanation

The algorithm uses the **stack-based matching** approach:

1. **Scan left to right:** Process each character in the expression sequentially
2. **Opening brackets:** Push `(`, `[`, or `{` onto the stack
3. **Closing brackets:** When `)`, `]`, or `}` is encountered:
   - Pop the top element from the stack
   - Check if it matches the closing bracket
   - If no match or stack is empty → return false
4. **Other characters:** Ignore operands and operators (a, b, +, -, *, etc.)
5. **Final check:** After processing all characters, the stack must be empty for the expression to be balanced

## Time and Space Complexity

- **Time Complexity:** O(n), where n is the length of the expression (single pass through the string)
- **Space Complexity:** O(n) in worst case, where all characters are opening brackets