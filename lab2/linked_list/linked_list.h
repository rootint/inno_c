#include "linked_list.c"

struct LinkedList;

void push_back(LinkedList* head, int value);

int get_length(LinkedList* head);

void pop_back(LinkedList* head);

void print_list(LinkedList* head);

LinkedList* init_list();
