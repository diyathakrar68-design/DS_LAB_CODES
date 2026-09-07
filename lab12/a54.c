//  Write a menu driven program to implement following operations on the doubly 
// linked list. 
//  Insert a node at the front of the linked list. 
//  Delete a node from specified position. 
//  Insert a node at the end of the linked list. (Home Work) 
//  Display all nodes. (Home Work)
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
void insertAtFront(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    new_node->prev = NULL;

    if (*head_ref != NULL) {
        (*head_ref)->prev = new_node;
    }
    *head_ref = new_node;
}
void deleteNode(struct Node** head_ref, int position) {
    if (*head_ref == NULL) return;

    struct Node* temp = *head_ref;

    // If head needs to be removed
    if (position == 0) {
        *head_ref = temp->next;
        if (*head_ref != NULL) {
            (*head_ref)->prev = NULL;
        }
        free(temp);
        return;
    }

    // Find the node to be deleted
    for (int i = 0; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return; // Position is out of bounds

    // Unlink the node from the list
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
}
void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d <-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref; // Used to traverse to the end of the list
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}
void menu() {
    printf("Menu:\n");
    printf("1. Insert a node at the front\n");
    printf("2. Delete a node from specified position\n");
    printf("3. Insert a node at the end\n");
    printf("4. Display all nodes\n");
    printf("5. Exit\n");
}
int main() {
    struct Node* head = NULL;
    int choice, data, position;

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertAtFront(&head, data);
                break;
            case 2:
                printf("Enter position to delete node from: ");
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}