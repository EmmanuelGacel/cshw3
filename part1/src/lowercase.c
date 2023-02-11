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
		int size = 0;
		int i;
		char **base_pointer;
		char **copy_pointer;
		size_t count;
		for (i = 1; i < argc; i++){
			count = count + my_strlen((*argv + i)); // eq to echo, eq argv[1] "String\0", you can use mystring/length
		}
		base_pointer = copy_pointer = (char*)malloc(size*sizeof(char));
		for (i = 1; i < argc; i++){
			*copy_pointer = my_strcpy(*copy_pointer,(*argv + i));
		}
		return p;
	}
	return NULL;
/*
 * static char **copy_args_lowercase(int argc, char **argv) {
        if (argc > 1){ //only executes if arguments were supplied
                //int size = 0;
                int i;
                //char **copy_pointer;
                size_t count;

                for (i = 1; i < argc; i++){ //iterates for as many arguments there are
                        //adds the length of each argument to the total
                        count = count + my_strlen((argv[i])); // eq to echo, eq argv[1] "String\0"
                }

                char *copy_pointer = (char*)malloc(sizeof(argc)+ 1); //ensures copy is of valid size

                for (i = 1; i < argc; i++){
                        *copy_pointer = my_strcpy(*copy_pointer,(argv[i]));
                }

                my_strlower(*copy_pointer); //has a void return value

                return copy_pointer; //
        }
        return NULL;
}
 */
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
