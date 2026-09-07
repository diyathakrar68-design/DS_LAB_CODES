//  WAP to split a circular linked list into two halves.
#include <stdio.h>
#include <stdlib.h> 

struct Node {
    int data;
    struct Node* next;
};
void splitList(struct Node* head, struct Node** head1_ref, struct Node** head2_ref) {
    if (head == NULL) return;

    struct Node* slow_ptr = head;
    struct Node* fast_ptr = head;

    // Use the tortoise and hare algorithm to find the middle
    while (fast_ptr->next != head && fast_ptr->next->next != head) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    // Set the heads of the two halves
    *head1_ref = head;
    *head2_ref = slow_ptr->next;

    // Make the first half circular
    slow_ptr->next = *head1_ref;

    // Make the second half circular
    struct Node* temp = *head2_ref;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = *head2_ref;
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
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // Creating a circular linked list: 1 -> 2 -> 3 -> 4 -> 5 -> (back to head)
    for (int i = 5; i >= 1; i--) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = i;
        if (head == NULL) {
            new_node->next = new_node; // Point to itself
            head = new_node;
        } else {
            struct Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->next = head;
        }
    }

    printf("Original Circular Linked List:\n");
    displayList(head);

    splitList(head, &head1, &head2);

    printf("First Half Circular Linked List:\n");
    displayList(head1);

    printf("Second Half Circular Linked List:\n");
    displayList(head2);

    freeList(head1);
    freeList(head2);

    return 0;
}