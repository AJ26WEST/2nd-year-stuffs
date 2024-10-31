#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node using indices
struct Node {
    int index;                // Index of the data in the array
    struct Node* left;       // Pointer to the left child
    struct Node* right;      // Pointer to the right child
};

// Function to create a new node
struct Node* createNode(int index) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->index = index;  // Initialize the node with the index
    newNode->left = NULL;    // Set left child to NULL
    newNode->right = NULL;   // Set right child to NULL
    return newNode;
}

// Function to insert values in level order using recursion
struct Node* insertLevelOrder(struct Node* root, int index, int current, int n) {
    if (current >= n) {
        return NULL;
    }

    // Create a new node at the current position
    struct Node* newNode = createNode(index);

    if (root == NULL) {
        return newNode;
    }

    // Calculate the position of the left and right child in a complete binary tree
    if (root->left == NULL) {
        root->left = insertLevelOrder(root->left, index, 2 * current + 1, n);
    } else if (root->right == NULL) {
        root->right = insertLevelOrder(root->right, index, 2 * current + 2, n);
    }

    return root;
}

// Function for in-order traversal (left-root-right)
void inOrderTraversal(struct Node* root, int data[], int n) {
    if (root != NULL) {
        inOrderTraversal(root->left, data, n);
        if (root->index < n)  // Check if index is within bounds
            printf("%d ", data[root->index]);  // Access data using index
        inOrderTraversal(root->right, data, n);
    }
}

// Function for pre-order traversal (root-left-right)
void preOrderTraversal(struct Node* root, int data[], int n) {
    if (root != NULL) {
        if (root->index < n)  // Check if index is within bounds
            printf("%d ", data[root->index]);  // Access data using index
        preOrderTraversal(root->left, data, n);
        preOrderTraversal(root->right, data, n);
    }
}

// Function for post-order traversal (left-right-root)
void postOrderTraversal(struct Node* root, int data[], int n) {
    if (root != NULL) {
        postOrderTraversal(root->left, data, n);
        postOrderTraversal(root->right, data, n);
        if (root->index < n)  // Check if index is within bounds
            printf("%d ", data[root->index]);  // Access data using index
    }
}

// Function to free the memory of the binary tree
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to demonstrate the binary tree operations
int main() {
    struct Node* root = NULL;  // Initialize the root of the tree to NULL
    int n;

    // Prompt user for number of nodes to insert
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    // Allocate memory for the data array
    int* data = (int*)malloc(n * sizeof(int));
    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Insert nodes into the binary tree using level order
    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &data[i]);  // Store data in the array
        root = insertLevelOrder(root, i, 0, n);  // Insert index into the tree
    }

    // Display the tree using different traversals
    printf("In-order Traversal of the Binary Tree:\n");
    inOrderTraversal(root, data, n);
    printf("\n");

    printf("Pre-order Traversal of the Binary Tree:\n");
    preOrderTraversal(root, data, n);
    printf("\n");

    printf("Post-order Traversal of the Binary Tree:\n");
    postOrderTraversal(root, data, n);
    printf("\n");

    // Free the allocated memory for the tree and data array
    freeTree(root);
    free(data);

    return 0;
}