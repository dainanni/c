/* epsilon.c
 * Created by Daivik Dinesh
 * On 11/02/15
 * SID- 913296561
 * ECS 30 Fall Quarter 2015
 * Program to find the largest epsilon (deviation) for a number 
 */

#include<stdio.h>
#include<stdlib.h>

void main()
{

double ep1;/*Declaring ep1 for double value of epsilon*/
float ep2; /*Declaring ep2 for float value of epsilon*/

for(ep1 = 1.0; (1.0 != 1.0 + ep1); ep1 = ep1 / 2 );/* Loop to find Epsilon for double by dividing by 2 to find the largest possible value*/

for(ep2 = 1.0f; (1.0f != 1.0f + ep2); ep2 = ep2 / 2 ); /* Loop to find Epsilon for float by dividing by 2 to find the largest possible value*/

/* To print the epsilon values for float and double in one statement*/
printf("The value for epsilon is %g (floating) and %g (double).", ep2, ep1);

}
