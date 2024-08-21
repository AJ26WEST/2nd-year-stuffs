#include <stdio.h>

int main() {
    int stack[100]; // array to store stack elements
    int top = -1; // top index of the stack
    int capacity = 100; // maximum capacity of the stack
    int choice, element;

    while (1) {
        printf("Stack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
     
        printf("3. Print Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                if (top >= capacity - 1) {
                    printf("Stack is full!\n");
                } else {
                    stack[++top] = element;
                    printf("%d pushed onto stack\n", element);
                }
                break;
            case 2:
                if (top < 0) {
                    printf("Stack is empty!\n");
                } else {
                    printf("%d popped from stack\n", stack[top--]);
                }
                break;
            
            case 3:
                printf("Stack: ");
                for (int i = 0; i <= top; i++) {
                    printf("%d ", stack[i]);
                }
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
