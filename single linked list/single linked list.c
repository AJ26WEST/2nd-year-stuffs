#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Insert at the beginning
void Insert_Begin() {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (!temp) {
        printf("Memory overflow\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &temp->data);
    temp->next = head;
    head = temp;
}

// Insert at the end
void Insert_End() {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (!temp) {
        printf("Memory overflow\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        struct node *ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

// Insert at a specific position
void Insert_AnyPos() {
    int key;
    printf("Enter the element to insert: ");
    scanf("%d", &key);

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (!temp) {
        printf("Memory overflow\n");
        return;
    }
    temp->data = key;

    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        temp->next = head;
        head = temp;
        return;
    }

    struct node *ptr = head;
    for (int i = 1; i < pos - 1 && ptr != NULL; i++) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Position is out of bounds\n");
        free(temp);
    } else {
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

// Delete from the beginning
void Delete_Begin() {
    if (head == NULL) {
        printf("Memory Underflow\n");
        return;
    }
    
    struct node *temp = head;
    head = head->next;
    free(temp);
}

// Delete from the end
void Delete_End() {
    if (head == NULL) {
        printf("Memory Underflow\n");
        return;
    }

    struct node *ptr = head;
    struct node *temp = NULL;

    if (ptr->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    while (ptr->next != NULL) {
        temp = ptr;
        ptr = ptr->next;
    }
    
    temp->next = NULL;
    free(ptr);
}

// Delete from a specific position
void Delete_AnyPos() {
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("Memory Underflow\n");
        return;
    }

    struct node *ptr = head;

    if (pos == 1) {
        head = head->next;
        free(ptr);
        return;
    }

    struct node *prev = NULL;
    for (int i = 1; i < pos && ptr != NULL; i++) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Position is out of bounds\n");
        return;
    }

    prev->next = ptr->next;
    free(ptr);
}

// Display all elements in the linked list
void Display() {
    struct node *ptr = head;

    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List Elements: ");
    while (ptr != NULL) {
        printf("%d", ptr->data);
        ptr = ptr->next;
        if (ptr != NULL) {
            printf(" -> ");
        }
    }
    printf(" -> NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1: Insertion\n2: Deletion\n3: Display\n4: Exit\nChoice: ");
        scanf("%d", &choice);
        int pos;
        switch (choice) {
            case 1:
                printf("Select Position:\n1: Front\n2: End\n3: Between Nodes\nChoice: ");
                scanf("%d", &pos);
                if (pos == 1) Insert_Begin();
                else if (pos == 2) Insert_End();
                else if (pos == 3) Insert_AnyPos();
                else printf("Wrong Input\n");
                break;

            case 2:
                printf("Select Position:\n1: Front\n2: End\n3: Between Nodes\nChoice: ");
                scanf("%d", &pos);
                if (pos == 1) Delete_Begin();
                else if (pos == 2) Delete_End();
                else if (pos == 3) Delete_AnyPos();
                else printf("Wrong Input\n");
                break;

            case 3:
                Display();
                break;

            case 4:
                printf("Exited!\n");
                exit(0);

            default:
                printf("Wrong Choice!\n");
                break;
        }
    }
    return 0;
}
