#include "mystring.h"
#include <stddef.h>
//Taken from page 99 of the K&R textbook
size_t my_strlen(char *src){
	int n;
	for (n = 0; *src != NULL; s++){
		n++;
	}
	return n;
}

//Taken from page 105 of the K&R textbook
char *my_strcpy(char *dst, char *src){
	int *pdst = &dst[i];
	if (*src != null){
		while ((*dst++ = *src++) != NULL);
		return pdst;

	} else return NULL;
}

void my_strlower(char *src){
	while(*src != NULL){
		*src = tolower(*src);
		src++;
		}
}
