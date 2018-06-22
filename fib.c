// fib.c
// By Daivik Dinesh
// SID- 913296561
// Completed Homework 2 Program
// fib.c - Program to print fibonacci sequence iteratively

#include<stdio.h>
#include<stdlib.h>

int fib(int n)          /* function to print Fibonacci numbers */
{
        int f = 0;
        int  s= 1;
        int  next;
        int k;


                        if( n == 0) /* prints blank line for 0 case */
                        {
                                printf("\n");
                        }

                        else if(n>0) /*Checks for positive n*/
                        {

                                  for(k = 0; k<n; k++) /* Used to print sequence*/
                                {
                                        if (k == (n-1)) /*Checks to print last char*/
                                        {
                                                printf(“%d\n”,f);/* Prints last digit*/
                                                next = f +s;
                                                f =s;
                                                s = next;

                                        }

                                        else
                                        {
                                                printf("%d “,f);/*Prints digits of seq*/
                                                next = f + s;
                                                f = s;
                                                s = next;

                                        }

                                }
                        }

			else if(n< 0) /*Returns error if n is negative */
                        {
                                return 0;
                        }




        return (1);

}

                            

                                   