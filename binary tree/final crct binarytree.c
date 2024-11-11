#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node using indices
struct Node {
    int index;                // Index of the data in the array
    struct Node* left;       // Pointer to the left child
    struct Node* right;      // Pointer to the right child
};

// Function to create a new node with a given index
struct Node* createNode(int index) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) { // Check if memory was allocated
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->index = index;  // Store the index in the node
    newNode->left = NULL;    // Initialize left child as NULL
    newNode->right = NULL;   // Initialize right child as NULL
    return newNode; // Return the created node
}

// Function to insert values in level order using recursion
struct Node* insertLevelOrder(struct Node* root, int index, int current, int n) {
    if (current >= n) { // Base case: if the current index is out of bounds, return NULL
        return NULL;
    }

    struct Node* newNode = createNode(index); // Create a new node for the current index

    if (root == NULL) { // If root is NULL, the new node becomes the root
        return newNode;
    }

    // Fill the left and right child nodes in level order
    if (root->left == NULL) {
        root->left = insertLevelOrder(root->left, index, 2 * current + 1, n);
    } else if (root->right == NULL) {
        root->right = insertLevelOrder(root->right, index, 2 * current + 2, n);
    }

    return root;
}

// In-order traversal (left-root-right)
void inOrderTraversal(struct Node* root, int data[], int n) {
    if (root != NULL) {
        inOrderTraversal(root->left, data, n); // Visit the left subtree
        if (root->index < n)  // Make sure index is within bounds
            printf("%d ", data[root->index]);  // Print the data at the index
        inOrderTraversal(root->right, data, n); // Visit the right subtree
    }
}

// Pre-order traversal (root-left-right)
void preOrderTraversal(struct Node* root, int data[], int n) {
    if (root != NULL) {
        if (root->index < n)  // Make sure index is within bounds
            printf("%d ", data[root->index]);  // Print the data at the index
        preOrderTraversal(root->left, data, n); // Visit the left subtree
        preOrderTraversal(root->right, data, n); // Visit the right subtree
    }
}

// Post-order traversal (left-right-root)
void postOrderTraversal(struct Node* root, int data[], int n) {
    if (root != NULL) {
        postOrderTraversal(root->left, data, n); // Visit the left subtree
        postOrderTraversal(root->right, data, n); // Visit the right subtree
        if (root->index < n)  // Make sure index is within bounds
            printf("%d ", data[root->index]);  // Print the data at the index
    }
}

// Function to free the memory used by the binary tree
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left); // Free the left child
        freeTree(root->right); // Free the right child
        free(root);            // Free the current node
    }
}

// Main function to demonstrate binary tree operations
int main() {
    struct Node* root = NULL;  // Start with an empty tree
    int n;  // Number of nodes

    // Get the number of nodes to insert
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    // Allocate memory for the data array
    int* data = (int*)malloc(n * sizeof(int));
    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Input the values to store in the binary tree
    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &data[i]);
        root = insertLevelOrder(root, i, 0, n); // Insert node index in level order
    }

    // Display the tree using different traversal methods
    printf("In-order Traversal:\n");
    inOrderTraversal(root, data, n);
    printf("\n");

    printf("Pre-order Traversal:\n");
    preOrderTraversal(root, data, n);
    printf("\n");

    printf("Post-order Traversal:\n");
    postOrderTraversal(root, data, n);
    printf("\n");

    // Free the memory used by the tree and data array
    freeTree(root);
    free(data);

    return 0;
}
