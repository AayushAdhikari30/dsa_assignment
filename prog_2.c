#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} CharStack;

typedef struct {
    int items[MAX_SIZE];
    int top;
} IntStack;


void initCharStack(CharStack *s) {
    s->top = -1;
}

bool isCharStackEmpty(CharStack *s) {
    return s->top == -1;
}

bool isCharStackFull(CharStack *s) {
    return s->top == MAX_SIZE - 1;
}

void pushChar(CharStack *s, char ch) {
    if (isCharStackFull(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->items[++(s->top)] = ch;
}

char popChar(CharStack *s) {
    if (isCharStackEmpty(s)) {
        return '\0';
    }
    return s->items[(s->top)--];
}

char peekChar(CharStack *s) {
    if (isCharStackEmpty(s)) {
        return '\0';
    }
    return s->items[s->top];
}


void initIntStack(IntStack *s) {
    s->top = -1;
}

bool isIntStackEmpty(IntStack *s) {
    return s->top == -1;
}

bool isIntStackFull(IntStack *s) {
    return s->top == MAX_SIZE - 1;
}

void pushInt(IntStack *s, int value) {
    if (isIntStackFull(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->items[++(s->top)] = value;
}

int popInt(IntStack *s) {
    if (isIntStackEmpty(s)) {
        printf("Stack underflow!\n");
        return 0;
    }
    return s->items[(s->top)--];
}


bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char op) {
    switch(op) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

bool isRightAssociative(char op) {
    return (op == '^');
}


void infixToPostfix(char *infix, char *postfix) {
    CharStack s;
    initCharStack(&s);
    
    int i = 0;  
    int j = 0;  
    
    while (infix[i] != '\0') {
        char current = infix[i];
        
        if (current == ' ') {
            i++;
            continue;
        }
        
        if (isalnum(current)) {
            postfix[j++] = current;
            postfix[j++] = ' ';  
        }
        else if (current == '(') {
            pushChar(&s, current);
        }
        else if (current == ')') {
            while (!isCharStackEmpty(&s) && peekChar(&s) != '(') {
                postfix[j++] = popChar(&s);
                postfix[j++] = ' ';
            }
            if (!isCharStackEmpty(&s)) {
                popChar(&s);  
            }
        }
        else if (isOperator(current)) {
            while (!isCharStackEmpty(&s) && 
                   peekChar(&s) != '(' && 
                   (precedence(peekChar(&s)) > precedence(current) ||
                    (precedence(peekChar(&s)) == precedence(current) && !isRightAssociative(current)))) {
                postfix[j++] = popChar(&s);
                postfix[j++] = ' ';
            }
            pushChar(&s, current);
        }
        
        i++;
    }
    
    while (!isCharStackEmpty(&s)) {
        postfix[j++] = popChar(&s);
        postfix[j++] = ' ';
    }
    
    postfix[j] = '\0';  
}


int applyOperator(int operand1, int operand2, char op) {
    switch(op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                printf("Error: Division by zero!\n");
                return 0;
            }
            return operand1 / operand2;
        case '^':
            {
                int result = 1;
                for (int i = 0; i < operand2; i++) {
                    result *= operand1;
                }
                return result;
            }
        default:
            return 0;
    }
}

int evaluatePostfix(char *postfix) {
    IntStack s;
    initIntStack(&s);
    
    int i = 0;
    
    while (postfix[i] != '\0') {
        char current = postfix[i];
        
        if (current == ' ') {
            i++;
            continue;
        }
        
        if (isdigit(current)) {
            int num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            pushInt(&s, num);
            continue;
        }
        else if (isOperator(current)) {
            int operand2 = popInt(&s);  
            int operand1 = popInt(&s);  
            
            int result = applyOperator(operand1, operand2, current);
            pushInt(&s, result);
        }
        
        i++;
    }
    
    return popInt(&s);
}


int main() {
   
    
    printf("Test Case 1:\n");
    char infix1[] = "A + B * C";
    char postfix1[MAX_SIZE];
    infixToPostfix(infix1, postfix1);
    printf("Infix:    %s\n", infix1);
    printf("Postfix:  %s\n", postfix1);
    
    printf("Test Case 2:\n");
    char infix2[] = "(A + B) * C";
    char postfix2[MAX_SIZE];
    infixToPostfix(infix2, postfix2);
    printf("Infix:    %s\n", infix2);
    printf("Postfix:  %s\n", postfix2);
    
    printf("Test Case 3:\n");
    char infix3[] = "A * B + C / D";
    char postfix3[MAX_SIZE];
    infixToPostfix(infix3, postfix3);
    printf("Infix:    %s\n", infix3);
    printf("Postfix:  %s\n", postfix3);
    
    
    
    
    printf("Evaluation Test 1:\n");
    char infixNum1[] = "3 + 5 * 2";
    char postfixNum1[MAX_SIZE];
    infixToPostfix(infixNum1, postfixNum1);
    printf("Infix:    %s\n", infixNum1);
    printf("Postfix:  %s\n", postfixNum1);
    int result1 = evaluatePostfix(postfixNum1);
    printf("Result:   %d\n", result1);
    
    printf("Evaluation Test 2:\n");
    char infixNum2[] = "(3 + 5) * 2";
    char postfixNum2[MAX_SIZE];
    infixToPostfix(infixNum2, postfixNum2);
    printf("Infix:    %s\n", infixNum2);
    printf("Postfix:  %s\n", postfixNum2);
    int result2 = evaluatePostfix(postfixNum2);
    printf("Result:   %d\n", result2);
    
    printf("Evaluation Test 3:\n");
    char infixNum3[] = "10 + 20 / 5 - 3";
    char postfixNum3[MAX_SIZE];
    infixToPostfix(infixNum3, postfixNum3);
    printf("Infix:    %s\n", infixNum3);
    printf("Postfix:  %s\n", postfixNum3);
    int result3 = evaluatePostfix(postfixNum3);
    printf("Result:   %d\n", result3);
    

    
    return 0;
}