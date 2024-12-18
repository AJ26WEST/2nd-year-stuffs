#include <stdio.h>

#define MAX_SIZE 5

int top = -1;
int stack[MAX_SIZE];

void push(int x) {
    if (top == MAX_SIZE - 1) {
        printf("Stack is full. Overflow condition!\n");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack is empty. Underflow condition!\n");
        return -1;
    }
    return stack[top--];
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements are: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void sorting() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    // Bubble Sort applied directly on the stack array
    for (int i = 0; i <= top; i++) {
        for (int j = 0; j < top - i; j++) {
            if (stack[j] > stack[j + 1]) {
                // Swap stack[j] and stack[j + 1]
                int temp = stack[j];
                stack[j] = stack[j + 1];
                stack[j + 1] = temp;
            }
        }
    }

    printf("Stack has been sorted in ascending order.\n");
}

int main() {
    int choice, x;
    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Sort\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                x = pop();
                if (x != -1)
                    printf("Popped element is: %d\n", x);
                break;
            case 3:
                display();
                break;
            case 4:
                sorting();  // Call sorting function
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
