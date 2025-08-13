#ifndef STACK_H
#define STACK_H

#include "list.h"

typedef struct Stack {
    List s;
} Stack;


void init_stack(Stack *stack);

void push_stack(Stack *stack, int value);

void pop_stack(Stack *stack);

void print_stack(Stack *stack);

int cur_size_stack(Stack * stack);

#endif