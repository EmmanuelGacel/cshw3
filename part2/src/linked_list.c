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
	linked_list *l = (linked_list *)malloc(sizeof*(inked_list));
	if (linked_list != NULL){
		l->head = NULL;
		l->tail = NULL;
		l->size_t = 0;
	}
	return n;
}

void insert_in_order(linked_list *list, void *data , int (*cmp)(const void*, const void *)){
	if (list != null){
		if (cmp(*data, list -> head) < 1){//Does this compare pointers or literals?
			list -> head -> previous = *data;
			list -> head = *data; //Are we storing literals of pointers?
		}else if (cmp(*data, list -> tail) < 1){
			list -> tail -> next = *data;//Check arrow grammar
			list->tail = *data;
		}else{
			*void index;
			for(index = (list -> head); cmp(*data, index) < 1; index = (index -> next));//Chech arrow grammar
			index -> previous = *data;
			index = (index -> previous);
			index -> next = *data;
			}
		}
	}else(cmp(*data, list -> tail) < 1, list - ){
		list->head = list ->tail = *data;
	}
}

void free_list(linked_list *list, void (*free_data)(void *)){
	while((*list != null) != NULL){
		free_data(list -> tail);
	}
}
