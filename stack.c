#include "stack.h"
#include "list.h"
#include <stdio.h>


void init_stack(Stack *stack){
    init_list(&(stack->s));
}

void push_stack(Stack *stack, int value){
    append_list(&(stack->s), value);
}

void pop_stack(Stack *stack){
    // remove_list(&(stack->s), cur_size_list(&(stack->s))-1);
    pop_list(&(stack->s));
}

void print_stack(Stack *stack){
    print_list(&(stack->s));
}

int cur_size_stack(Stack * stack){
    return cur_size_list(&(stack->s));
}

int main (){
    Stack stack;
    init_stack(&stack);
    push_stack(&stack, 1);
    push_stack(&stack, 2);
    push_stack(&stack, 3);
    print_stack(&stack);
    pop_stack(&stack);
    print_stack(&stack);
    push_stack(&stack, 4);
    print_stack(&stack);
    printf("%d", cur_size_stack(&stack));
    return 0;
}

