#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100

int main() {
    char stack[MAX_SIZE];
    int top = -1;
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    int i, j = 0;

    printf("Enter an infix expression (like 1+2*3): ");
    fgets(infix, MAX_SIZE, stdin);

    // Convert infix to postfix
    for (i = 0; infix[i] != '\0' && infix[i] != '\n'; i++) {
        if (isdigit(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--; // Remove '(' from stack
        } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            while (top != -1 && (stack[top] == '*' || stack[top] == '/')) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }

    while (top != -1) {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    // Evaluate the postfix expression
    int numStack[MAX_SIZE];
    top = -1;

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            numStack[++top] = postfix[i] - '0';
        } else {
            int num2 = numStack[top--];
            int num1 = numStack[top--];
            int result;
            if (postfix[i] == '+') {
                result = num1 + num2;
            } else if (postfix[i] == '-') {
                result = num1 - num2;
            } else if (postfix[i] == '*') {
                result = num1 * num2;
            } else if (postfix[i] == '/') {
                result = num1 / num2;
            }
            numStack[++top] = result;
        }
    }
    int finalResult = numStack[top--];
    printf("Result: %d\n", finalResult);

    return 0;
}
