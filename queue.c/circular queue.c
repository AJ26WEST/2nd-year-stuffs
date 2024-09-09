#include <stdio.h>


#define MAX_SIZE 3

 
    int queue[MAX_SIZE];
int front = -1, rear = -1;


int isFull()
{
   
    return (rear + 1) % MAX_SIZE == front;
}


int isEmpty()
{
   
    return front == -1;
}


void enqueue(int data)
{
   
    if (isFull()) {
        printf("Queue overflow\n");
        return;
    }
   
    if (front == -1) {
        front = 0;
    }
   
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = data;
    printf("Element %d inserted\n", data);
}


int dequeue()
{
   
    if (isEmpty()) {
        printf("Queue underflow\n");
        return -1;
    }
   
    int data = queue[front];
 
    if (front == rear) {
        front = rear = -1;
    }
    else {
     
        front = (front + 1) % MAX_SIZE;
    }
 
    return data;
}


void display()
{
   
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
   
    printf("Queue elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
   
    printf("%d\n", queue[rear]);
}

int main(){

int choice, item;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the item to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting\n");
                return 0;
            default:
                printf("Invalid choice...\n");
                break;
        }
    }
}
