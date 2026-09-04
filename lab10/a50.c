//  Write a program to swap two consecutive nodes in the linked list. Don’t change 
// the values of nodes, implement by changing the link of the nodes. 
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};  
void swapConsecutiveNodes(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* prev = NULL;

    while (current != NULL && current->next != NULL) {
        struct Node* next_node = current->next;

        // Swap the nodes
        current->next = next_node->next;
        next_node->next = current;

        if (prev == NULL) {
            *head_ref = next_node; // Update head for the first pair
        } else {
            prev->next = next_node; // Link previous node to the new first node
        }

        // Move to the next pair
        prev = current;
        current = current->next;
    }
}
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void freeList(struct Node* head) {
    struct Node* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
int main() {
    struct Node* head = NULL;

    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("Linked List before swapping consecutive nodes:\n");
    printList(head);

    swapConsecutiveNodes(&head);

    printf("Linked List after swapping consecutive nodes:\n");
    printList(head);

    freeList(head);
    return 0;
}