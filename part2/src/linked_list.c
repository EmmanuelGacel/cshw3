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
	//printf("n -> data: %s \n",(char *)  n -> data);
                 //printf("head -> data: %s\n", (char *) list -> head -> data);
                 //printf("cmp data: %d\n",cmp(n->data, list -> head-> data));
                 //printf("cmp data: %d\n",cmp(list -> head-> data, n -> data));
		
	  //printf("------------------------------- \n");
                                //printf("Head -> data: %s\n", (char *) list -> head -> data);
                                //printf("Tail -> data: %s\n", (char *) list -> tail -> data);
                                //printf("Data: %s\n", (char *) data);
                                //printf("Index -> data: %s\n", (char *) index -> data);
                                //printf("cmp data: %d\n",cmp(data, index->data));
                                //printf("------------------------------- \n");
                                //printf("cmp data: %d\n",cmp(data, index->data));

			/*
                        if(cmp(data, index->data) == 0){ //case for duplicates
                                printf("323Index -> data: %s\n", (char *) index -> data);
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
                        */

				
				/*
				if (index -> next != NULL){
					printf("How did we get here\n");
					n -> prev = index -> prev;
					n -> next = index;
					//printf("Index -> data: %s\n", (char *) index -> data); 
					index = n -> prev;
					//printf("Index -> data: %s\n", (char *) index -> data);
					//printf("Made it 4\n");
					//printf("Index -> next: %p", index);
					index -> next = n;
					//printf("Made it 5\n");
					++list->size;
				}else{
					//:if (list -> head != list -> tail)
					printf("Last Tail Assignment:\n");
					//printf("Made it 7\n");
					//printf("Made it 8\n");
					printf ("cmp( data, tail) : %d \n",cmp(data, list -> tail -> data));
					printf("n -> data: %s\n", (char *) data);
					printf("Index -> data: %s\n", (char *) index -> data);
					printf("Tail -> data: %s\n", (char *) list -> tail -> data);
					list -> tail -> next = n;
					n -> prev = list -> tail;
					list -> tail = n;
					//printf("Tail -> data: %s\n", (char *) list -> tail -> data);
					//index -> next = n;
					//index = index -> next;
					//printf("Index -> data: %s\n", (char *) index -> data);
					//printf("Made it 7\n");
					++list->size;
					////n -> prev = index;
					
					//index -> next = n;
					
					////list -> tail = n;
					
						//index -> next = n;
						//n -> prev = index;
						//list -> tial - n;
				
				}

			}
			*/
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

void free_list(linked_list *list, void (*free_data)(void *)){
        while(list != NULL){
                free_node(list -> tail, *free_data);
        }
        free_data(list);
}
