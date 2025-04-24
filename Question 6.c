//Write a C program to create a circular singly linked list with n nodes. Allow the user to input the data for each node. After the list is created, ask the user to enter a position, and delete the node at that position. Finally, display the circular linked list. Assume 1-based indexing for the deletion position.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *temp;

int main() {
    int size, place;

    printf("Enter total nodes in circular linked list: ");
    scanf("%d", &size);

    for (int i = 1; i <= size; i++) {
        struct node *nnode = (struct node *)malloc(sizeof(struct node));

        if (nnode == NULL) {
            printf("Unable to allocate memory.\n");
            return 1;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &nnode->data);

        if (head == NULL) {
            head = nnode;
            head->next = head;
            temp = head;
        } else {
            nnode->next = temp->next;
            temp->next = nnode;
            temp = nnode;
        }
    }

    printf("Enter position of node to remove: ");
    scanf("%d", &place);

    temp = head;
    for (int i = 1; i < place - 1; i++) {
        temp = temp->next;
    }

    struct node *temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);

    temp = head;
    do {
        printf("%d\n", temp->data);
        temp = temp->next;
    } while (temp != head);

    return 0;
}
