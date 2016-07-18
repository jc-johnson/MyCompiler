/* Cradle program -  minimum needed to get the job done*/

#include <stdio.h>
#include <string.h>

#include "Concat.c"

/* Constant declarations */
const char TAB = '\t';

typedef int bool;
#define true 1;
#define false 0;

/* Variable Declarations */
char look;  /* Lookahead character */


/* Declaring function prototypes */
void getChar();
void error(char*);
void myAbort(char*);
void expected(char*);
void match (char c);
bool isAlpha(char c);

/* Read new character fron input stream */
void getChar(){
	read(look);
}

/* Report an error */
void error(char* s) {
	// printf("%s\n", s);
	perror(s); 
}

/* Report an error and halt (return in C)  */
void myAbort(char *s) {
	perror(s);
	return;
}

/* Report what was expected */
void expected(char *s) {
	
	char *c;
	c = concat(s, " Expected");
	myAbort(c);

	
}

/* Match a specific input character */
void match (char c){
	if (look == c) {
		getChar();
	} else {
		char* s;
		s = &c; 
		expected(s);
	}
}

/* Recognize an alpha character */
bool isAlpha(char c){
	
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))  {
		return true;
	}
	return false;
}

/* Recognize a decimal digit */
bool isDigit(char c) {
	
	if (c >= 48 && c <= 57) {
		return true;
	}
	return false;
}

/* Get an identifier */

/* Get a number */

/* Output a string with tab */

/* Output a string with tab and CRLF */

/* Initialize */



/* Main Program */ 
int main(int argc, char *argv[]) {
	
	/* tab test */
	printf("%c\n", TAB);
	
	/* error test */
	char *p;
	p = "Error Test";
	error(p);
	
	/* abort test */
	p = "Abort Test";
	myAbort(p);
	
	/* concat test */
	p = concat("sam", " I am");
	printf("%s\n", p);
	
	/* expected test */
	expected("Not to fail");
	
	/* match test */
	look = 'b';
	match('b');
	match('c');
	
	/* isAlpha test */
	printf("isAlpha tests\n");
	bool b;
	b = isAlpha('c');
	printf("%i\n", b);
	b = isAlpha('Z');
	printf("%i\n", b);
	b = isAlpha('!');
	printf("%i\n", b);
	b = isAlpha('1');
	printf("%i\n", b);
	
	/* isDigit test */
	printf("isDigit tests\n");
	b = isDigit('1');
	printf("%i\n", b);
	b = isDigit('0');
	printf("%i\n", b);
	b = isDigit('A');
	printf("%i\n", b);
	b = isDigit('$');
	printf("%i\n", b);
	
	
}

