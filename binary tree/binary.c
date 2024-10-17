#include <stdio.h>
#include <stdlib.h>

struct node {
    int item;
    struct node* left;
    struct node* right;
};

// Inorder traversal
void inorderTraversal(struct node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d -> ", root->item);
    inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal(struct node* root) {
    if (root == NULL) return;
    printf("%d -> ", root->item);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(struct node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d -> ", root->item);
}

// Create a new Node
struct node* createNode(int value) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->item = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert on the left of the node
struct node* insertLeft(struct node* root, int value) {
    root->left = createNode(value);
    return root->left;
}

// Insert on the right of the node
struct node* insertRight(struct node* root, int value) {
    root->right = createNode(value);
    return root->right;
}

int main() {
    int numNodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    if (numNodes <= 0) {
        printf("Number of nodes must be positive.\n");
        return 1;
    }

    int value;
    printf("Enter the value for the root node: ");
    scanf("%d", &value);
    struct node* root = createNode(value);

    for (int i = 1; i < numNodes; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        // For simplicity, we'll insert nodes to the left and right in a sequential manner
        // You can implement your own logic for positioning nodes
        if (i % 2 == 1) {
            insertLeft(root, value);
        } else {
            insertRight(root, value);
        }
    }

    printf("\nInorder traversal:\n");
    inorderTraversal(root);

    printf("\nPreorder traversal:\n");
    preorderTraversal(root);

    printf("\nPostorder traversal:\n");
    postorderTraversal(root);

    // Free allocated memory (optional)
    // You could implement a function to free the nodes here

    return 0;
}
