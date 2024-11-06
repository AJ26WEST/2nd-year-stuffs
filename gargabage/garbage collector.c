#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node {
    struct node* prev;
    int value;
    int size;
    struct node* next;
} node;

// Create a new node
node* create() {
    node* t = (node*)malloc(sizeof(node));
    if (!t) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter the value: ");
    scanf("%d", &(t->value));
    printf("Enter the size: ");
    scanf("%d", &(t->size));
    t->next = NULL;
    t->prev = NULL;
    return t;
}

// Insert node at the end of the list
node* insert(node* t, node* H) { 
    if (H == NULL) {
        return t;
    } else {
        node* p = H;
        while (p->next) {
            p = p->next;
        }
        p->next = t;
        t->prev = p;
    }
    return H;
}

// Insert garbage node
node* insertGarbage(int size, node* H) { 
    node* t = (node*)malloc(sizeof(node));
    if (!t) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    t->next = NULL;
    t->prev = NULL;
    t->size = size;
    t->value = INT_MIN;
    
    if (H == NULL) {
        return t;
    } else {
        node* p = H;
        while (p->next) {
            p = p->next;
        }
        p->next = t;
        t->prev = p;
    }
    return H;
}

// Display list
void display(node* H) {
    printf("\nThe current list is: ");
    node* p = H;
    if (p) {
        while (p) {
            printf(p->value != INT_MIN ? "%d -> " : "# -> ", p->value);
            p = p->next;
        }
        printf("NULL\n");

        printf("The corresponding sizes are: ");
        p = H;
        while (p) {
            printf("%d -> ", p->size);
            p = p->next;
        }
        printf("NULL\n");
    } else {
        printf("List is empty\n");
    }
}

// Display garbage list
void displayGarbage(node* HG) {
    printf("\nThe garbage sizes are: ");
    node* p = HG;
    if (p) {
        while (p) {
            printf("%d -> ", p->size);
            p = p->next;
        }
        printf("NULL\n");
    } else {
        printf("No garbage collected\n");
    }
}

// Delete node at specified position
node* delete(node* H, node* HG) {
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    
    if (!H) {
        printf("List is empty\n");
        return HG;
    }
    
    node* p = H;
    for (int i = 1; i < pos; i++) {
        if (!p->next) {
            printf("Position out of range\n");
            return HG;
        }
        p = p->next;
    }
    
    if (p->value != INT_MIN) {
        p->value = INT_MIN;
        HG = insertGarbage(p->size, HG);
    } else {
        printf("Position already marked as garbage\n");
    }
    
    display(H);
    return HG;
}

// Collect and display garbage
void garbageCollection(node* H, node* HG) {
    node* p = H;
    int garbage = 0;
    
    while (p) {
        if (p->value == INT_MIN) {
            garbage += p->size;
        }
        p = p->next;
    }
    
    printf("The amount of garbage collected is: %d\n", garbage);
    displayGarbage(HG);
}

int main() {
    node* HL = NULL;
    node* HG = NULL;
    int n;
    
    while (1) {
        printf("\n\n============================");
        printf("\n1. Display\n2. Insert\n3. Delete\n4. Collect Garbage\n5. Exit");
        printf("\n============================");
        printf("\nEnter Choice: ");
        scanf("%d", &n);
        
        node* t;
        switch (n) {
            case 1:
                display(HL);
                break;
            case 2:
                t = create();
                HL = insert(t, HL);
                display(HL);
                break;
            case 3:
                HG = delete(HL, HG);
                break;
            case 4:
                garbageCollection(HL, HG);
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong option selected\n");
        }
    }
    return 0;
}
