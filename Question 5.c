//Write a C program to create a circular singly linked list of user-defined size. Then insert a new node at a user-specified position (not at the beginning or end), and display the updated list.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int size, value, place;

    printf("Enter the number of nodes in the circular linked list: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return -1;
        }

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        newNode->data = value;

        if (head == NULL) {
            head = newNode;
            head->next = head;
            temp = head;
        } else {
            newNode->next = head;
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Enter the position to insert a new node: ");
    scanf("%d", &place);

    temp = head;
    for (int i = 1; i < place - 1; i++) {
        temp = temp->next;
    }

    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    printf("Enter data for the new node: ");
    scanf("%d", &value);
    newNode->data = value;

    newNode->next = temp->next;
    temp->next = newNode;

    temp = head;
    do {
        printf("%d\n", temp->data);
        temp = temp->next;
    } while (temp != head);

    return 0;
}
