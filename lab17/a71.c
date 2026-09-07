// Write a program to implement queue using singly linked list.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node* temp = front;
    printf("Dequeued: %d\n", temp->data);
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}