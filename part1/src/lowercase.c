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
		int i; //skip first arg
		size_t  count;

		for (i = 1; i < argc; i++){ //saves in count, total # of chars
			printf("word = %s\n", argv[i]);
			count = count + my_strlen(argv[i]); // *argv + i, goes to address of next string
			count += 1; //accounts for the space
		}
		
		count = count - 1; //takes out the ./lowercase and the last added space
		printf ("count = %ld\n", count);
				
		char *copy_pointer = (char*)malloc((count*sizeof(char) + 1)); //allocates memory based on count
		
		
		for (i = 1; i < argc; i++){ //copies over all the args into copy_pointer
			my_strcpy(copy_pointer,(argv[i]));
		}

		my_strlower(copy_pointer); //sets all values in cp to lowercase

		//FIGURE OUT RETURN TYPE
		return char** answer = &copy_pointer;
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
