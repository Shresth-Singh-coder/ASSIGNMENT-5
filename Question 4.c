//Write a C program to create a circular singly linked list of user-defined size, where each node contains integer data. After creating the list, display the elements in the list by traversing it once.

#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the circular linked list
struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int size, i, value;

    // Input the number of nodes
    printf("Enter the number of nodes in the circular linked list: ");
    scanf("%d", &size);

    // Loop to create the circular linked list
    for (i = 0; i < size; i++) {
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
            head->next = head;  // Point to itself (circular)
            temp = head;
        } else {
            newNode->next = head;  // Point new node to head
            temp->next = newNode;  // Link previous node to new node
            temp = newNode;        // Move temp to last node
        }
    }

    // Display the elements in the circular linked list
    printf("\nCircular Linked List contents:\n");
    if (head != NULL) {
        temp = head;
        do {
            printf("%d\n", temp->data);
            temp = temp->next;
        } while (temp != head);
    } else {
        printf("The list is empty.\n");
    }

    return 0;
}
