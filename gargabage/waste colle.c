#include <stdio.h>
#include <stdlib.h>

struct Block {
    int id;
    int size;
    int isFree;
    struct Block* prev;
    struct Block* next;
};

// Head of the doubly linked list
struct Block* head = NULL;
int nextBlockID = 1; // Unique block ID tracker

// Function to create a new block
struct Block* createBlock(int size) {
    struct Block* newBlock = (struct Block*)malloc(sizeof(struct Block));
    newBlock->id = nextBlockID++;  // Assign unique ID and increment
    newBlock->size = size;
    newBlock->isFree = 1;  // Initially free
    newBlock->prev = NULL;
    newBlock->next = NULL;
    return newBlock;
}

// Function to add a block to the list
void addBlock(int size) {
    struct Block* newBlock = createBlock(size);
    
    if (head == NULL) {
        head = newBlock;
    } else {
        struct Block* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBlock;
        newBlock->prev = temp;
    }
    printf("Block of size %d added.\n", size);
}

// Function to allocate memory (find the first free block of sufficient size)
void allocateMemory(int size) {
    struct Block* temp = head;
    while (temp != NULL) {
        if (temp->isFree && temp->size >= size) {
            temp->isFree = 0;
            printf("Memory allocated for Block ID %d of size %d\n", temp->id, size);
            return;
        }
        temp = temp->next;
    }
    printf("No free block available for size %d\n", size);
}

// Function to deallocate memory (free the block by its ID)
void deallocateMemory(int id) {
    struct Block* temp = head;
    while (temp != NULL) {
        if (temp->id == id && !temp->isFree) {
            temp->isFree = 1;
            printf("Memory deallocated for Block ID %d\n", id);
            return;
        }
        temp = temp->next;
    }
    printf("Block ID %d not found or already free\n", id);
}

// Function to simulate garbage collection (collect all free blocks)
void garbageCollector() {
    struct Block* temp = head;
    printf("Running Garbage Collector...\n");
    int collected = 0;
    while (temp != NULL) {
        if (temp->isFree) {
            printf("Garbage collected: Block ID %d of size %d\n", temp->id, temp->size);
            collected = 1;
        }
        temp = temp->next;
    }
    if (!collected) {
        printf("No free blocks found.\n");
    }
}

// Function to display the memory blocks
void displayBlocks() {
    struct Block* temp = head;
    if (head == NULL) {
        printf("No blocks in memory.\n");
        return;
    }
    printf("Memory Blocks:\n");
    while (temp != NULL) {
        printf("Block ID: %d, Size: %d, Status: %s\n", temp->id, temp->size, temp->isFree ? "Free" : "Allocated");
        temp = temp->next;
    }
}

// Menu function to perform operations
void menu() {
    int choice, size, id;
    
    do {
        printf("\n--- Memory Allocator Menu ---\n");
        printf("1. Add Memory Block\n");
        printf("2. Allocate Memory\n");
        printf("3. Deallocate Memory\n");
        printf("4. Run Garbage Collector\n");
        printf("5. Display Memory Blocks\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter block size: ");
                scanf("%d", &size);
                addBlock(size);
                break;
            case 2:
                printf("Enter size to allocate: ");
                scanf("%d", &size);
                allocateMemory(size);
                break;
            case 3:
                printf("Enter Block ID to deallocate: ");
                scanf("%d", &id);
                deallocateMemory(id);
                break;
            case 4:
                garbageCollector();
                break;
            case 5:
                displayBlocks();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}
