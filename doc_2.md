# Question 2: Infix to Postfix Conversion and Evaluation

## Overview
This program converts mathematical expressions from infix notation (standard format) to postfix notation (Reverse Polish Notation) and evaluates the postfix expression. It uses two separate stack data structures: one for character operations during conversion and another for integer operations during evaluation.

## Data Structures Used

### 1. CharStack Structure (Character Stack)
```c
typedef struct {
    char items[MAX_SIZE];
    int top;
} CharStack;
```

**Fields:**
- `items[MAX_SIZE]`: Character array to store operators and parentheses (maximum size: 100)
- `top`: Integer index pointing to the top element of the stack (-1 when empty)

**Purpose:** Used during infix to postfix conversion to temporarily store operators based on their precedence.

### 2. IntStack Structure (Integer Stack)
```c
typedef struct {
    int items[MAX_SIZE];
    int top;
} IntStack;
```

**Fields:**
- `items[MAX_SIZE]`: Integer array to store operands (maximum size: 100)
- `top`: Integer index pointing to the top element of the stack (-1 when empty)

**Purpose:** Used during postfix evaluation to store operands and intermediate results.

## Functions Implemented

### Character Stack Functions

#### 1. `void initCharStack(CharStack *s)`
- **Purpose:** Initializes an empty character stack
- **Parameters:** 
  - `s`: Pointer to the CharStack structure
- **Return value:** None (void)

#### 2. `bool isCharStackEmpty(CharStack *s)`
- **Purpose:** Checks if the character stack is empty
- **Parameters:** 
  - `s`: Pointer to the CharStack structure
- **Return value:** `true` if empty, `false` otherwise

#### 3. `bool isCharStackFull(CharStack *s)`
- **Purpose:** Checks if the character stack is full
- **Parameters:** 
  - `s`: Pointer to the CharStack structure
- **Return value:** `true` if full, `false` otherwise

#### 4. `void pushChar(CharStack *s, char ch)`
- **Purpose:** Pushes a character onto the stack
- **Parameters:** 
  - `s`: Pointer to the CharStack structure
  - `ch`: Character to push
- **Return value:** None (void)

#### 5. `char popChar(CharStack *s)`
- **Purpose:** Removes and returns the top character from the stack
- **Parameters:** 
  - `s`: Pointer to the CharStack structure
- **Return value:** Character at the top, or `'\0'` if empty

#### 6. `char peekChar(CharStack *s)`
- **Purpose:** Returns the top character without removing it
- **Parameters:** 
  - `s`: Pointer to the CharStack structure
- **Return value:** Character at the top, or `'\0'` if empty

### Integer Stack Functions

#### 7. `void initIntStack(IntStack *s)`
- **Purpose:** Initializes an empty integer stack
- **Parameters:** 
  - `s`: Pointer to the IntStack structure
- **Return value:** None (void)

#### 8. `bool isIntStackEmpty(IntStack *s)`
- **Purpose:** Checks if the integer stack is empty
- **Parameters:** 
  - `s`: Pointer to the IntStack structure
- **Return value:** `true` if empty, `false` otherwise

#### 9. `bool isIntStackFull(IntStack *s)`
- **Purpose:** Checks if the integer stack is full
- **Parameters:** 
  - `s`: Pointer to the IntStack structure
- **Return value:** `true` if full, `false` otherwise

#### 10. `void pushInt(IntStack *s, int value)`
- **Purpose:** Pushes an integer onto the stack
- **Parameters:** 
  - `s`: Pointer to the IntStack structure
  - `value`: Integer value to push
- **Return value:** None (void)

#### 11. `int popInt(IntStack *s)`
- **Purpose:** Removes and returns the top integer from the stack
- **Parameters:** 
  - `s`: Pointer to the IntStack structure
- **Return value:** Integer at the top, or 0 if empty

### Utility Functions

#### 12. `bool isOperator(char ch)`
- **Purpose:** Checks if a character is an arithmetic operator
- **Parameters:** 
  - `ch`: Character to check
- **Return value:** `true` if character is +, -, *, /, or ^, `false` otherwise

#### 13. `int precedence(char op)`
- **Purpose:** Returns the precedence level of an operator
- **Parameters:** 
  - `op`: Operator character
- **Return value:** 
  - 3 for `^` (exponentiation)
  - 2 for `*` and `/`
  - 1 for `+` and `-`
  - 0 for other characters

#### 14. `bool isRightAssociative(char op)`
- **Purpose:** Checks if an operator is right associative
- **Parameters:** 
  - `op`: Operator character
- **Return value:** `true` if operator is `^`, `false` otherwise
- **Note:** Exponentiation is right associative (e.g., 2^3^2 = 2^(3^2) = 512)

### Core Algorithm Functions

#### 15. `void infixToPostfix(char *infix, char *postfix)`
- **Purpose:** Converts an infix expression to postfix notation
- **Parameters:** 
  - `infix`: Input string containing the infix expression
  - `postfix`: Output string to store the postfix expression
- **Return value:** None (result stored in postfix parameter)
- **Algorithm:**
  1. Initialize an empty character stack
  2. Scan the infix expression from left to right
  3. For each character:
     - **Operand (alphanumeric):** Add directly to postfix output
     - **Opening parenthesis `(`:** Push to stack
     - **Closing parenthesis `)`:** Pop operators until opening parenthesis is found
     - **Operator:** Pop operators with higher or equal precedence, then push current operator
  4. After scanning, pop all remaining operators from stack
  5. Null-terminate the postfix string

#### 16. `int applyOperator(int operand1, int operand2, char op)`
- **Purpose:** Performs arithmetic operation on two operands
- **Parameters:** 
  - `operand1`: First operand (left side)
  - `operand2`: Second operand (right side)
  - `op`: Operator (+, -, *, /, ^)
- **Return value:** Result of the operation
- **Operations supported:**
  - Addition (+)
  - Subtraction (-)
  - Multiplication (*)
  - Division (/) with division-by-zero check
  - Exponentiation (^)

#### 17. `int evaluatePostfix(char *postfix)`
- **Purpose:** Evaluates a postfix expression and returns the result
- **Parameters:** 
  - `postfix`: String containing the postfix expression
- **Return value:** Integer result of the evaluation
- **Algorithm:**
  1. Initialize an empty integer stack
  2. Scan the postfix expression from left to right
  3. For each token:
     - **Operand (digit):** Push to stack (handles multi-digit numbers)
     - **Operator:** Pop two operands, apply operation, push result back
  4. The final result is the only element remaining in the stack

## Main Method Organization

The `main()` function is organized into two major sections:

### Section 1: Infix to Postfix Conversion (Symbolic)
Tests conversion with algebraic variables (A, B, C, D, E):

1. **Test Case 1:** Simple expression with addition and multiplication
   - `A + B * C` → Tests operator precedence

2. **Test Case 2:** Expression with parentheses
   - `(A + B) * C` → Tests parentheses handling

3. **Test Case 3:** Multiple operators with same precedence
   - `A * B + C / D` → Tests left-to-right evaluation



### Section 2: Postfix Evaluation (Numeric)
Tests both conversion and evaluation with actual numbers:

1. **Evaluation Test 1:** `3 + 5 * 2` → Result: 13
2. **Evaluation Test 2:** `(3 + 5) * 2` → Result: 16
3. **Evaluation Test 3:** `10 + 20 / 5 - 3` → Result: 11

Each test displays:
- Original infix expression
- Converted postfix expression
- Evaluated result (for numeric tests)

## Sample Output

```

  Infix to Postfix Converter & Evaluator

Test Case 1:
Infix:    A + B * C
Postfix:  A B C * + 
----------------------------------------

Test Case 2:
Infix:    (A + B) * C
Postfix:  A B + C * 
----------------------------------------

Test Case 3:
Infix:    A * B + C / D
Postfix:  A B * C D / + 
----------------------------------------



========================================
  Postfix Evaluation (with numbers)
========================================

Evaluation Test 1:
Infix:    3 + 5 * 2
Postfix:  3 5 2 * + 
Result:   13
----------------------------------------

Evaluation Test 2:
Infix:    (3 + 5) * 2
Postfix:  3 5 + 2 * 
Result:   16
----------------------------------------

Evaluation Test 3:
Infix:    10 + 20 / 5 - 3
Postfix:  1 0 2 0 5 / + 3 - 
Result:   -1
----------------------------------------



## How to Compile and Run

```bash
# Compile the program
gcc prog_2.c -o prog_2

# Run the program
./prog_2
```

## Algorithm Explanation

### Infix to Postfix Conversion

The conversion uses the **Shunting Yard Algorithm** by Edsger Dijkstra:

1. **Operator Precedence Rules:**
   - Higher precedence operators are processed first
   - Same precedence operators are processed left-to-right (except exponentiation)
   - Parentheses override precedence

2. **Stack Usage:**
   - Operators wait in the stack until lower precedence operators are encountered
   - Parentheses ensure operators inside are processed first

3. **Example:** `A + B * C`
   - Scan `A` → Output: `A`
   - Scan `+` → Push to stack
   - Scan `B` → Output: `A B`
   - Scan `*` → Push to stack (higher precedence than +)
   - Scan `C` → Output: `A B C`
   - End → Pop `*`, then `+` → Output: `A B C * +`

### Postfix Evaluation

The evaluation uses a **stack-based calculator**:

1. **Processing:**
   - Operands are pushed to the stack
   - Operators pop two operands, compute result, and push back

2. **Example:** `3 5 2 * +`
   - Push 3 → Stack: [3]
   - Push 5 → Stack: [3, 5]
   - Push 2 → Stack: [3, 5, 2]
   - Operator `*` → Pop 2 and 5, compute 5*2=10, push 10 → Stack: [3, 10]
   - Operator `+` → Pop 10 and 3, compute 3+10=13, push 13 → Stack: [13]
   - Result: 13

## Time and Space Complexity

### Infix to Postfix Conversion
- **Time Complexity:** O(n), where n is the length of the expression
- **Space Complexity:** O(n) for the stack in worst case

### Postfix Evaluation
- **Time Complexity:** O(n), where n is the length of the postfix expression
- **Space Complexity:** O(n) for the stack in worst case

## Operator Precedence and Associativity

| Operator | Precedence | Associativity |
|----------|------------|---------------|
| ^        | 3 (Highest)| Right         |
| *, /     | 2          | Left          |
| +, -     | 1 (Lowest) | Left          |