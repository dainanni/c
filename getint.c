/* getint.c
 *
 * Created by Daivik Dinesh
 * 
 * SID- 913296561
 *
 * For ECS 030 Fall Quarter
 *
 * Program to check a user’s input for an integer or an integer that contains a string */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include<limits.h>

int getint(char *inputline, int *value, char **nextchar)/* Function to read an integer*/
{

        int a = 0, b = 0; /* Variables to keep indexes in arrays*/
        int check = 0; /* counter to check for negative values or - sign*/
        char temp[1024]; /*temporary char array to keep the string part*/
        long int num; /* Integer to store converted value of array*/

        if(inputline == '\0' || value == '\0' || nextchar == ‘\0’) /*To check for BADARG values*/
        {
                return (-1);
        }

        if(*nextchar == ‘\0’) /*Checking for BADARG*/
        {
                return (-1);
        }

        while(isspace(inputline[a])) /* Checks for a blank space character*/ 
        {
                a++;
        }

	if(inputline[a] == '+' || inputline[a] == ‘-‘) /* Checks for = and - signs in input*/
        {
                if(inputline[a] == ‘-‘) /* To check for - sign*/
                {
                        check++; /* Increments counter to keep track of negative value*/
                }

                a++;

                if(!isdigit (inputline[a])) /* Checks if next char is a digit*/
                {
                        *nextchar = &inputline[0]; /* Stores the digit as part of string next char */
              		return(0); /* returns 0 for switchcase in driver function*/
        	}

}


        for( ;inputline[a]; a++) /* For loop to traverse through the input to check various cases*/
        {
                if(inputline[a] == ‘.’)/* Checks for the ‘.’ character*/
                {
                        if(isalpha(inputline[ a + 1 ])) /* Checks if char after . is an alphabet*/
                        {
                                *nextchar = &inputline[0]; /* Stores in next char again*/
                                return(0);
                        }

                        if(isdigit(inputline[a+1])) /* Similarly, checks for digit after .*/
                        {
                                *nextchar = &inputline[0];                                                      				return (0);
                        }
                 }

                if(isalpha(inputline[a])) /* Checks for alphabets in the main input*/
                {
                        *nextchar = &inputline[0];
                        return (0);
                }

                if(isdigit(inputline[a])) /* If integer found in main input, stores it in temp array*/ 
                {
                        temp[b] = inputline[a]; /* Stores value of digit (the current input) into a temporary char array ‘temp’*/
                        b++;
                }

                else
                {
                         break; /*Used to break out of current iteration of input check*/
                }

        }

	*nextchar = &inputline[a];

        num = atol(temp); /* Converts values of char array temp into a single integer and stores it in variable ‘num’*/

        if(check != 0) /* Counter to check for a value in order to convert newly stored integer value into negative*/
        {
                num = -num;
        }

        *value = num; /*Storing the integer variable ‘num’ into value*/ 

        if(num < INT_MIN) /*Checks for ‘Integer Underflow’*/ 
        {
                return(3);
        }

        if(num > INT_MAX) /*Checks for ‘Integer Overflow’*/ 
        {
                return(2);
        }

        return(1);


}
