// . Write a program to sort elements of a linked list.
#include <stdio.h>  
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void sortList(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* next_node;
    int temp;

    while (current != NULL) {
        next_node = current->next;
        while (next_node != NULL) {
            if (current->data > next_node->data) {
                temp = current->data;
                current->data = next_node->data;
                next_node->data = temp;
            }
            next_node = next_node->next;
        }
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
int main() {
    struct Node* head = NULL;

    // Creating a linked list: 30 -> 10 -> 20 -> 40 -> NULL
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = 30;
    new_node->next = head;
    head = new_node;

    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = 10;
    new_node->next = head;
    head = new_node;

    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = 20;
    new_node->next = head;
    head = new_node;

    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = 40;
    new_node->next = head;
    head = new_node;

    printf("Linked List before sorting:\n");
    printList(head);

    sortList(&head);

    printf("Linked List after sorting:\n");
    printList(head);

    // Free the allocated memory
    struct Node* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return 0;
}
void freeList(struct Node* head) {
    struct Node* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
