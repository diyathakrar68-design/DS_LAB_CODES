//  WAP to swap Kth node from beginning with Kth node from end in a singly linked 
// list. 
#include <stdio.h>
#include <stdlib.h> 
struct Node {
    int data;
    struct Node* next;
};
void swapKthNode(struct Node** head_ref, int k) {
    struct Node* first = *head_ref;
    struct Node* second = *head_ref;
    struct Node* prev_first = NULL;
    struct Node* prev_second = NULL;
    int count = 1;

    // Find the Kth node from the beginning
    while (first != NULL && count < k) {
        prev_first = first;
        first = first->next;
        count++;
    }

    // If K is greater than the number of nodes
    if (first == NULL) return;

    // Find the Kth node from the end
    struct Node* temp = *head_ref;
    while (temp != NULL) {
        temp = temp->next;
        if (count > 0) {
            count--;
        } else {
            prev_second = second;
            second = second->next;
        }
    }

    // If Kth node from beginning and end are the same
    if (first == second) return;

    // Swap the nodes
    if (prev_first != NULL) {
        prev_first->next = second;
    } else {
        *head_ref = second;
    }

    if (prev_second != NULL) {
        prev_second->next = first;
    } else {
        *head_ref = first;
    }

    struct Node* temp_next = first->next;
    first->next = second->next;
    second->next = temp_next;
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
void swapKthNode(struct Node** head_ref, int k);
int main() {
    struct Node* head = NULL;

    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("Linked List before swapping:\n");
    printList(head);

    int k = 2;
    swapKthNode(&head, k);

    printf("Linked List after swapping %dth node from beginning and end:\n", k);
    printList(head);

    freeList(head);
    return 0;
}