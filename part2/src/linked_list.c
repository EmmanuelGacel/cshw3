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
        
	node *n = create_node(data); 	
	if (list != NULL && list -> head == NULL){
		//Inserts the first node into an empty list
		if (list -> head == NULL){
			list -> head = list -> tail = n;
                        ++list->size;
		}
	}else if(cmp(data, list->head->data) < 0){ //Inserts nodes at the head
                 list -> head -> prev = n;
                 n -> next = list -> head;
                 list -> head = n;
                 ++list->size;

	}else{
		node* index = list->head; //creates temp pointer to head
		for( ; (cmp(data, index->data) > 0) && (index -> next) != NULL; index = (index->next)); //Moves index to its correct spot + 1;
		if(cmp(data, index->data) == 0){//Dulicate inserter
			while(cmp(data, index->data) == 0 && index -> next != NULL){
				index = (index->next);//Moves index past all duplicates
                	}
			if (cmp(data, index -> data ) < 0){//Inserts a dupicate node in the non-tail position after cycling thorugh all matches
				n -> prev = index -> prev;
                                n -> next = index;
                                index -> prev = n;
                                index = n -> prev;
                                index -> next = n;
                                ++list->size;
			}
			else{//Inserts a duplicate node in the tail position.
				index -> next = n;
                                n -> prev = index;
                                list -> tail = n;
                                ++list->size;
			}	
		
		}else{
			if (cmp(data, index -> data ) < 0){ //Inserts a node into a non-head/tail position.
				n -> prev = index -> prev;
				n -> next = index;
				index -> prev = n;
				index = n -> prev;
				index -> next = n;
				++list->size;
			}else{
				index -> next = n; // Inserta a node into the tail position.
			       	n -> prev = index;
				list -> tail = n;
				++list->size;
				
			}
		}
	}
        return true;
					
}

void free_list(linked_list *list, void (*free_data)(void *)){

	node *iterator = list->tail; //starts at the tail
	
	while(iterator != list->head){ //frees each node starting at the tail
                free_node(iterator, *free_data); //frees the individual node
		iterator = iterator->prev; //increments iterator
	}
	free_node(iterator, *free_data); //frees the head, since iterator now is equal to head
					 //
	free(list);//frees the linked list
}
