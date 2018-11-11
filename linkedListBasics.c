#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node NODE;

NODE *head = NULL;

void _add(int data, NODE *target);
void _printList();
NODE* get_node(int data);

int main(void) {
    NODE *target;

    _add(10, NULL);
    _add(20, NULL);
    _add(30, NULL);
    _add(40, NULL);

    target = get_node(40);
    
    _add(35, target);
    _add(5, head);

    _printList();

    return 0;
}

void _add(int data, NODE *target) {
    //set current to point to the head, and allocate memory for new node
    NODE *current = head;
    NODE *new_node = (NODE*) malloc(sizeof(NODE));

    if (new_node == NULL) {
        puts("Error allocating memory");
        exit(0);
    }

    //init the new_node
    new_node->data = data;
    new_node->next = target;

    printf("new_node memory address: %d, value: %d\n", new_node, new_node->data);

    //now check if the target address is the head
    if (target == head) {
        head = new_node;
        printf("new head address: %d, value: %d\n", head, head->data);
        return;
    }

    while (current->next != target) {
           printf("the current head: %d, %d\n", head, head->data);
           current = current->next;
    }

    printf("hit the tail\nmemory location: %d, value: %d\n", current, current->data);

    current->next = new_node;

    printf("tail pointer address: %d\n", current->next);
}

NODE* get_node(int data) {
    NODE *current = head;

    printf("The head address in get_node fn: %d \n", current);

    while (current->data != data) {
           current = current->next;
    }
    printf("Reached the node at: %d\n", current);

    return current;
}

void _printList() {
    printf("\n\n");
    NODE *current = head;

    while (current->next != NULL) {
            printf("current address %d, value: %d \n", current, current->data);
            current = current->next;
    }
    printf("current address %d, value: %d \n", current, current->data);
    printf("end of list\n");
}
