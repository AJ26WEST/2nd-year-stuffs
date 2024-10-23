#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Define the maximum number of vertices

// Queue structure for BFS
typedef struct {
    int items[MAX]; // Array to store the elements in the queue
    int front;      // Front index of the queue
    int rear;       // Rear index of the queue
} Queue;

// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = -1; // Initially, both front and rear are -1 (indicating an empty queue)
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1; // Queue is empty if front is -1
}

// Function to enqueue an item
void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) { // Check if the queue is full
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) { // If queue is initially empty, set front to 0
        q->front = 0;
    }
    q->rear++; // Increment rear and add the value
    q->items[q->rear] = value;
}

// Function to dequeue an item
int dequeue(Queue* q) {
    if (isEmpty(q)) { // Check if the queue is empty
        printf("Queue is empty\n");
        return -1; // Return -1 if queue is empty
    }
    int item = q->items[q->front]; // Get the item at the front
    if (q->front >= q->rear) { // If there's only one item, reset the queue
        q->front = -1;
        q->rear = -1;
    } else { // Otherwise, just increment the front index
        q->front++;
    }
    return item; // Return the dequeued item
}

// Function to perform BFS on the graph
void bfs(int graph[MAX][MAX], int start, int visited[], int n) {
    Queue q; // Create a queue for BFS
    initQueue(&q); // Initialize the queue
    
    visited[start] = 1; // Mark the starting vertex as visited
    enqueue(&q, start); // Enqueue the starting vertex
    
    while (!isEmpty(&q)) { // Continue until the queue is empty
        int current = dequeue(&q); // Dequeue the current vertex
        printf("%d ", current); // Print the current vertex
        
        // Visit all the adjacent vertices
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) { // If there is an edge and the vertex is not visited
                visited[i] = 1; // Mark it as visited
                enqueue(&q, i); // Enqueue the adjacent vertex
            }
        }
    }
}

int main() {
    int n; // Number of vertices
    int graph[MAX][MAX]; // Adjacency matrix to represent the graph
    int visited[MAX] = {0}; // Array to track visited vertices, initialized to 0 (unvisited)

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (0 and 1 only):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int startVertex;
    // Input the starting vertex for BFS
    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &startVertex);

    // Perform BFS traversal starting from the specified vertex
    printf("BFS traversal starting from vertex %d:\n", startVertex);
    bfs(graph, startVertex, visited, n);

    return 0;
}
