#include <stdio.h>
#include "linked_list.h"

int main() {
    LinkedList* head = init_list();
    push_back(head, 5);
    push_back(head, 6);
    // printf("index: %d\n", get_element_by_index(head, 2));
    for (int i = 0; i < get_length(head); i++) {
        // printf("index: %d; element: %d\n", i, get_element_by_index(head, i));
        printf("index: %d; element: %d\n", get_index_by_value(head, get_element_by_index(head, i+1)), get_element_by_index(head, i));
    }
    printf("%d\n", get_length(head));
    print_list(head);
}