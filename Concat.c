#include <stdlib.h>
#include <string.h>

char* concat(char *s1, char *s2) {
	
	/* concat caller must free memory after it's needed 	*/
	char *result = malloc(strlen(s1) + strlen(s2)+1); // +1 for null terminator
	
	if (result != NULL) {
		strcpy(result, s1);
		strcat(result, s2);
		return result;
	} 
	
	else {
		perror("failed to allocate memory.\n");
		return NULL;
	}
}
