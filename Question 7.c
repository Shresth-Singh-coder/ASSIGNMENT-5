//Write a C program to create two separate circular singly linked lists. Allow the user to input the number of nodes and data for each list. After creating both lists, join them into a single circular list such that the last node of the first list points to the first node of the second list, and the last node of the second list points to the head of the first list. Finally, display the combined circular linked list.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head, *head1 = NULL, *head2 = NULL, *temp1, *temp2;

int main() {
    int size1, size2;

    printf("Enter total nodes in first circular list: ");
    scanf("%d", &size1);

    for (int i = 0; i < size1; i++) {
        struct node *nnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &nnode->data);

        if (head1 == NULL) {
            head1 = nnode;
            temp1 = nnode;
            temp1->next = head1;
        } else {
            nnode->next = temp1->next;
            temp1->next = nnode;
            temp1 = nnode;
        }
    }

    printf("Enter total nodes in second circular list: ");
    scanf("%d", &size2);

    for (int i = 0; i < size2; i++) {
        struct node *nnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &nnode->data);

        if (head2 == NULL) {
            head2 = nnode;
            temp2 = nnode;
            temp2->next = head2;
        } else {
            nnode->next = temp2->next;
            temp2->next = nnode;
            temp2 = nnode;
        }
    }

    temp1->next = head2;
    temp2->next = head1;

    head = head1;
    temp1 = head;

    do {
        printf("%d", temp1->data);
        temp1 = temp1->next;
    } while (temp1 != head);

    printf("\n");

    return 0;
}
