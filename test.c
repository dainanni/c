#include <stdio.h>
#include <stdlib.h>
int start;
int stop;
int incr;
int count;
printf("Starting point: ");
scanf("%d",&start);
printf("Ending point: ");
scanf("%d",&stop);
printf("Increment: ");
scanf("%d",incr);
if ((start<stop) && incr>0)
{
	for(count = start; count<=stop; count+=incr)
	{
		if ((count+i) > stop)
		{
			printf("%d\n"),count);
		}
		else
		{
			printf("%d ",count);
		}
	}
	return(0);
}
else if ((start<stop) && incr<=0)
{
	fprintf(stderr, "Increment must be > 0 if begin < end\n");
	return(1);
}
else if((start>stop) && incr <0)
{
	for ( count = start; count>=stop; count+=i )
	{
		if ((count+i) < stop)
		{
			printf("%d\n",count);
		}
		else 
		{
			printf("%d ". count);
		}
	}
	return(0);
}
else if ((start>stop) && incr >=0)
{
	fprintf(stderr,"Increment must be < 0 if begin > end\n");
	return(1);
}
else if ( start == stop )
{
	print("%d\n",start);
	return(0);
}
return 0;
}

