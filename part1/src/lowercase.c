#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"

/**
 * Take an array of char* pointers and print each of the strings to standard
 * out. This function must use only pointer arithmetic and no array
 * subscripting. The output start with "[", ends with "]\n", and prints the
 * strings inside, each separated by a comma and space.
 * Example: [Hi, BYE, AP, COMSW 3157, FunTimes]
 */
void display_strings(char **strings) {
    printf("[");
    if (strings != NULL) {
        char **str_ptr = strings;
        if (*str_ptr != NULL) {
            printf("%s", *str_ptr++);
            while (*str_ptr != NULL) {
                printf(", %s", *str_ptr++);
            }
        }
    }
    printf("]\n");
}
//Mobaxterm
static char **copy_args_lowercase(int argc, char **argv) {
	
	if (argc > 1) {
	//initializes and malloc pointer array (**copy_pointer)
        char **copy_pointer = (char**) malloc((argc) * sizeof(char*)); //allocates room to hold null pointer too
        int num_args = argc; //saves argc value, so num_args can be freely manipulated
        
	while (--num_args > 0) { 
            	int current = num_args - 1; //since argv's first arg is function call, argv calls are one index ahead of copy_pointer call
		//initializes and mallocs copy_pointer subarry first, set first element to first argument 
	    	copy_pointer[current] = (char*) malloc((my_strlen(argv[num_args]) + 1) * sizeof(char));
		
	    	my_strcpy(copy_pointer[current], argv[num_args]); //copys argv arg into copy_pointer array 
            
	    	my_strlower(copy_pointer[current]);//lowers all the entire subarray
	}
        return copy_pointer;
    }
    return NULL; //if argc doesn't contain any arguments
}

static void free_copy(char **copy) {
	
	char **temporary = copy;//avoids messing with copy directly
				
	while(*temporary){ //iterates through all pointers on pointer array
        	free(*temporary++); //frees all of the char array
	}

	free(copy); //frees the pointer array
	return;
}


/**
 * DO NOT MODIFY main()
 */
int main(int argc, char **argv) {
    char **copy;
    copy = copy_args_lowercase(argc, argv);

    printf("Raw arguments       : ");
    display_strings(argv + 1);

    printf("Lowercase arguments : ");
    display_strings(copy);
	
    free_copy(copy);

    return EXIT_SUCCESS;
}
