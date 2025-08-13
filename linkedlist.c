#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

void init_llist(LinkedList *llist){
    llist->head = NULL;
    llist->size = 0;
}

void insert_head_llist(LinkedList *llist, int value){
    Node *new = malloc(sizeof(Node));
    if(new==NULL){
        printf("Error: No space in heap");
        return;
    }
    new->data=value;
    new->next=llist->head;
    llist->head=new;
    llist->size++;
}

void insert_tail_llist(LinkedList *llist, int value){
    Node *new = malloc(sizeof(Node));
    if(new==NULL){
        printf("Error: No space in heap");
        return;
    }
    new->data=value;
    new->next=NULL;

    if(llist->head==NULL){
        llist->head=new;
    }
    else{
        Node *cur = llist->head;
        while(cur->next!=NULL){
            cur=cur->next;
        }

        cur->next=new;
    }

    llist->size++;
}

void insert_llist(LinkedList *llist, int value, int position) {
    if (position<0 || position>llist->size){
        printf("Error: invalid position\n");
        return;
    }
    if(position==0){
        insert_head_llist(llist, value);
        return;
    }

    Node *cur = llist->head;
    for (int i=0; i<position-1; i++){
        cur = cur->next;
    }
    Node *next = cur->next;

    Node *new = malloc(sizeof(Node));
    if(new==NULL){
        printf("Error: No space in heap");
        return;
    }
    new->data=value;

    cur->next = new;
    new->next = next;

    llist->size++;
}

void remove_head_llist(LinkedList *llist){
    if (llist->head==NULL){
        printf("Error: why would you do that...");
        return;
    }
    Node *temp = llist->head;
    llist->head = temp->next;
    free(temp);
    llist->size--;
}

void remove_tail_llist(LinkedList *llist){
    if (llist->head==NULL){
        printf("Error: why would you do that...");
        return;
    }

    if(llist->size>1){
        Node *cur = llist->head;
        while(cur->next->next!=NULL){
            cur=cur->next;
        }
        free(cur->next);
        cur->next=NULL;
    }
    else{
        remove_head_llist(llist);
    }
    llist->size--;
}

void remove_llist(LinkedList *llist, int position){
    if(position < 0 || position>(llist->size-1)){
        printf("Error: why would you do that...");
        return;
    }
    
    if (position==0){
        remove_head_llist(llist);
        return;
    }
    
    Node *prev = NULL;
    Node *cur = llist->head;
    for(int i=0; i<position; i++){
        prev=cur;
        cur=cur->next;
    }
    
    Node *next = cur->next;
    free(cur);
    prev->next=next;
    
    llist->size--;
}

Node* get_node_llist(LinkedList *llist, int position){
    if(position < 0 || position>(llist->size-1)){
        printf("Error: why would you do that...");
        return NULL;
    }
    Node *cur = llist->head;
    for(int i=0; i<position; i++){
        cur = cur->next;
    }
    return cur;
}

int get_val_llist(LinkedList *llist, int position){
    return get_node_llist(llist, position)->data;
}

int get_size_llist(LinkedList *llist){
    return llist->size;
}

void print_llist(LinkedList *llist){
    Node* cur = llist->head;
    while (cur!=NULL){
        printf("%d", cur->data);
        cur=cur->next;
    }
    printf("\n");
}

void free_llist(LinkedList *llist){
    Node* cur = llist->head;
    while (cur!=NULL){
        Node* temp = cur;
        cur = cur->next;
        free(temp);
    }

    llist->head=NULL;
    llist->size=0;
}

// int main(){
//     LinkedList llist;
//     init_llist(&llist);
//     insert_tail_llist(&llist, 1);
//     insert_head_llist(&llist, 2);
//     insert_llist(&llist, 3, 1);
//     insert_tail_llist(&llist, 4);
//     insert_tail_llist(&llist, 5);
//     insert_tail_llist(&llist, 6);
//     print_llist(&llist);
//     printf("%d\n", get_size_llist(&llist));
//     remove_llist(&llist, 5);
//     remove_llist(&llist, 2);
//     print_llist(&llist);
//     printf("%d\n", get_size_llist(&llist));
//     free_llist(&llist);
//     print_llist(&llist);
//     printf("%d\n", get_size_llist(&llist));

//     print_llist(&llist);
//     return 0;
// }