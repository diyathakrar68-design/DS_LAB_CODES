//  Write a program to remove the duplicates nodes from given sorted Linked List.
#include <stdio.h>  
#include <stdlib.h>  

struct Node {
    int data;
    struct Node* next;
};
void removeDuplicates(struct Node* head) {
    struct Node* current = head;
    struct Node* next_next;

    if (current == NULL) return;

    while (current->next != NULL) {
        if (current->data == current->next->data) {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        } else {
            current = current->next;
        }
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

    push(&head, 20);
    push(&head, 13);
    push(&head, 13);
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);

    printf("Linked List before removing duplicates:\n");
    printList(head);

    removeDuplicates(head);

    printf("Linked List after removing duplicates:\n");
    printList(head);

    freeList(head);
    return 0;
}
