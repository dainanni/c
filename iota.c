/* HW 1 
 * Program created by Daivik Dinesh
 * SID- 913296561
 * ECS 030 Fall Quarter 2015
 * 
 * iota.c - Program to print integers from start to end pt by the desired increments */


#include <stdio.h>
#include <stdlib.h>

int main(void)
{
int start; /* Variable to store starting point */
int stop; /* Variable to store ending point */
int i; /* Variable to store increment/decrement value */
int var; /* Declaring a loop variable */

printf("Starting point: ");
scanf("%d",&start); /* Taking in starting point for computation */
 
printf("Ending point: "); 
scanf("%d",&stop); /* Taking in ending point for computation */

printf("Increment: ");
scanf("%d",&i); /* Taking in increment/decrement for computation */

if ((start<stop) && i>0) /* Checking if increment is positive */
{       
        for(var = start; var<=stop; var+=i) /* Loop to print digits */
        {       
		if ((var+i) > stop) /* To check if last element is being printed*/
                {
                        printf("%d\n",var); /* To print the last element */
                }
                else
                {
                        printf("%d ",var); /* To print the next few elements */
                }
        }
        return(0);
}
else if ((start<stop) && i<=0) /* -ve increment isn’t possible for start < stop */
{
        fprintf(stderr, "Increment must be > 0 if begin < end\n”);/* Error printed*/
        return(1);
}
else if((start>stop) && i <0) /* Checking if increment is negative */
{
        for ( var = start; var>=stop; var+=i )/* Loop to print digits*/
        {
                if ((var+i) < stop) /* To check for the last element being printed */
                {
                        printf("%d\n",var); /* To print last element */
		 }
                else
                {
                        printf("%d ", var); /* To print following elements */
                }
        }
        return(0);
}
else if ((start>stop) && i >=0) /* +ve increment isn’t possible for start > stop */
{
        fprintf(stderr,"Increment must be < 0 if begin > end\n"); /* Error printed */
        return(1);
}
else if ( start == stop ) /* For same start and stop, only the one number is checked */
{
        printf("%d\n",start); /* The one number is printed */
        return(0);
}
return 0;
}

