/*
 * BUGGY -- a program to reverse the order of the lines in a file
 * (print last line first, then next-to-last, then ..., finally the first)
 *
 * LIMITS:
 * -- assumes no more than 1023 lines of at most 1023 characters
 *
 * Input: lines to be reversed
 * Output: input lines, printed in reverse order
 * Error: too many lines gives an error message
 * 	  running out of memory gives an error message
 *
 * Matt Bishop, November 9, 2015
 * Version 1 -- has a bug! It crashes
 */

// Debugging program
// Debugged by Daivik Dinesh
// SID- 913296561
// ECS 030 Fall Quarter 2015
// Program to reverse order of lines in a file
// Error (Bug) is commented in the program (free function)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * useful macros
 */
#define	MAXLINES	1023	/* maximum number of lines allowed */
#define	MAXLENGTH	1023	/* maximum length of a line */

/*
 * useful globals (could be declared local ...)
 */
char *line[MAXLINES];		/* array of pointers to lines */

/*
 * the main routine
 */
int main(void)
{
	char buf[MAXLENGTH];	/* buffer for input line */
	char *p, *b;		/* used to copy input line to allocated storage */
	int lineno = 0;		/* current line number/line[] index */
	int i;			/* counter in a for loop */

	/*
	 * loop through the file, copying 1 line at a time
	 * to allocated storage
	 */
	while(fgets(buf, MAXLENGTH, stdin) != NULL){
		/* check: do we have too many lines? */
		if (lineno >= MAXLINES){
			fprintf(stderr, "Over %d lines of input\n", lineno + 1);
			return(1);
		}
		/* we're good -- allocate the space, complain if needed */
		if ((p = malloc((strlen(buf) + 1) * sizeof(char))) == NULL){
			fprintf(stderr, "Line %d: no memory!\n", lineno + 1);
			return(1);
		}
		/* save the space in the array of lines */
		line[lineno++] = p;
		/* now copy the input line to the stored space */
		b = buf;
		while(*p++ = *b++)
			;
			
	}

	/*
	 * now print the lines in reverse order
	 */
	for(i = lineno - 1; i >= 0; i--){
		/* print it character by character */
		for(p = line[i]; *p; p++)
			putchar(*p);
		/* done with it! release the space allocated for this line */
		(void) free(line[i]);/* Used to deallocate the memory address that was 						used to store the input line taken initially */
	}

	/*
	 * all done!
	 */
	return(0);
}

