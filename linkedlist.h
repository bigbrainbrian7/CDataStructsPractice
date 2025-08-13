#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    int size;
} LinkedList;

void init_llist(LinkedList *llist);

void insert_head_llist(LinkedList *llist, int value);

void insert_tail_llist(LinkedList *llist, int value);

void insert_llist(LinkedList *llist, int value, int position);

void remove_head_llist(LinkedList *llist);

void remove_tail_llist(LinkedList *llist);

void remove_llist(LinkedList *llist, int position);

Node* get_node_llist(LinkedList *llist, int position);

int get_val_llist(LinkedList *llist, int position);

int get_size_llist(LinkedList *llist);

void print_llist(LinkedList *llist);

#endif