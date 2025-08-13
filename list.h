#ifndef LIST_H
#define LIST_H

typedef struct List {
    int *array;
    int max_size;
    int cur_size;
} List;

void free_list(List *list);

void init_list(List *list);

void append_list(List *list, int value);

void print_list(List *list);

void insert_list(List *list, int value, int position);

void remove_list(List *list, int position);

int cur_size_list(List *list);

void pop_list(List *list);

int max_size_list(List *list);

#endif