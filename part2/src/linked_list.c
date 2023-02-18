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
		if (list -> head == NULL){
			list -> head = list -> tail = n;
                        ++list->size;
		}else if(cmp(data, list->head) < 0){
			printf("Index -> data: %s \n",(char *)  n -> data);
			printf("Index -> data: %s\n", (char *) list -> head -> data);
			printf("cmp data: %d\n",cmp(n->data, (list -> head)));
			printf("cmp static data: %d\n",cmp((void *)"aa\0", (void *) "b\0"));
			printf("cmp static data: %d\n",cmp((void *)"b", (void *) "a"));
			list -> head -> prev = n;
			n -> next = list -> head;
			list -> head = n;
			++list->size;
		}
	}else{ //node is more than head
			node* index = list->head; //creates temp pointer to head
			printf("cmp data: %d\n",cmp(data, index->data));

			//moves index to correct spot
			for( ; (cmp(data, index->data) < 0) && (index -> next) != NULL; index = (index->next)){

			printf("cmp data: %d\n",cmp(data, index->data));
			}// Account for the talei
			if (index -> next != NULL){													  //
				//printf("Index -> data: %s\n", (char *) index -> data);
				index = index -> next;
				//printf("Index -> data: %s\n", (char *) index -> data);
			}
			if(cmp(data, index->data) == 0){ //case for duplicates
				while(cmp(data, index->data) == 0 && index != NULL){
					index = (index->next);//move past all duplicates
				}
				printf("Made it 2 \n");
				if(index->next != list->tail){
					printf("Made it 3 \n");
                                	n->next = index->next; //sets n's next to node after index
                                	index->prev->next = n; //sets node before index's next to n
					++list->size;
				}
                        	else{
					list->tail->next = n; //sets node after the tail to
		                        list -> tail = n;
					++list->size;
                        	}	
		
			}else{
				if (index -> next != NULL){
					printf("How did we get here");
					n -> prev = index -> prev;
					n -> next = index;
					//printf("Index -> data: %s\n", (char *) index -> data); 
					index = n -> prev;
					//printf("Index -> data: %s\n", (char *) index -> data);
					//printf("Made it 4\n");
					//printf("Index -> next: %p", index);
					index -> next = n;
					//printf("Made it 5\n");
				}else{
					//:if (list -> head != list -> tail)
					printf("Made it 6\n");
					//printf("Made it 7\n");
					//printf("Made it 8\n");
					printf("Index -> data: %s\n", (char *) index -> data);
					printf("Tail -> data: %s\n", (char *) list -> tail -> data);
					list -> tail -> next = n;
					n -> prev = list -> tail;
					list -> tail = n;
					printf("Tail -> data: %s\n", (char *) list -> tail -> data);
					//index -> next = n;
					//index = index -> next;
					printf("Index -> data: %s\n", (char *) index -> data);
					printf("Made it 7\n");
					////n -> prev = index;
					
					//index -> next = n;
					
					////list -> tail = n;
					
						//index -> next = n;
						//n -> prev = index;
						//list -> tial - n;
				
				}

			}
			
			/*else{ //node is equal to head
				node* index = list->head; //creates temp pointer to head
                        	while(cmp(data, index->data) == 0 && (index -> next) != NULL){
                                	index = (index->next);//move past all duplicates
                        	}
                        if(index->next != list->tail){
					n->next = index->next; //sets n's next to node after index
                                	index->prev->next = n; //sets node before index's next to n
                        	}
                        else{	
                                	list->tail->next = n; //sets node after the tail to
                                	list -> tail = n;
                        	}*/
               
                
        //else{ //list does not yet exist (set head and tail to n)
                //list->head = list->tail = n;
        //}
	}
        return true;
	
}

void free_list(linked_list *list, void (*free_data)(void *)){
        while(list != NULL){
                free_node(list -> tail, *free_data);
        }
        free_data(list);
}
