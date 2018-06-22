/* Commented and Solved by Daivik Dinesh
 * SID- 913296561
 * ECS 030 Fall Quarter 2015
 * Obfuscated Program to print out “Hello World!”
 */


int i;/* Declaring an integer variable i*/

	main()/* Calling main function to run the code*/
	{

		for(; i[  "]<i;++i){--i;}"  ]; 	/* for loop that contains obfuscated code, 						   where the expression “]<i;++i){—i;}” 						   means that the loop iterates for 14 							   times, (because the size of string 							   “Hello, world!\n” is 14 and after 							   evaluating the inner expression which 						   is not standard ANSI C, we see the size 						   14)*/

		read('-'  -  '-', i++  +  "hell\o, world!\n",'/'  /  ‘/‘));/* Over here, 									      ‘-‘  -  ‘-‘ 									      is equal to 									      0, and 										      ‘/‘  /  ‘/‘ 									      is equal to 									      1. The i++ + 									      “hell\o, 										      world!\n” 									      helps us 										      print the 									      next 										      character of 									      the hello 									      world! 										      string, by 									      using the 									      loop */

	}



	read(j,i,p)/* Definition of function read, to take in 2 integers and char to use 		      the write function*/  
	{
		write( j/ p+p ,i-- - j, i/i);/* writes the values-> write(0, i-—, 1), 						        because j is always 0 in read, and i/i is 					        1 in this case */

	}

/* De-obfuscated Program:-
 * 
 * int i;

 *main()
 *{
 *
 *char ch[14]= “hello world!\n”;/* Declaration of ‘ch’ as a char array that stores 			                   “hello world!”*/
 *
 *for(;i < 14; i++);/*Because,the read function uses write() which evaluates to i++ */		    */ 
 * write(0, ch +i, 1);/* Evaluated read function expression that was obfuscated*/
 *
 *
 *}

 *read(int j,char *i, int p)/* Function definition*/
 *{

 * write(0, i, 1);/* Used to increase i’s value by 1*/
 *
 *}
 */