#include "mystring.h"
#include <stddef.h>
//Taken from page 99 of the K&R textbook
size_t my_strlen(char *src){
	int n;//holds the count
	//iterates through characters in *src
	//when an array is passed into a function, location of initial element is passed
	for (n = 0; *src != '\0'; src++){ //pointers are variables, so can do src++ (src is a local variable)
		n++; 
	}
	return n;
}

//Taken from page 105 of the K&R textbook
char *my_strcpy(char *dst, char *src){

	char *pdst = &dst[0];//saves pointer to beginning of dst
	if (*src != '\0'){
		//*dst++ referes to the to the character dst pointed at before increment
		while ((*dst++ = *src++) != '\0');//copies src into dst until it equals null

	} else return NULL;
	return pdst; //returns the first element of dst (saved earlier) after copying
}

void my_strlower(char *src){
	while(*src != '\0'){//loops over each character in src
		*src = tolower(*src);//sets each character to lowercase
		src++; //increments the pointer
		}
}
