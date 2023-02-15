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
        	int result = (cmp(data, list->head)) ; //compares the pointers (looks at head)
						       
		if (result < 0){ //node is less than head
                        list->head->prev = n; //sets node to previous of the head
                        list->head = n; //new head is the new node
                }else if (result > 0){ //node is more than head
			node* index = list->head; //creates temp pointer to head
		
			//moves index to correct spot
			for(index = (list->head); (cmp(data, index->data) > 0); index = (index->next));
			
			if(cmp(data, index->data) == 0){ //case for duplicates
				while(cmp(data, index->data) == 0 && index != NULL){
					index = (index->next);//move past all duplicates
				}
				if(index->next != list->tail){

                                	n->next = index->next; //sets n's next to node after index
                                	index->prev->next = n; //sets node before index's next to n
				}
                        	else{
					list->tail->next = n; //sets node after the tail to
		                        list -> tail = n;
                        	}	
			}
                }else{ //node is equal to head
			node* index = list->head; //creates temp pointer to head
                        while(cmp(data, index->data) == 0 && index != NULL){
                                index = (index->next);//move past all duplicates
                        }
                        if(index->next != list->tail){
				n->next = index->next; //sets n's next to node after index
                                index->prev->next = n; //sets node before index's next to n
                        }
                        else{
                                list->tail->next = n; //sets node after the tail to
                                list -> tail = n;
                        }
                }
                
        }else{ //list does not yet exist (set head and tail to n)
                list->head = list->tail = n;
        }
        return true;

}

void free_list(linked_list *list, void (*free_data)(void *)){
        while(list != NULL){
                free_node(list -> tail, *free_data);
        }
        free_data(list);
}
