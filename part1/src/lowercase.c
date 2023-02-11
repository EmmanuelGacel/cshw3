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
		char *copy_pointer;
		size_t count;
		for (i = 1, count = 12; i < argc; i++){ //saves in count, total # of chars
			printf("word = %s\n", *argv + count);
			count = count + my_strlen(*argv + count); // *argv + i, goes to address of next string
			count += 1; //accounts for the space
		}
		
		count = count - 13; //takes out the ./lowercase and the last added space
		printf ("count = %ld\n", count);
				
		copy_pointer = (char*)malloc((count*sizeof(char) + 1)); //allocates memory for copy, based on count
		

		for (i = 1; i < argc; i++){ //makes all the chars lowercse
			my_strlower(my_strcpy(copy_pointer,(*argv + i)));

		}
		char **answer = &copy_pointer; //holds address of copy pointer
		return answer;
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
