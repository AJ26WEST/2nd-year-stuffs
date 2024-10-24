#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct Stack {
    int items[MAX_VERTICES];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
bool isStackEmpty(Stack *s) {
    return s->top == -1;
}

// Function to push an item onto the stack
void push(Stack *s, int value) {
    if (s->top == MAX_VERTICES - 1) {
        printf("Stack is full\n");
        return;
    }
    s->top++;
    s->items[s->top] = value;
}

// Function to pop an item from the stack
int pop(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[s->top--];
}

// Function to perform DFS
void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int start, int numVertices) {
    bool visited[MAX_VERTICES] = {false};
    Stack s;
    initStack(&s);

    push(&s, start); // Push the starting vertex onto the stack

    while (!isStackEmpty(&s)) {
        int currentVertex = pop(&s);

        // If the vertex has not been visited
        if (!visited[currentVertex]) {
            printf("%d ", currentVertex); // Print the visited vertex
            visited[currentVertex] = true; // Mark it as visited
        }

        // Visit all the adjacent vertices in reverse order
        for (int i = numVertices - 1; i >= 0; i--) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                push(&s, i); // Push the unvisited adjacent vertex onto the stack
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
    printf("Enter the starting vertex for DFS (0-%d): ", numVertices - 1);
    scanf("%d", &startVertex);

    // Validate the starting vertex
    if (startVertex < 0 || startVertex >= numVertices) {
        printf("Invalid starting vertex. Please run the program again.\n");
        return 1;
    }

    // Perform DFS
    printf("DFS starting from vertex %d: ", startVertex);
    dfs(graph, startVertex, numVertices);
    printf("\n");

    return 0;
}
