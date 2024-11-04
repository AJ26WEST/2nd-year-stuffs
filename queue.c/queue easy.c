#include <stdio.h>

#define MAX_SIZE 5  // Define the fixed maximum size of the queue

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Helper function to check if the queue is empty
int isEmpty() {
    return (front == -1 && rear == -1);
}

// Helper function to check if the queue is full
int isFull() {
    return (rear == MAX_SIZE - 1);
}

void enqueue(int x) {
    if (isFull()) {
        printf("Overflow: Queue is full.\n");
    } else {
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        queue[rear] = x;
        printf("Enqueued: %d\n", x);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Underflow: Queue is empty.\n");
    } else {
        printf("Dequeued: %d\n", queue[front]);
        if (front == rear) {  // Reset the queue if it becomes empty
            front = rear = -1;
        } else {
            front++;
        }
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, element;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
