#include "linkedlist.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct Queue {
    LinkedList list;
    Node *front;
    Node *rear;
} Queue;

void init_queue(Queue *q){
    init_llist(&(q->list));
    q->front = NULL;
    q->rear = NULL;
}

bool is_empty_queue(Queue *q){
    return get_size_llist(&(q->list))<=0;
}

//not O(1) - didnt implement front and rear yet
void enqueue(Queue *q, int value){
    insert_tail_llist(&(q->list), value);
}

int dequeue(Queue *q){
    if(is_empty_queue(q)){
        printf("Error: nothing TO deque");
        return -1;
    }

    int result=get_val_llist(&(q->list), 0);

    remove_head_llist(&(q->list));

    return result;
}

int get_size_queue(Queue *q){
    return get_size_llist(&(q->list));
}

void print_queue(Queue *q){
    print_llist(&(q->list));
}

// int main(){
//     Queue *q = malloc(sizeof(Queue));
//     init_queue(q);

//     enqueue(q, 1);
//     enqueue(q, 2);
//     enqueue(q, 3);
    
//     print_queue(q);
//     dequeue(q);
//     enqueue(q, 4);
//     dequeue(q);
//     dequeue(q);
//     dequeue(q);
//     print_queue(q);
//     dequeue(q);
//     print_queue(q);
    
//     return 0;
// }