//  Write a menu driven program to implement following operations on the circular 
// linked list. 
//  Insert a node at the front of the linked list. 
//  Delete a node from specified position. 
//  Insert a node at the end of the linked list. 
//  Display all nodes.

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void insertAtFront(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    if (*head_ref == NULL) {
        new_node->next = new_node; // Point to itself
        *head_ref = new_node;
    } else {
        struct Node* temp = *head_ref;
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
}
void deleteNode(struct Node** head_ref, int position) {
    if (*head_ref == NULL) return;

    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    // If head needs to be removed
    if (position == 0) {
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        if (temp == *head_ref) { // Only one node
            free(*head_ref);
            *head_ref = NULL;
        } else {
            temp->next = (*head_ref)->next;
            free(*head_ref);
            *head_ref = temp->next;
        }
        return;
    }

    // Find the node to be deleted
    for (int i = 0; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
        if (temp == *head_ref) break; // Reached back to head
    }

    if (temp == NULL || temp == *head_ref) return; // Position is out of bounds

    prev->next = temp->next;
    free(temp);
}
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    if (*head_ref == NULL) {
        new_node->next = new_node; // Point to itself
        *head_ref = new_node;
    } else {
        struct Node* temp = *head_ref;
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = *head_ref;
    }
}
void displayList(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}
void freeList(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    struct Node* next_node;
    do {
        next_node = temp->next;
        free(temp);
        temp = next_node;
    } while (temp != head);
}
int main() {
    struct Node* head = NULL;
    int choice, data, position;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Delete from position\n");
        printf("3. Insert at end\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertAtFront(&head, data);
                break;
            case 2:
                printf("Enter position to delete (0-based index): ");
                scanf("%d", &position);
                deleteNode(&head, position);
                break;
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                freeList(head);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}