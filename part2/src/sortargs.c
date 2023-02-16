#include <stdio.h>
#include <string.h>
#include "linked_list.h"
int str_cmp(const void *str1, const void *str2){
	return strcmp( ( const char *)str1,  (const char *)str2);
}
void print_function (void* data){
	printf("%s", (char*) data);
}
int main(int argc, char **argv) {
	linked_list *list = create_linked_list();
	int i;
	for (i = 1; i < argc; i++){
		insert_in_order(list, argv[i], str_cmp); 
	}
	print_list(list, print_function);
	return EXIT_SUCCESS;
}
