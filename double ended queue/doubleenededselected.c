#include <stdio.h>
#include <stdlib.h>
#define N 3

int front = -1, rear = -1, dq[N];

void insertFront(int item, int size) {
    if ((front == 0 && rear == size - 1) || (rear + 1) % size == front) {
        printf("Deque overflow\n");
    } else {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = size - 1;
        } else {
            front--;
        }
        dq[front] = item;
        printf("%d successfully inserted at the front\n", item);
    }
}

void insertRear(int item, int size) {
    if ((front == 0 && rear == size - 1) || (rear + 1) % size == front) {
        printf("Deque overflow\n");
    } else {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == size - 1) {
            rear = 0;
        } else {
            rear++;
        }
        dq[rear] = item;
        printf("%d successfully inserted at the rear\n", item);
    }
}

int deleteFront(int size) {
    if (front == -1) {
        printf("Deque underflow\n");
        return -1;
    }
    int item = dq[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == size - 1) {
        front = 0;
    } else {
        front++;
    }
    printf("%d successfully deleted from the front\n", item);
    return item;
}

int deleteRear(int size) {
    if (front == -1) {
        printf("Deque underflow\n");
        return -1;
    }
    int item = dq[rear];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = size - 1;
    } else {
        rear--;
    }
    printf("%d successfully deleted from the rear\n", item);
    return item;
}

void display(int size) {
    if (front == -1) {
        printf("Deque is empty\n");
    } else {
        printf("Deque elements:\n");
        int i = front;
        while (1) {
            printf("%d\t", dq[i]);
            if (i == rear) break;
            i = (i + 1) % size;
        }
        printf("\n");
    }
}

int main() {
    int size, item, choice;

    printf("Enter the size of the deque: ");
    scanf("%d", &size);

    do {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to be inserted at the front: ");
                scanf("%d", &item);
                insertFront(item, size);
                break;
            case 2:
                printf("Enter element to be inserted at the rear: ");
                scanf("%d", &item);
                insertRear(item, size);
                break;
            case 3:
                deleteFront(size);
                break;
            case 4:
                deleteRear(size);
                break;
            case 5:
                display(size);
                break;
            case 6:
                printf("\nExiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (1);

    return 0;
}
