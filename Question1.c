#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *previous;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

int main () {

    printf("Enter size of doubly linked list : ");
    int size;
    scanf("%d", &size);

    for (int a = 1; a <= size; a++) {
        struct node *nnode = (struct node *) malloc (sizeof(struct node));

        if (nnode == NULL) {
            printf("Memory allocation failed!");
            return -1;
        }

        printf("Enter data : ");
        scanf("%d", &nnode->data);

        nnode->previous = NULL;
        nnode->next = NULL;

        if (head == NULL) {
            head = nnode;
            tail = nnode;
        } else {
            tail->next = nnode;
            nnode->previous = tail;
            tail = nnode;
        }
    }

    struct node *temp = head;

    printf("Printing in forward direction-\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    temp = tail;

    printf("Printing in backward direction-\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->previous;
    }
    
    return 0;
}
