#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void free_list(List *list){
    //free technically already does safety checking for null, but whatever
    if (list->array!=NULL){
        free(list->array);
        list->array=NULL;
    }
    list->max_size=0;
    list->cur_size=0;

}

void init_list(List *list){
    list->array = malloc(sizeof(int)*8);
    if (list->array==NULL) {
        printf("Error initilaizing array: no space in heap");
        free_list(list);
        return;
    }
    list->max_size = 8;
    list->cur_size = 0;
}

void append_list(List *list, int value){
    if (list->cur_size >= list->max_size) {
        list->array = realloc(list->array, sizeof(int)*list->max_size*2);
        if (list->array==NULL) {
            printf("Error reallocating array: no space in heap");
            free_list(list);
            return;
        }
        list->max_size*=2;
    }
    *(list->array+list->cur_size)=value;
    list->cur_size++;
}


//zero-indexed
void insert_list(List *list, int value, int position) {
    if (list->cur_size >= list->max_size) {
        list->array = realloc(list->array, sizeof(int)*list->max_size*2);
        if (list->array==NULL) {
            printf("Error reallocating array: no space in heap");
            free_list(list);
            return;
        }
        list->max_size*=2;
    }

    if (position>list->cur_size) {
        printf("Cannot insert beyond highest index");
        return;
    }
    
    *(list->array+position) = value;
    
    if (position == list->cur_size) {
        list->cur_size++;
    }
}

void remove_list(List *list, int position) {
    if (list->cur_size<=0) {
        printf("Cannot remove from empty list");
        return;
    }
    if (position>=list->cur_size) {
        printf("Cannot remove beyond highest index");
        return;
    }

    for(int i=position; i<list->cur_size-1;i++){
        *(list->array+i)=*(list->array+i+1);
    }

    list->cur_size--;
}


void print_list(List *list){
    for (int i=0; i<list->cur_size; i++){
        printf("%d", *(list->array+i));
    }
    printf("\n");
}

int cur_size_list(List *list){
    return list->cur_size;
}

void pop_list(List *list){
    list->cur_size--;
}

int max_size_list(List *list){
    return list->max_size;
}

// int main() {
//     List list;
//     init_list(&list);
//     append_list(&list, 1);
//     printf("%d\n", cur_size_list(&list));
//     append_list(&list, 2);
//     printf("%d\n", cur_size_list(&list));
//     append_list(&list, 3);
//     printf("%d\n", cur_size_list(&list));
//     insert_list(&list, 4, 3);
//     printf("%d\n", cur_size_list(&list));
//     remove_list(&list, 4);
//     printf("%d\n", cur_size_list(&list));
//     print_list(&list);

//     return 0;
// }