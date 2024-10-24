#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
bool isEmpty(Queue *q) {
    return q->front == -1;
}

// Function to add an item to the queue
void enqueue(Queue *q, int value) {
    if (q->rear == MAX_VERTICES - 1) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Function to remove an item from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;  // Reset the queue
    }
    return item;
}

// Function to perform BFS
void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int start, int numVertices) {
    bool visited[MAX_VERTICES] = {false};
    Queue q;
    initQueue(&q);

    visited[start] = true; // Mark the starting vertex as visited
    enqueue(&q, start);    // Enqueue the starting vertex

    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex); // Print the visited vertex

        // Visit all the adjacent vertices
        for (int i = 0; i < numVertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                enqueue(&q, i); // Enqueue the unvisited adjacent vertex
                visited[i] = true; // Mark it as visited
            }
        }
    }
}

// Function to print the adjacency matrix
void printAdjacencyMatrix(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numVertices;

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // Input the adjacency matrix
    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix for the graph (%d x %d):\n", numVertices, numVertices);
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Print the adjacency matrix
    printAdjacencyMatrix(graph, numVertices);

    // Input the starting vertex
    int startVertex;
    printf("Enter the starting vertex for BFS (0-%d): ", numVertices - 1);
    scanf("%d", &startVertex);

    // Validate the starting vertex
    if (startVertex < 0 || startVertex >= numVertices) {
        printf("Invalid starting vertex. Please run the program again.\n");
        return 1;
    }

    // Perform BFS
    printf("BFS starting from vertex %d: ", startVertex);
    bfs(graph, startVertex, numVertices);
    printf("\n");

    return 0;
}
