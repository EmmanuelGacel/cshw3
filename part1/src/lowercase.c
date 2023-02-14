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
	
	if (argc > 1){
		char **copy_pointer = (char**)(malloc(argc *sizeof(char*) + 1)); //allocates sufficient memory
                
                int num_args = argc; //saves value of args      
                int length;
                while(--num_args > 0){
                        length = my_strlen(*++argv);//length of current argument
             
                        char *ptemp  = (char *)(malloc (length * sizeof(char) + 1)); //char array space

                        *++copy_pointer = (my_strcpy(ptemp, *argv)); //sets next pointer in cp
                        
                        my_strlower(*copy_pointer); //lowers array cp is currently at   
                          
                }
                return copy_pointer - (argc - 2); //accounts for file name, and brings to 0
		
	}
	return NULL;
}

static void free_copy(char **copy) {
	free(*copy); 
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
