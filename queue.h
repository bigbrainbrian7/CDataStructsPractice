#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"
#include <stdbool.h>

typedef struct Queue {
    LinkedList list;
    Node *front;
    Node *rear;
} Queue;

void init_queue(Queue *q);

bool is_empty_queue(Queue *q);

void enqueue(Queue *q, int value);

int dequeue(Queue *q);

int get_size_queue(Queue *q);

void print_queue(Queue *q);

#endif