//Write a C program to create a doubly linked list of a given size, and then delete a node from the start, end, or a specific position. Display the list after deletion.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL, *tail = NULL;

int main() {
    int size;
    printf("Enter size of doubly linked list: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (!newNode) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    int choice;
    printf("Delete node at:\n1. Start\n2. End\n3. Specific position\nChoice: ");
    scanf("%d", &choice);

    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return 0;
    }

    if (choice == 1) {
        struct Node *temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;
