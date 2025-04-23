//Write a C program to create a doubly linked list of given size and allow the user to insert a node at the beginning, end, or at a specific position in the list. Display the list after insertion.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL, *tail = NULL, *temp;

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
    printf("Insert node at:\n1. Start\n2. End\n3. Specific position\nChoice: ");
    scanf("%d", &choice);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    newNode->next = NULL;

    if (choice == 1) {
        newNode->next = head;
        if (head != NULL) head->prev = newNode;
        head = newNode;
    } else if (choice == 2) {
        if (tail != NULL) tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    } else if (choice == 3) {
        int position;
        printf("Enter the position after which to insert (1-based index): ");
        scanf("%d", &position);

        temp = head;
        for (int i = 1; i < position && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp != NULL && temp->next != NULL) {
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        } else if (temp == tail) { // inserting after last node
            temp->next = newNode;
            newNode->prev = temp;
            tail = newNode;
        } else {
            printf("Invalid position!\n");
            free(newNode);
        }
    } else {
        printf("Invalid choice!\n");
        free(newNode);
    }

    printf("Doubly Linked List contents:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    return 0;
}
