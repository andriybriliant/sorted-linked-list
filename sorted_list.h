#include <stdio.h>
#include <stdbool.h>
#include <limits.h>


typedef struct sorted_list {
    int key;
    struct sorted_list* next;
} sorted;

typedef struct return_two_lists {
    sorted* first;
    sorted* second;
} return_two_lists;

typedef sorted* list;

void show(list);
void add(list*, int);
void remove_first(list*);
bool find_element(list, int);
bool remove_found(list*, int);
int get_first_element(list*);
int get_last_element(list*);
void delete_list(list*);
void read_from_a_file(list*);
void connect_two_lists(list*, list*);
return_two_lists compare_two_lists(list, list);