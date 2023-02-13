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
		/**
		int i; //skip first arg
		size_t  count;

		for (i = 1; i < argc; i++){ //saves in count, total # of chars
			count = count + my_strlen(argv[i]); // *argv + i, goes to address of next str
			count = count - 1; //takes out the ./lowercase and the last added space

		}
		
		char **copy_pointer;
		char *copy = (char*)malloc((count*sizeof(char) + 1)); //allocates memory based on count
		
		for (i = 1; i < argc; i++){ //copies over all the args into copy_pointer
			printf("strcopy = %s\n", argv[i]);
			my_strcpy(copy,(argv[i])); //passes array of string to cp
		}


		my_strlower(copy); //sets all values in cp to lowercase

		//printf("copy = %s\n", copy_pointer[3]);
		//printf("final: %s\n ", *copy_pointer);
		copy_pointer = &copy;

		return copy_pointer;
		*/
		//MOST SUCCESSFUL VERSION
		char **copy_pointer = (char**)(malloc((argc + 1) *sizeof(char*))); //allocates sufficient memory
                 
                int length;
                while(--argc > 0){
                        length = my_strlen(*++argv);//length of current argument
                        printf("length = %d\n", length);

                        char temp[length + 1], *ptemp; //makes dst array with proper size
                        ptemp = temp; //pointer to temp                 

                        *++copy_pointer = (my_strcpy(ptemp, *argv)); //sets next pointer in cp
                        printf("Current cp = %s\n", *copy_pointer);

                        my_strlower(*copy_pointer); //lowers array cp is currently at   
                        printf("lowered cp = %s\n", *copy_pointer);

                }

                return copy_pointer;
		
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
