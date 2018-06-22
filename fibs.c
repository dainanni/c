// Homework 4
// Created by Daivik Dinesh
// SID- 913296561
// ECS 030 Fall Quarter 2015
// fibs.c - Program to print and time the iterative AND recursive versions of the Fibonacci series

#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

int iterfib(int n) /*Function to compute Fib seq iteratively*/
{       
        int f = 0;
        int s = 1; 
        int next = 0;
        int k;
        
        for(k = 0; k < n; k++) /* Loop to compute fibonacci series */
        {       
                next = f+s;
                f = s;
                s = next;
        }

return (f); /* Returns each digit of the sequence */
 
}

int recfib(int n)/* Function to print Fib seq recursively*/
{       
        if(n == 0) /* Checking for base cases */
        {       
                return 0;
        }
        
        else if (n == 1) /* Checks the base case */
        {       
                return 1;
        }
        
        else    
        {       
                return( recfib(n-1) + recfib(n-2) ); /* Logic used for the recursive Fibonacci function */
        }
}
int main(int argc, char *argv[]) /* Parameters of argument counter and array for command line input that is to be taken */
{
        int i, j, k; /* Loop variables */
        int val; /* Variable used to store integer value of user input */

        struct timeval *gettime(void); /* Prototype of gettime function */
        double timediff(struct timeval *t1, struct timeval *t2); /* Prototype of timediff function */

        struct timeval TimeIterBegin, TimeIterEnd, TimeRecBegin, TimeRecEnd; /* Declaration of variables for gettime func */

        float TimeIter, TimeRec; /* Declaration of variables for the timediff */

        if (argc != 2) /* Checks if the number of arguments is only 2 */
        {
                fprintf(stderr, "Usage: %s number\n", argv[0]); /* Prints error message if more or less than 2 arguments found */
                return 1;
        }

        if(sscanf(argv[1], "%d", &i) != 1) /* sscanf function helps to traverse through the array input and converts the integer part to integer */
        {
                        fprintf(stderr, " %s not an integer\n", argv[1]); /* Prints error message if input is NOT an integer */
                        return 1;
        }

        if(i < 0) /* To check for negative integer */
                {
                      fprintf(stderr, "Argument must be a positive integer\n", argv[0]); /* Prints error if argument is negative */
                      return 1;
                }


        val = atoi(argv[1]); /* Converts argv[1] into an integer to store into variable val*/

        printf("Iterative: ");

        TimeIterBegin = *gettime(); /* Starting the timer for Iterative function */

        for(k = 0; k < val; k++) /* Loop to print out the iterative fibonacci function */
        {
                printf(" %d", iterfib(k));
        }

        TimeIterEnd = *gettime(); /*Ending timer for Iterative function */

        TimeIter = timediff(&TimeIterBegin, &TimeIterEnd); /* Taking difference for getting the time taken by Iterative function */

        printf("\n");
        printf("Recursive: ");

	TimeRecBegin = *gettime(); /* Starting timer for Recursive function */

        for(j = 0; j < val; j++) /* Loop to print out the recursive fibonacci function*/
        {
                printf(" %d", recfib(j));
        }

        TimeRecEnd = *gettime(); /* Ending timer for Recursive function */

        TimeRec = timediff(&TimeRecBegin, &TimeRecEnd); /* Taking difference for getting the time taken by Recursive function */

        printf("\n");
        printf("Iterative timing: %12.6f\n", TimeIter); /*Prints the time taken by Iterative Fibonacci function */
        printf("Recursive timing: %12.6f\n", TimeRec); /* Prints the time taken by Recursive Fibonacci function */

return 0;

}
