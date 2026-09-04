//  WAP to perform given operation in the linked list. There exist a Linked List. Add 
// a node that contains the GCD of those two nodes between every pair adjacent 
// node of Linked List. 
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
int gcd(int a, int b) { 
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
void insertGCDNodes(struct Node** head_ref) {
    struct Node* current = *head_ref;
    while (current != NULL && current->next != NULL) {
        int gcd_value = gcd(current->data, current->next->data);
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = gcd_value;
        new_node->next = current->next;
        current->next = new_node;
        current = new_node->next; // Move to the next original node
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

    // Creating a linked list: 12 -> 15 -> 21 -> NULL
    push(&head, 21);
    push(&head, 15);
    push(&head, 12);

    printf("Linked List before inserting GCD nodes:\n");
    printList(head);

    insertGCDNodes(&head);

    printf("Linked List after inserting GCD nodes:\n");
    printList(head);

    freeList(head);
    return 0;
}