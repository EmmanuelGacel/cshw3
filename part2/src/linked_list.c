#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void print_list(linked_list *list, void (*print_function)(void*)) {
    putchar('[');
    node *cur = list->head;
    if (cur != NULL) {
        print_function(cur->data);
        cur = cur->next;
    }
    for ( ; cur != NULL; cur = cur->next) {
        printf(", ");
        print_function(cur->data);
    }
    printf("]\n{length: %lu, head->data: ", list->size);
    list->head != NULL ? print_function(list->head->data) :
                         (void)printf("NULL");
    printf(", tail->data: ");
    list->tail != NULL ? print_function(list->tail->data) :
                         (void)printf("NULL");
    printf("}\n\n");
}

linked_list* create_linked_list(){
        linked_list *l = (linked_list *)malloc(sizeof(linked_list));
        if (l != NULL){//Do we need this???
                l->head = NULL;
                l->tail = NULL;
                l->size = 0;
        }
        return l;
}

bool insert_in_order(linked_list *list, void *data , int (*cmp)(const void*, const void *)){
        node *n = create_node(data); //Is it okay if I assign this node to a pointer
        if (list != NULL){
                if (cmp(data, list -> head) < 1){//Does this compare pointers or literals?
                        *list -> head -> prev = *n;
                        *list -> head = *n; //Are we storing literals of pointers?
                }else if (cmp(data, list -> tail) > 1){
                        *list -> tail -> next = *n;//Check arrow grammar
                        *list -> tail = *n;
                }else{
                        node* index;
                        for(index = (list -> head); (cmp(data, index->data) > 0); index = (index -> next));//Chech arrow grammar
                        *index -> prev =  *n;
                        *index = (*index -> prev);
                        *index -> next =  *n;
                }
        }else{
                list->head = list ->tail =  n;
        }
        return true;

}

void free_list(linked_list *list, void (*free_data)(void *)){
        while(list != NULL){
                free_node(list -> tail, *free_data);
        }
        free_data(list);
}
