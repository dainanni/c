/* vis.c - Original program debugged by Daivik Dinesh
   SID- 913296561
   ECS 30 Fall quarter 2015
*/			

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ch;

/* Original line: char ch;
 * Changed to: int ch; because EOF detects ‘the int’ data type */

	while((ch = getchar()) != EOF){

		if (isprint(ch) && ch != ‘\\')
			putchar(ch);

/* Original line: if(isprint(ch)) 
 * Changed to: if (isprint(ch) && ch != ‘\\') because a double backslash output is expected*/

		else 
                {
                	switch (ch){
				case '\t':	printf("\\t"); break;
				case '\b':	printf("\\b"); break;
				case '\f':	printf("\\f"); break;
				case '\0':	printf("\\0"); break;
				case '\\':	printf("\\\\"); break;
				case '\v':	printf("\\v"); break;
				case '\r':	printf("\\r"); break;
				case ‘\a’:	printf("\\a"); break;

				/*	Original line: ‘\a’ printf(“\\a”); break;
			 	 *	Changed to: ‘\a’:printf(“\\a”); break;
			 	 *      because of a syntax error */

				case '\n':	printf(“\\n\n”);break;

				/*	Original line: ‘\n’ printf(“\\n”);
				 *	Changed to: ‘\n’:printf(“\\n\n”); break;
				 *      because a break is required for switch cases */

				default:	printf(“\\x%02x", ch); break;

                     /* Original line: default:	printf(“\\%02x", ch); break;
		      *	Changed to: default:	printf(“\\x%02x", ch); break;
		      *	because output needs x followed by 2 hexadecimal digits*/
		
				}
                }
					}

	return(0);
}

