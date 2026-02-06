#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}

bool isEmpty(Stack *s)
{
    return s->top == -1;
}

bool isFull(Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, char ch)
{
    if (isFull(s))
    {
        printf("Stack Overflow!\n");
        return;
    }
    s->items[++(s->top)] = ch;
}
char pop(Stack *s)
{
    if (isEmpty(s))
    {
        return '\0';
    }
    return s->items[(s->top)--];
}

char peek(Stack *s)
{
    if(isEmpty(s))
    {
        return '\0';}
        return s->items[s->top];
}

char isOpeningBracket(char ch)
{
    return (ch == '(' || ch == '[' || ch == '{');
}

bool isClosingBracket(char ch)
{
    return (ch == ')' || ch == ']' || ch == '}');
}

bool isMatchingPair(char opening, char closing)
{
    return (opening == '(' && closing == ')') ||
            (opening == '[' && closing == ']') ||
            (opening == '{' && closing == '}');
}

bool isBalanced(char *expression) {
    Stack s;
    initStack(&s);
    
    int length = strlen(expression);
    
    for (int i = 0; i < length; i++) {
        char current = expression[i];
        
        if (isOpeningBracket(current)) {
            push(&s, current);
        }
        else if (isClosingBracket(current)) {
            if (isEmpty(&s)) {
                return false;
            }
            
            char top = pop(&s);
            if (!isMatchingPair(top, current)) {
                return false;
            }
        }
    }
    
    return isEmpty(&s);
}

void checkAndPrint(char *expression){
    printf("Expression: %s\n", expression);

    if(isBalanced(expression)){
        printf("Result: Balanced\n");
    }
    else{
        printf("Result: Not Balanced\n");
    }
}

int main()
{
    char expr1[] = "a + (b-c) * (d";
    checkAndPrint(expr1);

    char expr2[] = "m +[a-b * (c+d*{m)]";
    checkAndPrint(expr2);

    char expr3[] = "a + (b-c)";
    checkAndPrint(expr3);

    return 0;
}