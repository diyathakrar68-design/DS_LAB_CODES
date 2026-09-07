//  WAP to delete alternate nodes of a doubly linked list.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
void deleteAlternateNodes(struct Node** head_ref) {
    if (*head_ref == NULL) return;

    struct Node* current = *head_ref;
    struct Node* next_node;

    while (current != NULL && current->next != NULL) {
        next_node = current->next;
        current->next = next_node->next;
        if (next_node->next != NULL) {
            next_node->next->prev = current;
        }
        free(next_node);
        current = current->next;
    }
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
int main() {
    struct Node* head = NULL;
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Insert a node at the end\n");
        printf("2. Delete alternate nodes\n");
        printf("3. Display all nodes\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 2:
                deleteAlternateNodes(&head);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}