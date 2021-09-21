// FIX HEAD NOT HAVING A VALUE
#include <stdlib.h>
#include <stdio.h>

typedef struct LinkedList {
    int data;
    struct LinkedList* next;
} LinkedList;


void push_back(LinkedList* head, int value) {
    LinkedList* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = (LinkedList*) malloc(sizeof(LinkedList));
    current->next->data = value;
    current->next->next = NULL;
}

void pop_back(LinkedList* head) {
    LinkedList* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    current->next = NULL;
    free(current->next);
}

void print_list(LinkedList* head) {
    LinkedList* current = head;
    while ((current = current->next) != NULL) printf("%d ", current->data);
    printf("\n");
}

int get_length(LinkedList* head) {
    int res = -1;
    LinkedList* current = head;
    while (current != NULL) {
        current = current->next;    
        res++;
    }

    return res;
}

int get_element_by_index(LinkedList* head, int index) {
    if (index > get_length(head) - 1 || index == -1) return -1;
    LinkedList* current = head;
    for (int i = 0; i < index; i++) current = current->next;
    return current->next->data;
}

int get_index_by_value(LinkedList* head, int value) {
    LinkedList* current = head;
    for (int i = 0; i < get_length(head); i++) {
        current = current->next;
        if (current->data == value) {
            return i;
            break;
        }
    }
    return -1;
}

LinkedList* init_list() {
    LinkedList* head;
    head = (LinkedList*) malloc(sizeof(LinkedList));
    return head;
}